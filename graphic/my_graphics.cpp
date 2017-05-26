#include <allegro.h>

#include "my_graphics.h"

#include "../leap/functions_leapmotion.h"

using namespace Leap;

extern Controller c;
extern int tonality[TON_INDEX];
extern int keyboard[KEY_INDEX];

BITMAP* keybord;
BITMAP* caption;


BITMAP* init_screen_allegro(void)
{
BITMAP* tmp;

int width = 500;
int height = 300;
int white = 0xFFFFFF;

	tmp = create_bitmap(width, height);
	clear_bitmap(tmp);
	clear_to_color(tmp, white);

	return tmp;
}

void print_chosen_text(int step, int index, int x, int y, int bckgrd){
	switch(step){
		case 0:{
			if(index == 0)
				textout_ex(screen, font, "TASTIERA", x, y, 0, bckgrd);
			if(index == 1)
				textout_ex(screen, font, "ARPEGGIO", x, y, 0, bckgrd);
			if(index == 2)
				textout_ex(screen, font, "PENTATONICA", x, y, 0, bckgrd);
			break;
		}
		case 1:{
			if(index == 0)
				textout_ex(screen, font, "La", x, y, 0, bckgrd);
			if(index == 1)
				textout_ex(screen, font, "Sib", x, y, 0, bckgrd);
			if(index == 2)
				textout_ex(screen, font, "Si", x, y, 0, bckgrd);
			if(index == 3)
				textout_ex(screen, font, "Do", x, y, 0, bckgrd);
			if(index == 4)
				textout_ex(screen, font, "Reb", x, y, 0, bckgrd);
			if(index == 5)
				textout_ex(screen, font, "Re", x, y, 0, bckgrd);
			if(index == 6)
				textout_ex(screen, font, "Mib", x, y, 0, bckgrd);
			if(index == 7)
				textout_ex(screen, font, "Mi", x, y, 0, bckgrd);
			if(index == 8)
				textout_ex(screen, font, "Fa", x, y, 0, bckgrd);
			if(index == 9)
				textout_ex(screen, font, "Solb", x, y, 0, bckgrd);
			if(index == 10)
				textout_ex(screen, font, "Sol", x, y, 0, bckgrd);
			if(index == 11)
				textout_ex(screen, font, "Lab", x, y, 0, bckgrd);
			break;
		}
	}
}

BITMAP* create_bmp_text_menu(int menu){
	BITMAP* tmp = create_bitmap(300, 100);
	clear_bitmap(tmp);
	clear_to_color(tmp, 0xFFFFFF);

	if(menu == 0)
		textout_ex(tmp, font, "Modalità mano destra:", 10, 10, 0, -1);
	if(menu == 1)
		textout_ex(tmp, font, "Tonalità di esecuzione:", 10, 10, 0, -1);
	if(menu == 2)
		textout_ex(tmp, font, "Accordi:", 10, 10, 0, -1);

	triangle(tmp, 10, 35, 20, 30, 20, 40, 0x008000);
	triangle(tmp, 290, 35, 280, 30, 280, 40, 0x008000);

	return tmp;
}

BITMAP* create_bmp_instrum(BITMAP* bmp1, BITMAP* bmp2, BITMAP* bmp3, int hand){
	BITMAP* tmp = create_bitmap(300, 200);
	clear_bitmap(tmp);
	clear_to_color(tmp, 0xFFFFFF);
	if(hand == 0)
		textout_ex(tmp, font, "Strumento mano sinistra:", 10, 10, 0, -1);
	else
		textout_ex(tmp, font, "Strumento mano destra:", 10, 10, 0, -1);

	blit(bmp1, tmp, 0, 0, 20, 50, bmp1->w, bmp1->h);
	blit(bmp2, tmp, 0, 0, 120, 50, bmp2->w, bmp2->h);
	blit(bmp3, tmp, 0, 0, 220, 50, bmp3->w, bmp3->h);

	return tmp;
}

