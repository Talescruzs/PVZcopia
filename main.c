#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "defs.h"
// #include "jogo.h"
#include "mecanicas.c"

int main (){
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_mouse();

    ALLEGRO_DISPLAY * display = al_create_display(1200, 900);
    al_set_window_position(display, 100, 100);
    al_set_window_title(display, "PVZ");

    ALLEGRO_FONT* font = al_load_font("./font.ttf", 30, 0);;

    ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source() );
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    int continua=1;
    ALLEGRO_BITMAP * planta1 = al_load_bitmap("./img/planta1.png");
    ALLEGRO_BITMAP * planta2 = al_load_bitmap("./img/planta2.png");
    ALLEGRO_BITMAP * ervilha = al_load_bitmap(ERVILHA.local_img);
    ALLEGRO_BITMAP * zumbi = al_load_bitmap("./img/zumbi1.png");
    ALLEGRO_BITMAP * tiro = al_load_bitmap("./img/tiroErvilha.png");
    ALLEGRO_BITMAP * bg = al_load_bitmap("./img/testebg.png");
    ALLEGRO_EVENT event;

    Posicao matriz[5][11];
    for(int i=0; i<5; i++){
        for(int j=0; j<11; j++){
            matriz[i][j].posX = incioXadrezX+(tamXadrezX*j);
            matriz[i][j].posY = incioXadrezY+(tamXadrezY*i);
            matriz[i][j].tamX = tamXadrezX;
            matriz[i][j].tamY = tamXadrezY;
            matriz[i][j].planta = VAZIO;
        }
    }

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
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
            addPlanta(event.mouse.x, event.mouse.y, ERVILHA, matriz);
        }

        al_flip_display();
    }

    al_destroy_bitmap(planta1);
    al_destroy_bitmap(planta2);
    al_destroy_bitmap(ervilha);
    al_destroy_bitmap(zumbi);


    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

  return 0;
}