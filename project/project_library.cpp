#include "../project/project_library.h"

#include <stdio.h>

#include "../midi/midi_lib.h"
#include "../graphic/my_graphics.h"
#include "../leap/functions_leapmotion.h"
#include "../project/init_lib.h"


using namespace Leap;
Controller c;	// controller used to communicate with the Leap Motions (global)

extern int tonality[TON_INDEX];
extern int keyboard[KEY_INDEX];
extern InitType parameters;

pthread_mutex_t mux_update_keyboard = PTHREAD_MUTEX_INITIALIZER;	// mutex for keyboard changes

boolean_T generate_notes_of_chord(ExternalOutputs_SX_Hand_SymType *chord, chord_to_midi_Type *msg)
{
int relative_mode = 0;

	if (!chord->changeO) return false; //no change

	relative_mode = (int) chord->chord_relO;

	// check that exists a chord that must be played
	if (relative_mode == 0) {
		msg->control = 0;
		return true;
	}
	else {

		pthread_mutex_lock(&mux_update_keyboard);
		change_keyboard(relative_mode,keyboard,tonality,parameters);
		pthread_mutex_unlock(&mux_update_keyboard);

		msg->control = 1;
		msg->id=(int) chord->id;
		msg->volume = (int) VOL_CHORD;

		// generate chord's notes
		msg->note[0] = tonality[relative_mode +parameters._1_ -2];			// tonica
		msg->note[1] = tonality[(relative_mode +parameters._2_ -2)%7];		// terza
		msg->note[2] = tonality[(relative_mode +parameters._3_ -2)%7];		// quinta
		msg->note[3] = tonality[(relative_mode + parameters._4_ -2)];

		return true;
	}
}

boolean_T generate_notes_of_melody(ExtY_DX_Hand_Fingers_Sym *finger_out, melody_to_midi_Type *msg)
{
	if (!finger_out->change_O) return false; // no change

	msg->id = finger_out->id;
	if (finger_out->fingers_Output < 0)
	{
		msg->nota = 0;
	}
	else
	{
		pthread_mutex_lock(&mux_update_keyboard);
		msg->nota = (int) keyboard[(finger_out->fingers_Output)%KEY_INDEX];
		pthread_mutex_unlock(&mux_update_keyboard);

		msg->volume = VOL_MELODY;
	}

	return true;


}

boolean_T generate_msg_for_SX_statemachine(ControllerSxMsgType *leap_msg,
		ExternalInputs_SX_Hand0_SymType *input_sm, int* id_buffer)
{

	// control that the frame read from the leap motion is new
	if (leap_msg->id_frame == *id_buffer) return false;

	try
	{
		*id_buffer = leap_msg->id_frame;

		input_sm->v_x_polso = (SM_INPUT_TYPE) leap_msg->velocity.x;
		input_sm->v_y_polso = (SM_INPUT_TYPE) leap_msg->velocity.y;
		input_sm->v_z_polso = (SM_INPUT_TYPE) leap_msg->velocity.z;
		input_sm->is_sx_hand = (boolean_T) leap_msg->is_sx_hand;
		input_sm->up_polso = (boolean_T) leap_msg->palm_normal;

		return true;
	}
	catch(...)
	{
		return false;
	}
}

boolean_T generate_msg_for_DX_statemachine(ControllerDxMsgType *leap_msg,
		ExtU_DX_Hand_Fingers_Sym *input_sm,int *id_buffer)
{

	// control that the frame read from the leap motion is new
	if (leap_msg->id_frame == *id_buffer) return false;

	try
	{
		*id_buffer = leap_msg->id_frame;

		input_sm->is_dx_hand = (boolean_T) leap_msg->hand;
		input_sm->thumb_angle = (SM_INPUT_TYPE) leap_msg->thumb;
		input_sm->index_angle = (SM_INPUT_TYPE) leap_msg->index;
		input_sm->middle_angle = (SM_INPUT_TYPE) leap_msg->middle;
		input_sm->ring_angle = (SM_INPUT_TYPE) leap_msg->ring;
		input_sm->pinky_angle = (SM_INPUT_TYPE) leap_msg->pinky;
		input_sm->hand_velocity = (SM_INPUT_TYPE) leap_msg->hand_speed;

		return true;
	}
	catch(...)
	{
		return false;
	}

}


