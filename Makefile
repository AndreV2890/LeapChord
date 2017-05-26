CC := g++
LIBRARY := 
MIDI_OPT := -D__LINUX_ALSA__ -lasound
ALLEGRO_OPT := `allegro-config --libs`
PTHREAD_OPT := -lpthread -lrt
LEAP_LIB := leap/lib/x64/libLeap.so -Wl,-rpath,leap/lib/x64
FILE_CPP := midi/RtMidi.cpp midi/midi_lib.cpp project/project_library.cpp leap/functions_leapmotion.cpp threads_managing/my_thread_lib.c project/init_lib.cpp graphic/my_graphics.cpp
STATEMACHINE_CPP := state_machines/SX_Hand0_ert_rtw/SX_Hand0.c state_machines/DX_Hand_Fingers_ert_rtw/DX_Hand_Fingers.c

all: Timidity
	$(CC) -Wall -g main.c $(FILE_CPP) $(STATEMACHINE_CPP) -o LeapChord $(LEAP_LIB) \
	$(MIDI_OPT) $(ALLEGRO_OPT) $(PTHREAD_OPT) -L. $(LEAP_LIB) 

Timidity:
	gnome-terminal -e "timidity --realtime-priority=100 -iA -B2,8 -Os1l -s 44100"

clean:
	killall -9 timidity
	rm -rf LeapChord *.o 
