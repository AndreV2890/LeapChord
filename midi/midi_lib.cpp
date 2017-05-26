
#include "../midi/midi_lib.h"

#include "../project/project_library.h"

int midi_init(RtMidiOut* midiout, int midi_port)
{
unsigned int nPorts = midiout->getPortCount();

	// Check available ports.
	if ( nPorts == 0 )
	{
		printf("No ports available!\n");
		return 0;
	}
	// Open the chosen port.
	midiout->openPort( midi_port );

	return 1;
}

int midi_set_instr(RtMidiOut* midiout, int channel, InstrumentType instrument)
{
vettore message;
char msg1;

	if ((instrument >= 0) && (instrument<=127))
	{
		msg1= ( 0xC0 ) + channel;
		message.push_back(msg1);
		message.push_back( instrument );
		midiout->sendMessage( &message );
		return 1;
	}
	return 0;
}

int note_on(RtMidiOut* midiout, int channel, int note, int volume)
{
vettore nota;
char msg1;

	if ((note >= 0) && (note<=127))
	{
		msg1= ( 0x90 ) + channel;
		nota.push_back( msg1 );
		nota.push_back( note );
		nota.push_back( volume );
		midiout->sendMessage( &nota );
		return 1;
	}
	return 0;
}

int note_off(RtMidiOut* midiout, int channel, int note)
{
vettore nota;
char msg1;

	if ((note >= 0) && (note<=127))
	{
		msg1= ( 0x80 ) + channel;
		nota.push_back( msg1 );
		nota.push_back( note );
		nota.push_back( 0 );
		midiout->sendMessage( &nota );
		return 1;
	}
	return 0;
}

int chord_maj_on(RtMidiOut* midiout, int channel, int note, int volume)
{
	note_on(midiout, channel, note , volume);
	note_on(midiout, channel, note+4 , volume);
	note_on(midiout, channel, note+7 , volume);
	note_on(midiout, channel, note+12 , volume);
	note_on(midiout, channel, note+19 , volume);
	return 1;

}

int chord_min_on(RtMidiOut* midiout, int channel, int note, int volume)
{
	note_on(midiout, channel, note , volume);
	note_on(midiout, channel, note+3 , volume);
	note_on(midiout, channel, note+7 , volume);
	note_on(midiout, channel, note+12 , volume);
	note_on(midiout, channel, note+19 , volume);
	return 1;

}

int chord_maj_off(RtMidiOut* midiout, int channel, int note)
{
	note_off(midiout, channel, note );
	note_off(midiout, channel, note+4 );
	note_off(midiout, channel, note+7 );
	note_off(midiout, channel, note+12 );
	note_off(midiout, channel, note+19 );
	return 1;

}

int chord_min_off(RtMidiOut* midiout, int channel, int note)
{
	note_off(midiout, channel, note );
	note_off(midiout, channel, note+3 );
	note_off(midiout, channel, note+7 );
	note_off(midiout, channel, note+12 );
	note_off(midiout, channel, note+19 );
	return 1;

}


