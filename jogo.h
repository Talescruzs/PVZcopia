#ifndef __JOGO_H_
#define __JOGO_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

void jogo(ALLEGRO_DISPLAY * display, ALLEGRO_FONT* font, ALLEGRO_EVENT_QUEUE * event_queue, ALLEGRO_TIMER* timer);

#endif