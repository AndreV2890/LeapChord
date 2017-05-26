#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#include "midi/midi_lib.h"
#include "midi/RtMidi.h"
#include "project/init_lib.h"
#include "project/project_library.h"
#include "threads_managing/my_thread_lib.h"

int tonality[TON_INDEX];	// first 4 octave of the major tonality of the chosen note
int keyboard[KEY_INDEX];	// notes that could be played by the left hand

InitType parameters;			// configuration parameters of the session


int main(int argc, char** argv)
{
RtMidiOut *midiout = new RtMidiOut();	// new link with the system midi port
boolean_T exit_program = false;	// could be setted true to exit

	// MIDI INIT
	midi_init(midiout,MIDI_PORT);

	// ALLEGRO INIT
	allegro_init();
	install_keyboard();
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0); // new window


	// PROGRAM: AT EACH EXECUTION CHANGES THE PARAMETERS

	while (!exit_program)
	{
		exit_program = function_cycle(midiout);
	}

	delete midiout; 	// clear the link connection


	return 0;
}