BITMAP* create_caption(NamesChordType chord){
	BITMAP* cap = create_bitmap(200, 400);
	clear_bitmap(cap);
	clear_to_color(cap, 0x000000);

	int space_y = 2;

	rect(cap, 1, 1, cap->w-1, cap->h-1, 0x008000);
	textout_centre_ex(cap, font, "ACCORDI:", 100, 10, 0xFFFFFF, -1);

	triangle(cap, 40, 30+space_y, 30, 50+space_y, 50, 50+space_y, 0xFFFFFF);
	//line(cap, 40, 50, 40, 60, 0xFFFFFF);
	textout_centre_ex(cap, font, chord._5_, 100, 40+space_y, 0xFFFFFF, -1);

	triangle(cap, 30, 80+space_y, 50, 80+space_y, 40, 100+space_y, 0xFFFFFF);
	//line(cap, 40, 70, 40, 80, 0xFFFFFF);
	textout_centre_ex(cap, font, chord._6_, 100, 90+space_y, 0xFFFFFF, -1);

	triangle(cap, 30, 140+space_y, 50, 130+space_y, 50, 150+space_y, 0xFFFFFF);
	//line(cap, 50, 140, 60, 140, 0xFFFFFF);
	textout_centre_ex(cap, font, chord._3_, 100, 140+space_y, 0xFFFFFF, -1);

	triangle(cap, 30, 180+space_y, 30, 200+space_y, 50, 190+space_y, 0xFFFFFF);
	//line(cap, 30, 190, 10, 190, 0xFFFFFF);
	textout_centre_ex(cap, font, chord._1_, 100, 190+space_y, 0xFFFFFF, -1);

	triangle(cap, 55, 230+space_y, 30, 250+space_y, 50, 250+space_y, 0xFFFFFF);
	line(cap, 40, 250, 35, 255, 0xFFFFFF);
	textout_centre_ex(cap, font, chord._2_, 100, 240+space_y, 0xFFFFFF, -1);

	triangle(cap, 25, 300+space_y, 30, 280+space_y, 50, 280+space_y, 0xFFFFFF);
	line(cap, 40, 280+space_y, 45, 275+space_y, 0xFFFFFF);
	textout_centre_ex(cap, font, chord._4_, 100, 290+space_y, 0xFFFFFF, -1);

	ellipse(cap, 40, 340+space_y, 10, 5, 0xFFFFFF);
	line(cap, 40, 340+space_y, 40, 320+space_y, 0xFFFFFF);
	triangle(cap, 35, 320+space_y, 45, 320+space_y, 40, 310+space_y, 0xFFFFFF);
	textout_centre_ex(cap, font, chord._7_, 100, 340+space_y, 0xFFFFFF, -1);

	return cap;
}

BITMAP* create_keybord(){
	BITMAP* key = create_bitmap(400, 400);
	clear_bitmap(key);
	clear_to_color(key, 0x000000);

	int num_key = 5;
	int raw_key = 3;
	int side = 40;
	int start_x = 140;
	int start_y = 100;
	int space = 2;

	int i = 0;
	for(i = 0; i<raw_key;i++){
		int j = 0;
		int x = start_x - i*side;
		int y = start_y + i*side*2;
		for(j = 0; j < num_key; j++){
			rectfill(key, x, y, x+side, y+side, 0xFFFFFF);
			x = x + side+ space;
		}
	}

	//textout_ex(key, font, "ULTIMA NOTA SUONATA:", 100, 370, 0xFFFFFF, -1);

	return key;
}

void update_sx_graphic(int relative_chord,int* key)
{
// relative chord: 1/7 se 0 cancella rettangolo
	if(relative_chord == 0)
	{
		blit(caption, screen, 0, 0, 100, 150, caption->w, caption->h);
	}
	else
	{

		write_notes_on_keyboard(key);


		//evidenzio l'accordo che sto suonando
		int i;
		int rect_chord[7] = {5, 6, 3, 1, 2, 4, 7};
		int x_1 = 20;
		int y_1 = 25;
		int side_x = 130;
		int side_y = 40;
		int space_y = 10;

		for(i = 0; i < 7; i++)
		{
			if(rect_chord[i] == relative_chord)
				rect(screen, 100+x_1, 150+y_1+(side_y+space_y)*i, 100+(x_1+side_x), 150+(y_1+side_y)+(side_y+space_y)*i, 0xA34529);
			else
				rect(screen, 100+x_1, 150+y_1+(side_y+space_y)*i, 100+(x_1+side_x), 150+(y_1+side_y)+(side_y+space_y)*i, 0x000000);
		}

	}
}

