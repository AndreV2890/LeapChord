#ifndef MY_GRAPHICS_H_
#define MY_GRAPHICS_H_

#include <allegro.h>
#include "../project/project_library.h"
#include "../project/init_lib.h"

BITMAP* init_screen_allegro(void);

BITMAP* create_bmp_text_menu(int);

BITMAP* create_bmp_instrum(BITMAP*, BITMAP*, BITMAP*, int);

BITMAP* create_caption(NamesChordType);	//chord legend

BITMAP* create_keybord();

void print_chosen_text(int, int, int, int, int);

void update_sx_graphic(int,int*);

void update_dx_graphic(int,int,int*);

void write_notes_on_keyboard(int *);

void* thread_allegro_init(void*);

void init_graphic_program_window(InitType);


#endif /* MY_GRAPHICS_H_ */
