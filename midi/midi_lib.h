
/*
 * MIDI LIBRARY [midi_lib.h]
 *
 * written by Antonio Di Guardo and Andrea Vincentini
 * for the project "Leap Chord" of Scuola Superiore
 * Sant'Anna (2015)
 *
 * informations at diguardoa@gmail.com
 */

#ifndef SRC_MIDI_LIB_H_
#define SRC_MIDI_LIB_H_

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <vector>

#include "../midi/RtMidi.h"
#include "../project/project_library.h"

typedef std::vector<unsigned char> vettore;

typedef enum _Instrument {
/*  0   */	Null,
/*	1	*/	Acoustic_Grand_Piano,
/*	2	*/	Bright_Acoustic_Piano,
/*	3	*/	Electric_Grand_Piano,
/*	4	*/	Honky_tonk_Piano,
/*	5	*/	Rhodes_Piano,
/*	6	*/	Chorused_Piano,
/*	7	*/	Harpsichord,
/*	8	*/	Clavinet,
/*	9	*/	Celesta,
/*	10	*/Glockenspiel,
/*	11	*/Music_Box,
/*	12	*/Vibraphone,
/*	13	*/Marimba,
/*	14	*/Xylophone,
/*	15	*/Tubular_Bells,
/*	16	*/Dulcimer,
/*	17	*/Hammond_Organ,
/*	18	*/Percussive_Organ,
/*	19	*/Rock_Organ,
/*	20	*/Church_Organ,
/*	21	*/Reed_Organ,
/*	22	*/Accordion,
/*	23	*/Harmonica,
/*	24	*/Tango_Accordion,
/*	25	*/Acoustic_Nylon_Guitar,
/*	26	*/Acoustic_Steel_Guitar,
/*	27	*/Electric_Jazz_Guitar,
/*	28	*/Electric_Clean_Guitar,
/*	29	*/Electric_Muted_Guitar,
/*	30	*/Overdriven_Guitar,
/*	31	*/Distortion_Guitar,
/*	32	*/Guitar_Harmonics,
/*	33	*/Acoustic_Bass,
/*	34	*/Fingered_Electric_Bass,
/*	35	*/Plucked_Electric_Bass,
/*	36	*/Fretless_Bass,
/*	37	*/Slap_Bass_1,
/*	38	*/Slap_Bass_2,
/*	39	*/Synth_Bass_1,
/*	40	*/Synth_Bass_2,
/*	41	*/Violin,
/*	42	*/Viola,
/*	43	*/Cello,
/*	44	*/Contrabass,
/*	45	*/Tremolo_Strings,
/*	46	*/Pizzicato_Strings,
/*	47	*/Orchestral_Harp,
/*	48	*/Timpani,
/*	49	*/String_Ensemble_1,
/*	50	*/String_Ensemble_2,
/*	51	*/Synth_Strings_1,
/*	52	*/Synth_Strings_2,
/*	53	*/Choir_Aah,
/*	54	*/Choir_Ooh,
/*	55	*/Synth_Voice,
/*	56	*/Orchestral_Hit,
/*	57	*/Trumpet,
/*	58	*/Trombone,
/*	59	*/Tuba,
/*	60	*/Muted_Trumpet,
/*	61	*/French_Horn,
/*	62	*/Brass_Section,
/*	63	*/Synth_Brass_1,
/*	64	*/Synth_Brass_2,
/*	65	*/Soprano_Sax,
/*	66	*/Alto_Sax,
/*	67	*/Tenor_Sax,
/*	68	*/Baritone_Sax,
/*	69	*/Oboe,
/*	70	*/English_Horn,
/*	71	*/Bassoon,
/*	72	*/Clarinet,
/*	73	*/Piccolo,
/*	74	*/Flute,
/*	75	*/Recorder,
/*	76	*/Pan_Flute,
/*	77	*/Bottle_Blow,
/*	78	*/Shakuhachi,
/*	79	*/Whistle,
/*	80	*/Ocarina,
/*	81	*/Square_Wave_Lead,
/*	82	*/Sawtooth_Wave_Lead,
/*	83	*/Calliope_Lead,
/*	84	*/Chiff_Lead,
/*	85	*/Charang_Lead,
/*	86	*/Voice_Lead,
/*	87	*/Fifths_Lead,
/*	88	*/Bass_Lead,
/*	89	*/New_Age_Pad,
/*	90	*/Warm_Pad,
/*	91	*/Polysynth_Pad,
/*	92	*/Choir_Pad,
/*	93	*/Bowed_Pad,
/*	94	*/Metallic_Pad,
/*	95	*/Halo_Pad,
/*	96	*/Sweep_Pad,
/*	97	*/Rain_Effect,
/*	98	*/Soundtrack_Effect,
/*	99	*/Crystal_Effect,
/*	100	*/Atmosphere_Effect,
/*	101	*/Brightness_Effect,
/*	102	*/Goblins_Effect,
/*	103	*/Echoes_Effect,
/*	104	*/SciFi_Effect,
/*	105	*/Sitar,
/*	106	*/Banjo,
/*	107	*/Shamisen,
/*	108	*/Koto,
/*	109	*/Kalimba,
/*	110	*/Bagpipe,
/*	111	*/Fiddle,
/*	112	*/Shanai,
/*	113	*/Tinkle_Bell,
/*	114	*/Agogo,
/*	115	*/Steel_Drums,
/*	116	*/Woodblock,
/*	117	*/Taiko_Drum,
/*	118	*/Melodic_Tom,
/*	119	*/Synth_Drum,
/*	120	*/Reverse_Cymbal,
} InstrumentType;



int midi_init(RtMidiOut* midiout, int midi_port);

int midi_set_instr(RtMidiOut* midiout, int channel, InstrumentType instrument);
/* Change the instrument
 * 0	Acustic Grand Piano
 * 1	Bright Acoustic Piano
 * ...and so on!
 * see http://www.ccarh.org/courses/253/handout/gminstruments/
 * NB= the last for Bytes are the number of the channel
 */

int note_on(RtMidiOut* midiout, int channel, int note, int volume);

int note_off(RtMidiOut* midiout, int channel, int note);

int chord_maj_on(RtMidiOut* midiout, int channel, int note, int volume);

int chord_min_on(RtMidiOut* midiout, int channel, int note, int volume);

int chord_maj_off(RtMidiOut* midiout, int channel, int note);

int chord_min_off(RtMidiOut* midiout, int channel, int note);



#endif /* SRC_MIDI_LIB_H_ */