void write_notes_on_keyboard(int *key)
{
int i;
int side = 40;
int start_x = 80;
int start_y = 280;
int space = 2;

	//ripulisco e aggiorno le note sulla tastiera
	blit(keybord, screen, 0, 0, SCREEN_W/2, 150, keybord->w, keybord->h);

	for (i=0; i<15; i++){
		char temp[4];
		get_name_note(key[i], temp);
		if(i >= 5 && i < 10)
		{
			start_x = 120;
			start_y = 200;
		}
		if(i >= 10)
		{
			start_x = 160;
			start_y = 120;
		}

		int x = start_x + (side+space)*(i%5);
		//printf("%d\t%d\t%d\n", i, x, start_y);
		textout_centre_ex(screen, font, temp, 400+x, 150+start_y, 0x000000, -1);
	}
}

void update_dx_graphic(int tastiera,int nota,int* previous_note)
{
	int side = 40;
	int start_x = 80;
	int start_y = 280;
	int space = 2;

	// nota: 0/14, se -1 niente
	if(nota >= 0){

		//tastiera: 0,1,2
		circlefill(screen, 400 + 370, 150 + 280-(80*tastiera), 5, 0xFFFFFF);

		if(nota <5){
			start_x = 80;
			start_y = 280;
		}
		if(nota >= 5 && nota < 10)
		{
			start_x = 120;
			start_y = 200;
		}
		if(nota >= 10)
		{
			start_x = 160;
			start_y = 120;
		}

		int x = start_x + (side+space)*((nota)%5);
		circle(screen, 400+x, 150+start_y, 20, 0xEF452A);
		(*previous_note) = nota;
	}
	else
	{
		int i;
		for(i = 0; i<3; i ++)
		{
			if(i != tastiera)
				circlefill(screen, 400 + 370, 150 + 280-(80*i), 5, 0x000000);
			else
				circlefill(screen, 400 + 370, 150 + 280-(80*i), 5, 0xFFFFFF);

		}
/* CANCEL PREVIOUS NOTE */
		if ( (*previous_note) >= 0 )
		{
			if((*previous_note) <5){
				start_x = 80;
				start_y = 280;
			}
			if((*previous_note) >= 5 && (*previous_note) < 10)
			{
				start_x = 120;
				start_y = 200;
			}
			if((*previous_note) >= 10)
			{
				start_x = 160;
				start_y = 120;
			}

			int x = start_x + (side+space)*((*previous_note)%5);
			circle(screen, 400+x, 150+start_y, 20, 0xFFFFFF);
		}

	}

//nota
}


