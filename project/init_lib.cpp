#include "../project/init_lib.h"

#include <allegro.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "../graphic/my_graphics.h"
#include "../xml/rapidxml.hpp"
#include "project_library.h"

// namespaces used to read from xml files
using namespace rapidxml;
using namespace std;

extern int tonality[TON_INDEX];
extern int keyboard[KEY_INDEX];
extern InitType parameters;


boolean_T function_cycle(RtMidiOut *midiout)
{
boolean_T enter_in_menu = false;	// used to exit the thread and enter into menu
pthread_t t_hands_dx, t_hands_sx, t_drums;
TaskPar t_hands_dx_par, t_hands_sx_par, t_drums_par;

	parameters.exit = false;		// used to exit the program

	// GET THE SESSION PARAMETERS
	parameters = inizialize(midiout,tonality,keyboard);

	if (parameters.exit) return true;
	else
	{
	int main_tonic;	//in  midi scale
	int pattern_major_scale[8] = {2,2,1,2,2,2,1};
	int i;

		// INITIALIZE THE PROGRAM WINDOW
		init_graphic_program_window(parameters);

		// INITIALIZE MIDI INSTRUMENTS
		midi_set_instr(midiout,BASS_CHANNEL, parameters.bassInstrument);
		midi_set_instr(midiout,DX_HAND_CHANNEL, parameters.dxInstrument);
		midi_set_instr(midiout,SX_HAND_CHANNEL,parameters.sxInstrument);
		midi_set_instr(midiout,DRUMS_CHANNEL, parameters.drumInstrument);

		// INITIALIZE THE TONALITY
		main_tonic = LOWEST_A + parameters.tonality;
		tonality[0] = main_tonic;
		for (i = 1; i < TON_INDEX; i++) {
			tonality[i] = tonality[i-1] + pattern_major_scale[(i-1)%7];
		}

		// INITIALIZE THE KEYBOARD
		change_keyboard(1,keyboard,tonality,parameters);

		// SET THREADS PARAMETERS
		set_taskpar(&t_hands_sx_par, midiout, &enter_in_menu, 15, 15, 21);
		set_taskpar(&t_hands_dx_par, midiout, &enter_in_menu, 15, 15, 30);
		set_taskpar(&t_drums_par, midiout,&enter_in_menu, parameters.bpmDrums, parameters.bpmDrums, 21);

		// CREATE THREADS
		pthread_create(&t_hands_sx, NULL, thread_hands_sx, &t_hands_sx_par);
		pthread_create(&t_hands_dx, NULL, thread_hands_dx, &t_hands_dx_par);
		pthread_create(&t_drums, NULL, thread_drums, &t_drums_par);

		// WAIT AND CANCEL THREADS
		pthread_join(t_hands_dx,NULL);
		pthread_join(t_hands_sx,NULL);
		pthread_join(t_drums,NULL);

		return false;
	}
}


InitType inizialize(RtMidiOut *midiout,int * tonality, int* keyboard)
{
InitType par;

boolean_T confirm_parameters = false; 	//used to exit from the thread
pthread_t t_allegro_init;				// name of init thread
TaskPar t_allegro_init_par;

	//INITIALIZATION WITH ALLEGRO THREAD
	set_taskpar(&t_allegro_init_par,&par,&confirm_parameters, 15, 15, 21);
	pthread_create(&t_allegro_init, NULL, thread_allegro_init, &t_allegro_init_par);

	pthread_join(t_allegro_init,NULL);

	if (par.exit) return par;
	if (par.read_from_xml) par = get_init_par_xml();

	return par;
}

InitType get_init_par_xml(void){
InitType temp;

xml_document<> doc;
xml_node<> * element;

	// OPEN XML FILE "init.xml"
	ifstream theFile ("init.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	element = doc.first_node("Leapchrod");

	temp.bassInstrument = (InstrumentType)atoi(element->first_node("bassInstrument")->value());
	temp.drumInstrument = (InstrumentType)atoi(element->first_node("drumInstrument")->value());
	temp.dxInstrument = (InstrumentType)atoi(element->first_node("dxInstrument")->value());
	temp.sxInstrument = (InstrumentType)atoi(element->first_node("sxInstrument")->value());
	temp.bpmDrums = (int) atoi(element->first_node("bpmDrums")->value());
	temp.modality = (Modality)atoi(element->first_node("modality")->value());
	temp.tonality = (Tonality)atoi(element->first_node("tonality")->value());

	temp._1_ = (int)atoi(element->first_node("_1_")->value());
	temp._2_ = (int)atoi(element->first_node("_2_")->value());
	temp._3_ = (int)atoi(element->first_node("_3_")->value());
	temp._4_ = (int)atoi(element->first_node("_4_")->value());

	temp.exit = false;

	return temp;
}

void change_keyboard(int grade,int* key,int* ton,InitType par)
{
int* pattern_modality;
int i;

	switch (par.modality) {
			case PIANO:
			{
				int temp[KEY_INDEX]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
				pattern_modality=temp;
				break;
			}
			case ARPEGGIO:
			{
				int temp[KEY_INDEX]={0,2,4,6,7,9,11,13,14,16,18,20,21,23,25};
				pattern_modality=temp;
				break;
			}
			case PENTATONIC:
			{
				int temp[KEY_INDEX]={0,1,2,4,5,7,8,9,11,12,14,15,16,18,19};
				pattern_modality=temp;
				break;
			}
			default:
			{
				return;
			}
		}

		for (i = 0; i < KEY_INDEX; ++i) {
			key[i] = ton[grade -1 + pattern_modality[i]];
		}
}

void get_name_note(int note, char* name)
{
int relative_note;

	relative_note = note % 12;

	switch (relative_note) {
		case 0: {	strcpy(name,"Do\0"); break;	}
		case 1: {	strcpy(name,"Reb\0"); break;	}
		case 2:	{	strcpy(name,"Re\0"); break;	}
		case 3:	{	strcpy(name,"Mib\0"); break;	}
		case 4:	{	strcpy(name,"Mi\0"); break;	}
		case 5:	{	strcpy(name,"Fa\0"); break;	}
		case 6:	{	strcpy(name,"Solb\0"); break;	}
		case 7:	{	strcpy(name,"Sol\0"); break;	}
		case 8:	{	strcpy(name,"Lab\0"); break;	}
		case 9:	{	strcpy(name,"La\0"); break;	}
		case 10:	{	strcpy(name,"Sib\0"); break;	}
		case 11:	{	strcpy(name,"Si\0"); break;	}
		default:	break;
	}
}

void initialize_names_chord(NamesChordType* names,Tonality tonic)
{
int tonic_midi_code=57+tonic;
int pattern_major_scale[7] = {0, 2, 4, 5, 7, 9, 11};
int i;

	for (i = 0; i < 7; ++i)
	{
		char temp[6];
		get_name_note(tonic_midi_code+pattern_major_scale[i], temp);

		// MINOR CHORDS AT GRADE 2, 3, 6
		if ((i==1) || (i==2) || (i==5)) strcat(temp,"m\0");

		// DIM CHORD AD GRADE 7
		if (i==6) strcat(temp," dim\0");

		switch (i) {
			case 0: {strcpy(names->_1_,temp); break;}
			case 1: {strcpy(names->_2_,temp); break;}
			case 2: {strcpy(names->_3_,temp); break;}
			case 3: {strcpy(names->_4_,temp); break;}
			case 4: {strcpy(names->_5_,temp); break;}
			case 5: {strcpy(names->_6_,temp); break;}
			case 6: {strcpy(names->_7_,temp); break;}
			default:
				break;
		}
	}
}