void initialize_msg_sx_sm(ExternalInputs_SX_Hand0_SymType *input_sm)
{
	input_sm->v_limit = (SM_INPUT_TYPE) V_CHANGE_CHORD;

}

void initialize_msg_dx_sm(ExtU_DX_Hand_Fingers_Sym *input_sm)
{
	input_sm->limit_fingers= (SM_INPUT_TYPE) FINGERS_DEEP;
	input_sm->limit_thumb = (SM_INPUT_TYPE) THUMB_DEEP;
	input_sm->limit_hand_velocity = (SM_INPUT_TYPE) V_UP_DX;

}


void updating_midi_chord(RtMidiOut* midiout,int channel_chord, int channel_bass,chord_to_midi_Type* nchord,chord_to_midi_Type* ochord)
{
	if (nchord->control > 0)
	{
		note_on(midiout, channel_bass, nchord->note[0] - 36,120);
		chord_on(midiout, channel_chord, nchord);
		note_off(midiout, channel_bass, ochord->note[0] -36);
		chord_off(midiout, channel_chord, ochord);
		(*ochord)=(*nchord);
	}
	else
	{
		// commenting this lines, avoid to swich-off the chord when the
		// hand isn't releved
		 chord_off(midiout, channel_chord, ochord);
		 note_off(midiout, channel_bass, ochord->note[0] -36);
	}

}

void updating_midi_melody(RtMidiOut* midiout,int channel,melody_to_midi_Type* nmelody,melody_to_midi_Type* omelody)
{

	if (nmelody->nota != omelody->nota)
	{
		if (nmelody->nota == 0) note_off(midiout,channel,omelody->nota);
		else
		{
			note_on(midiout,channel,nmelody->nota,nmelody->volume);
		}
	}

	(*omelody) = (*nmelody);
}

int chord_on(RtMidiOut* midiout, int channel, chord_to_midi_Type* chord)
{
int volume = chord->volume;
	note_on(midiout, channel, chord->note[0], volume);
	note_on(midiout, channel, chord->note[1], volume);
	note_on(midiout, channel, chord->note[2], volume);
	note_on(midiout, channel, chord->note[3], volume);
	return 1;
}

int chord_off(RtMidiOut* midiout, int channel, chord_to_midi_Type* chord)
{
	note_off(midiout, channel, chord->note[0]);
	note_off(midiout, channel, chord->note[1]);
	note_off(midiout, channel, chord->note[2]);
	note_off(midiout, channel, chord->note[3]);
	return 1;
}



void *thread_hands_dx(void *arg)
{
TaskPar *tp;
RtMidiOut *midiout;
boolean_T *exit;
DxStateMachineVariablesType dx_sm;
melody_to_midi_Type melody_to_midi, melody_old;
ControllerDxMsgType msg_dx_controller;
int buffer_id_melody = (-1);	// used to control if a new frame is read from the leap
int previous_note=(-1);			// graphic management

	melody_to_midi.nota = 0;
	melody_old.nota = 0;

	dx_sm.state->ModelData.dwork = &(dx_sm.obs_states);
	DX_Hand_Fingers_initialize(dx_sm.state, &(dx_sm.input),&(dx_sm.output));

	initialize_msg_dx_sm(&(dx_sm.input));

	/* Set the period */
	tp = (TaskPar *) arg;
	midiout = (RtMidiOut *) (tp->arg);
	exit = (boolean_T *) (tp->exit);

	set_period(tp);

	/*
	 *
	 *	CYCLIC JOB
	 *
	 */

	while(!(*exit)) {
		/*
		 *
		 * RIGHT HAND
		 *
		 */

		// read from controller
		msg_dx_controller = hand_dx_read_controller(&c);

		// have to enter into the menu?
		if (!msg_dx_controller.init)
		{
			// if exist a new frame
			if (generate_msg_for_DX_statemachine(&msg_dx_controller,&(dx_sm.input),&buffer_id_melody))
			{
				// step of state machine
				DX_Hand_Fingers_step(dx_sm.state, &(dx_sm.input), &(dx_sm.output));

				// if new message, send to MIDI (or print on the screen)
				if (generate_notes_of_melody(&(dx_sm.output),&melody_to_midi))
				{
					updating_midi_melody(midiout,DX_HAND_CHANNEL,&melody_to_midi,&melody_old);
					update_dx_graphic(dx_sm.output.octave,dx_sm.output.fingers_Output,&previous_note);
					postpone_deadline(tp,MILLISEC_FILTER_DX);
				}
			}
		}
		else
		{
			(*exit) = true;
		}


		/*
		 *
		 * TASK SERVICES
		 *
		 */

		if (deadline_miss(tp))
		{
			printf("hand_dx %d\n",tp->dmiss);
		}
		wait_for_period(tp);
	}

	/*
	 *
	 * EXIT ACTIONS
	 *
	 */

	if (melody_old.nota != 0) note_off(midiout,DX_HAND_CHANNEL,melody_old.nota);

}