void* thread_allegro_init(void* arg)
{
boolean_T confirm_modality_of_init = false;
boolean_T *confirm;
TaskPar *tp;
InitType *parameters;

BITMAP* titolo;
BITMAP* titolo_piccolo;

BITMAP* menu;
BITMAP* modality_bmp;
BITMAP* tonality_bmp;
BITMAP* mano_dx_bmp;
BITMAP* mano_sx_bmp;
BITMAP* chord_bmp;

BITMAP* piano_c;
BITMAP* organ_c;
BITMAP* guitar_c;
BITMAP* viola_c;

BITMAP* piano_b;
BITMAP* organ_b;
BITMAP* guitar_b;
BITMAP* viola_b;


	/* Set the period */
	tp = (TaskPar *) arg;
	confirm = (boolean_T*) tp->exit;
	parameters = (InitType*) tp->arg;

	parameters->read_from_xml=false;
	parameters->exit = false;

	int white = 0xFFFFFF;
	clear_to_color(screen, white);


	titolo = load_bitmap("./graphic/titolo.BMP", NULL);
	int start_x = (SCREEN_W/2)-(titolo->w/2);
	blit(titolo, screen, 0, 0, start_x, 0, titolo->w, titolo->h);

	//init the screan (con i primi 3 pulsanti)
	menu = init_screen_allegro();

	BITMAP* xml_c = load_bitmap("./graphic/xml_c.BMP", NULL);
	BITMAP* xml_b = load_bitmap("./graphic/xml_b.BMP", NULL);

	BITMAP* config_c = load_bitmap("./graphic/config_c.BMP", NULL);
	BITMAP* config_b = load_bitmap("./graphic/config_b.BMP", NULL);

	BITMAP* door_c = load_bitmap("./graphic/door_c.BMP", NULL);
	BITMAP* door_b = load_bitmap("./graphic/door_b.BMP", NULL);


	//rect(tmp, 50, 50, 150, 150, 0);
	blit(xml_b, menu, 0, 0, 50, 50, xml_b->w, xml_b->h);
	blit(config_b, menu, 0, 0, 200, 50, config_b->w, config_b->h);
	blit(door_b, menu, 0, 0, 350, 50, door_b->w, door_b->h);

	set_period(tp);
	int start_y = 300;
	int i = 0;
	blit(menu, screen, 0, 0, start_x, start_y, menu->w, menu->h);
	blit(xml_c, screen, 0, 0, start_x+50, start_y+50, xml_c->w, xml_c->h);

	while(!confirm_modality_of_init)
	{

		if (confirm_modality(&c))
		{
			switch (i) {
				case 0:
				{
					parameters->read_from_xml = true;
					confirm_modality_of_init = true;
					break;
				}
				case 1:
				{
					confirm_modality_of_init = true;
					break;
				}
				case 2:
				{
					parameters->exit = true;
					confirm_modality_of_init = true;
					break;
				}
				default:
					break;
			}
		}

		else {
			if (change_modality(&c,&i,3))
			{
				switch(i){
					case 0:{
						blit(door_b, screen, 0, 0, start_x+350, start_y+50, door_b->w, door_b->h);
						blit(xml_c, screen, 0, 0, start_x+50, start_y+50, xml_c->w, xml_c->h);
						blit(config_b, screen, 0, 0, start_x+200, start_y+50, config_b->w, config_b->h);
						break;
					}
					case 1:{
						blit(xml_b, screen, 0, 0, start_x+50, start_y+50, xml_b->w, xml_b->h);
						blit(config_c, screen, 0, 0, start_x+200, start_y+50, config_c->w, config_c->h);
						blit(door_b, screen, 0, 0, start_x+350, start_y+50, door_b->w, door_b->h);
						break;
					}
					case 2:{
						blit(xml_b, screen, 0, 0, start_x+50, start_y+50, xml_b->w, xml_b->h);
						blit(config_b, screen, 0, 0, start_x+200, start_y+50, config_b->w, config_b->h);
						blit(door_c, screen, 0, 0, start_x+350, start_y+50, door_c->w, door_c->h);
						break;
					}
				}
				postpone_deadline(tp,500);
			}
		}



		wait_for_period(tp);
	}

	if (parameters->exit) printf("true\n");

	if (!parameters->exit && !parameters->read_from_xml)
	{
		int step = 0;

		clear_bitmap(screen);
		clear_to_color(screen, white);

		titolo_piccolo = load_bitmap("./graphic/titolo_piccolo.bmp", NULL);
		int start_x = (SCREEN_W/2)-(titolo_piccolo->w/2);
		blit(titolo_piccolo, screen, 0, 0, start_x, 0, titolo_piccolo->w, titolo_piccolo->h);

		piano_b = load_bitmap("./graphic/pianoforte_b.BMP", NULL);
		viola_b = load_bitmap("./graphic/viola_b.BMP", NULL);
		guitar_b = load_bitmap("./graphic/chitarra_elettrica_b.BMP", NULL);
		organ_b = load_bitmap("./graphic/rock_organ_b.BMP", NULL);

		piano_c = load_bitmap("./graphic/pianoforte.BMP", NULL);
		organ_c = load_bitmap("./graphic/rock_organ.BMP", NULL);
		guitar_c = load_bitmap("./graphic/chitarra_elettrica.BMP", NULL);
		viola_c = load_bitmap("./graphic/viola.BMP", NULL);

		modality_bmp = create_bmp_text_menu(0);
		tonality_bmp = create_bmp_text_menu(1);
		chord_bmp = create_bmp_text_menu(2);
		mano_dx_bmp = create_bmp_instrum(piano_b, guitar_b, viola_b, 1);
		mano_sx_bmp = create_bmp_instrum(piano_b, organ_b, guitar_b, 0);

		//Coordinate dei menu per la scelta della modalità
		int mod = 0;
		int mod_x = ((SCREEN_W/2)-modality_bmp->w)/2;
		int mod_y = 150;

		//per la scelta della modalità
		int ton = 0;
		int ton_x = (SCREEN_W/2) + ((SCREEN_W/2)-tonality_bmp->w)/2;
		int ton_y = 150;

		//per la scelta dello strumento dx
		int dx = 0;
		int mano_dx_x = (SCREEN_W/2) + ((SCREEN_W/2)-mano_dx_bmp->w)/2;
		int mano_dx_y = 300;

		//per la scelta dello strumento sx
		int sx = 0;
		int mano_sx_x = ((SCREEN_W/2)-mano_sx_bmp->w)/2;
		int mano_sx_y = 300;

		//per la scelta degli accordi
		int chord = 0;
		int chord_x = (SCREEN_W/2)-(chord_bmp->w)/2;
		int chord_y = 500;

		blit(modality_bmp, screen, 0, 0, mod_x, mod_y, modality_bmp->w, modality_bmp->h);
		blit(tonality_bmp, screen, 0, 0, ton_x, ton_y, tonality_bmp->w, tonality_bmp->h);
		blit(mano_dx_bmp, screen, 0, 0, mano_dx_x, mano_dx_y, mano_dx_bmp->w, mano_dx_bmp->h);
		blit(mano_sx_bmp, screen, 0, 0, mano_sx_x, mano_sx_y, mano_sx_bmp->w, mano_sx_bmp->h);
		blit(chord_bmp, screen, 0, 0, chord_x, chord_y, chord_bmp->w, chord_bmp->h);

		int offset_y = 32;

		/* SHOW (COLORED) PREDEFINED INSTRUMENTS */
		textout_ex(screen, font, "TASTIERA", mod_x+100, mod_y+offset_y, 0, -1);
		textout_ex(screen, font, "LA ", ton_x+100, ton_y+ offset_y, 0, -1);
		textout_ex(screen, font, "CLASSICO ", chord_x+100, chord_y+ offset_y, 0, -1);
		blit(piano_c, screen, 0, 0, mano_sx_x+20, mano_sx_y+50, piano_c->w, piano_c->h);
		blit(piano_c, screen, 0, 0, mano_dx_x+20, mano_dx_y+50, piano_c->w, piano_c->h);
		rect(screen, mod_x+1, mod_y+1, mod_x + modality_bmp->w-1, mod_y + modality_bmp->h-1, 0x008000);

		sleep(1);

		set_period(tp);
		/*
		 *
		 * MENU PER LA SCELTA DEI PARAMETRI
		 *
		 */

		while(!(*confirm))
		{
			if (confirm_modality(&c))
			{
				switch(step)
				{
					case 0:{
						step++;
						blit(modality_bmp, screen, 0, 0, mod_x, mod_y, modality_bmp->w, modality_bmp->h);
						print_chosen_text(0, mod, mod_x+100, mod_y+offset_y, -1);
						rect(screen, ton_x+1, ton_y+1, ton_x + tonality_bmp->w-1, ton_y + tonality_bmp->h-1, 0x008000);
						postpone_deadline(tp,500);
						break;
					}
					case 1:{
						step++;
						blit(tonality_bmp, screen, 0, 0, ton_x, ton_y, tonality_bmp->w, tonality_bmp->h);
						print_chosen_text(1, ton, ton_x+100, ton_y+offset_y, -1);
						rect(screen, mano_sx_x+1, mano_sx_y+1, mano_sx_x + mano_sx_bmp->w-1, mano_sx_y + mano_sx_bmp->h-1, 0x008000);
						postpone_deadline(tp,500);
						break;
					}
					case 2:{
						step++;
						blit(mano_sx_bmp, screen, 0, 0, mano_sx_x, mano_sx_y, mano_sx_bmp->w, mano_sx_bmp->h);
						if(sx == 0)
							blit(piano_c, screen, 0, 0, mano_sx_x+20, mano_sx_y+50, piano_c->w, piano_c->h);
						if(sx == 1)
							blit(organ_c, screen, 0, 0, mano_sx_x+120, mano_sx_y+50, organ_c->w, organ_c->h);
						if(sx == 2)
							blit(guitar_c, screen, 0, 0, mano_sx_x+220, mano_sx_y+50, guitar_c->w, guitar_c->h);
						rect(screen, mano_dx_x+1, mano_dx_y+1, mano_dx_x + mano_dx_bmp->w-1, mano_dx_y + mano_dx_bmp->h-1, 0x008000);
						postpone_deadline(tp,500);
						break;
					}
					case 3:{
						step++;
						blit(mano_dx_bmp, screen, 0, 0, mano_dx_x, mano_dx_y, mano_dx_bmp->w, mano_dx_bmp->h);
						if(dx == 0)
							blit(piano_c, screen, 0, 0, mano_dx_x+20, mano_dx_y+50, piano_c->w, piano_c->h);
						if(dx == 1)
							blit(guitar_c, screen, 0, 0, mano_dx_x+120, mano_dx_y+50, guitar_c->w, guitar_c->h);
						if(dx == 2)
							blit(viola_c, screen, 0, 0, mano_dx_x+220, mano_dx_y+50, viola_c->w, viola_c->h);
						rect(screen, chord_x+1, chord_y+1, chord_x + chord_bmp->w-1, chord_y + chord_bmp->h-1, 0x008000);
						postpone_deadline(tp,500);
						break;
					}
					case 4:{
						(*confirm) = true;
						break;
					}
				}
			}
			else
			{
				switch (step) {
					case 0:	//modality
					{
						if (change_modality(&c,&mod,3))
						{
							blit(modality_bmp, screen, 0, 0, mod_x, mod_y, modality_bmp->w, modality_bmp->h);
							switch (mod)
							{
								case 0: {textout_ex(screen, font, "TASTIERA", mod_x+100, mod_y+offset_y, 0, -1);	break;}
								case 1: {textout_ex(screen, font, "ARPEGGIO", mod_x+100, mod_y+offset_y, 0, -1);	break;}
								case 2: {textout_ex(screen, font, "PENTATONICA", mod_x+100, mod_y+offset_y, 0, -1);	break;}
								default: break;
							}
							rect(screen, mod_x+1, mod_y+1, mod_x + modality_bmp->w-1, mod_y + modality_bmp->h-1, 0x008000);
							postpone_deadline(tp,500);
						}
						break;
					}
					case 1:	//Tonality
					{
						if (change_modality(&c,&ton,12))
						{
							char temp_chord_print[4];
							blit(tonality_bmp, screen, 0, 0, ton_x, ton_y, tonality_bmp->w, tonality_bmp->h);
							get_name_note(57+ton,temp_chord_print);
							textout_ex(screen, font,temp_chord_print, ton_x+100, ton_y+offset_y, 0, -1);
							rect(screen, ton_x+1, ton_y+1, ton_x + tonality_bmp->w-1, ton_y + tonality_bmp->h-1, 0x008000);
							postpone_deadline(tp,500);
						}
						break;
					}
					case 2:	//Instruments SX Hands
					{
						if (change_modality(&c,&sx,3))
						{
							blit(mano_sx_bmp, screen, 0, 0, mano_sx_x, mano_sx_y, mano_sx_bmp->w, mano_sx_bmp->h);
							switch (sx)
							{
								case 0: {blit(piano_c, screen, 0, 0, mano_sx_x+20, mano_sx_y+50, piano_c->w, piano_c->h);	break;}
								case 1: {blit(organ_c, screen, 0, 0, mano_sx_x+120, mano_sx_y+50, organ_c->w, organ_c->h);	break;}
								case 2: {blit(guitar_c, screen, 0, 0, mano_sx_x+220, mano_sx_y+50, guitar_c->w, guitar_c->h);	break;}
								default: break;
							}
							rect(screen, mano_sx_x+1, mano_sx_y+1, mano_sx_x + mano_sx_bmp->w-1, mano_sx_y + mano_sx_bmp->h-1, 0x008000);
							postpone_deadline(tp,500);
						}
						break;
					}
					case 3: //Instruments DX Hands
					{
						if (change_modality(&c,&dx,3))
						{
							blit(mano_dx_bmp, screen, 0, 0, mano_dx_x, mano_dx_y, mano_dx_bmp->w, mano_dx_bmp->h);
							switch (dx)
							{
								case 0: {blit(piano_c, screen, 0, 0, mano_dx_x+20, mano_dx_y+50, piano_c->w, piano_c->h);	break;}
								case 1: {blit(guitar_c, screen, 0, 0, mano_dx_x+120, mano_dx_y+50, guitar_c->w, guitar_c->h);	break;}
								case 2: {blit(viola_c, screen, 0, 0, mano_dx_x+220, mano_dx_y+50, viola_c->w, viola_c->h);	break;}
								default: break;
							}
							rect(screen, mano_dx_x+1, mano_dx_y+1, mano_dx_x + mano_dx_bmp->w-1, mano_dx_y + mano_dx_bmp->h-1, 0x008000);
							postpone_deadline(tp,500);
						}
						break;
					}
					case 4:
					{
						if (change_modality(&c,&chord,4))
						{
							blit(chord_bmp, screen, 0, 0, chord_x, chord_y, chord_bmp->w, chord_bmp->h);
							switch (chord)
							{
								case 0: {textout_ex(screen, font, "CLASSICO ", chord_x+100, chord_y+ offset_y, 0, -1);	break;}
								case 1: {textout_ex(screen, font, "SETTIMA ", chord_x+100, chord_y+ offset_y, 0, -1);	break;}
								case 2: {textout_ex(screen, font, "SESTA ", chord_x+100, chord_y+ offset_y, 0, -1);		break;}
								case 3: {textout_ex(screen, font, "QUARTA ", chord_x+100, chord_y+ offset_y, 0, -1);	break;}
								default: break;
							}
							rect(screen, chord_x+1, chord_y+1, chord_x + chord_bmp->w-1, chord_y + chord_bmp->h-1, 0x008000);
							postpone_deadline(tp,500);
						}
						break;
					}
					default: break;
				}
			}



			wait_for_period(tp);
		}


	/*
	 * INIT PARAMETERS
	 */
		parameters->modality = (Modality) mod;
		parameters->tonality = (Tonality) ton;

		switch (dx) {
			case 0: {parameters->dxInstrument = (InstrumentType) 1;		break;}
			case 1: {parameters->dxInstrument = (InstrumentType) 30;	break;}
			case 2: {parameters->dxInstrument = (InstrumentType) 42;	break;}
			default: break;
		}
		switch (sx) {
			case 0: {parameters->sxInstrument = (InstrumentType) 1;		break;}
			case 1: {parameters->sxInstrument = (InstrumentType) 19;	break;}
			case 2: {parameters->sxInstrument = (InstrumentType) 30;	break;}
			default: break;
		}

		parameters->_1_=1;
		parameters->_2_=3;
		parameters->_3_=5;
		parameters->_4_=8;
		switch (chord) {
			case 1: //Settima
			{
				parameters->_4_=7;
				break;
			}
			case 2: //Sesta
			{
				parameters->_3_=6;
				break;
			}
			case 3: //Quarta
			{
				parameters->_2_=4;
				break;
			}
			default:
				break;
		}

		parameters->drumInstrument = (InstrumentType)115;
		parameters->bassInstrument = (InstrumentType) 33;
		parameters->bpmDrums= 800;
	}

	/*
	 *
	 * Init the new window
	 *
	 */
	clear_bitmap(screen);
	clear_to_color(screen, 0x000000);

}

void init_graphic_program_window(InitType par)
{
BITMAP* titolo_piccolo;
int start_x;
NamesChordType nomi_accordi;

	initialize_names_chord(&nomi_accordi,par.tonality);

	titolo_piccolo = load_bitmap("./graphic/titolo_piccolo.bmp", NULL);
	start_x = (SCREEN_W/2)-(titolo_piccolo->w/2);
	blit(titolo_piccolo, screen, 0, 0, start_x, 0, titolo_piccolo->w, titolo_piccolo->h);

	caption = create_caption(nomi_accordi);
	keybord = create_keybord();

	blit(caption, screen, 0, 0, 100, 150, caption->w, caption->h);
	blit(keybord, screen, 0, 0, SCREEN_W/2, 150, keybord->w, keybord->h);

	return;
}
