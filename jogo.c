#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "plantas.h"
#include "jogo.h"

void jogo(ALLEGRO_DISPLAY * display, ALLEGRO_FONT* font, ALLEGRO_EVENT_QUEUE * event_queue, ALLEGRO_TIMER* timer){
    int continua=1;
    ALLEGRO_BITMAP * planta1 = al_load_bitmap("./img/planta1.png");
    ALLEGRO_BITMAP * planta2 = al_load_bitmap("./img/planta2.png");
    ALLEGRO_BITMAP * ervilha = al_load_bitmap(ERVILHA.local_img);
    ALLEGRO_BITMAP * zumbi = al_load_bitmap("./img/zumbi1.png");
    ALLEGRO_BITMAP * tiro = al_load_bitmap("./img/tiroErvilha.png");
    ALLEGRO_BITMAP * bg = al_load_bitmap("./img/testebg.png");
    ALLEGRO_EVENT event;

    while(continua==1){
        al_wait_for_event(event_queue, &event);
        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(bg, 0, 0, 0);
        
        for(int i=0; i<5; i++){
            al_draw_bitmap(planta1, 100, 220+(120*i), 0);
            for(int j=0; j<3; j++){
                al_draw_bitmap_region(ervilha, ERVILHA.tamX*((int)(al_get_timer_count(timer)/10)%4), ERVILHA.tamY*0, ERVILHA.tamX, ERVILHA.tamY, 230+(110*j), 250+(110*i), 0);
            }
            al_draw_bitmap_region(zumbi, 128*((int)(al_get_timer_count(timer)/10)%4), 128*0, 128, 128, 1200-2*((int)(al_get_timer_count(timer)%700)), 220+(110*i), 0);
            al_draw_bitmap(tiro, 270+10*((int)(al_get_timer_count(timer)%90)), 230+(120*i), 0);
        }

        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            continua = -1;
        }
        al_flip_display();
    }

    al_destroy_bitmap(planta1);
    al_destroy_bitmap(planta2);
    al_destroy_bitmap(ervilha);
    al_destroy_bitmap(zumbi);
}