void *thread_hands_sx(void *arg)
{
TaskPar *tp;

RtMidiOut *midiout;
boolean_T *exit;

// state machines variables

SxStateMachineVariablesType sx_sm;

// used to create the message for MIDI sintetizer

chord_to_midi_Type chord_to_midi, chord_old;

// to store frames from Leap Motion

ControllerSxMsgType msg_sx_controller;

// to manage the recognition of new frames

int buffer_id_chord = (-1);

/*
 *
 * 	INITIALIZATION PART
 *
 */

	chord_to_midi.note[0] = 0;
	chord_to_midi.note[1] = 0;
	chord_to_midi.note[2] = 0;
	chord_to_midi.note[3] = 0;

	chord_old.note[0] = 0;
	chord_old.note[1] = 0;
	chord_old.note[2] = 0;
	chord_old.note[3] = 0;

	/* Initialize models */
	sx_sm.state->ModelData.dwork = &(sx_sm.obs_states);
	SX_Hand0_initialize(sx_sm.state, &(sx_sm.input), &(sx_sm.output));


	initialize_msg_sx_sm(&(sx_sm.input));

	/* Set the period */
	tp = (TaskPar *) arg;
	midiout = (RtMidiOut *) (tp->arg);
	exit = (boolean_T *) (tp->exit);
	set_period(tp);

	/* Initialize Graphic Part*/
	write_notes_on_keyboard(keyboard);
/*
 *
 *	CYCLIC JOB
 *
 */

	while(!(*exit)) {
		/*
		 *
		 * LEFT HAND
		 *
		 */

		// read from controller
		msg_sx_controller = hand_sx_read_controller(&c);

		// if exist a new frame
		if (generate_msg_for_SX_statemachine(&msg_sx_controller,&(sx_sm.input),&buffer_id_chord))
		{
			// step of state machine
			SX_Hand0_step(sx_sm.state, &(sx_sm.input), &(sx_sm.output));

			// if new message, send to MIDI (or print on the screen)
			if (generate_notes_of_chord(&(sx_sm.output), &chord_to_midi))
			{
				updating_midi_chord(midiout, SX_HAND_CHANNEL,BASS_CHANNEL,&chord_to_midi,&chord_old);
				update_sx_graphic(sx_sm.output.chord_relO,keyboard);
				postpone_deadline(tp,MILLISEC_FILTER_SX);
			}

		}

		/*
		 *
		 * TASK SERVICES
		 *
		 */

		if (deadline_miss(tp))
		{
			printf("hand_sx %d\n",tp->dmiss);
		}
		wait_for_period(tp);
	}

	/*
	 *
	 * EXIT ACTIONS
	 *
	 */
	chord_off(midiout,SX_HAND_CHANNEL,&chord_old);
	note_off(midiout,BASS_CHANNEL, chord_old.note[0]);
}

void* thread_drums(void* arg)
{
TaskPar *tp;
RtMidiOut *midiout;
boolean_T *exit;

	tp = (TaskPar *) arg;
	midiout = (RtMidiOut *) (tp->arg);
	exit = (boolean_T *) (tp-> exit);
	set_period(tp);

	while(!(*exit))
	{
		note_off(midiout,DRUMS_CHANNEL,60);
		note_on(midiout,DRUMS_CHANNEL,60,VOL_DRUM);
		if (deadline_miss(tp)) {
			printf("drums %d\n",tp->dmiss);
		}
		wait_for_period(tp);
	}

	// exit actions
	note_off(midiout,DRUMS_CHANNEL,60);
}
