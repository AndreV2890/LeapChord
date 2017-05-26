/*
 * init_lib.h
 *
 *  Created on: Dec 9, 2015
 *      Author: parallels
 */

#ifndef INIT_LIB_H_
#define INIT_LIB_H_
#include "../midi/midi_lib.h"
#include "../midi/RtMidi.h"
#include "project_library.h"


typedef enum _Modality {PIANO,ARPEGGIO,PENTATONIC} Modality;
typedef enum _Tonality {A,Bb,B,Cb,C,Db,D,Eb,E,F,Gb,G,Ab} Tonality;

typedef struct {
	InstrumentType bassInstrument;
	InstrumentType sxInstrument;
	InstrumentType dxInstrument;
	InstrumentType drumInstrument;
	int bpmDrums;
	Tonality tonality;
	Modality modality;
	boolean_T exit;
	boolean_T read_from_xml;
	int _1_;
	int _2_;
	int _3_;
	int _4_;
} InitType;

boolean_T function_cycle(RtMidiOut *);

InitType inizialize(RtMidiOut *,int*,int*);

InitType get_init_par_xml(void);

/*
 * update keyboard array depending on current chord and choosen modality.
 * The first time is used in the init part.
 */
void change_keyboard(int,int*,int*,InitType);

void initialize_names_chord(NamesChordType*,Tonality);

void get_name_note(int, char*);


#endif /* INIT_LIB_H_ */
