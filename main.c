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

    //BITMAT
    ALLEGRO_BITMAP * ervilhaBit = al_load_bitmap("./img/ervilha.png");
    ALLEGRO_BITMAP * girassolBit = al_load_bitmap("./img/girassol.png");
    ALLEGRO_BITMAP * vazioBit = al_load_bitmap("./img/vazio.png");
    ALLEGRO_BITMAP * zumbi = al_load_bitmap("./img/zumbi1.png");
    ALLEGRO_BITMAP * tiro = al_load_bitmap("./img/tiroErvilha.png");
    ALLEGRO_BITMAP * bg = al_load_bitmap("./img/testebg.png");

    //PLANTAS
    Planta VAZIO = {0, 0, 0, 0, 0, 0, 96, 96, 1, 0, vazioBit};
    Planta ERVILHA = {1, 10, 100, 220, 0, 0, 96, 96, 10, 5.5, ervilhaBit};
    Planta GIRASSOL = {2, 10, 100, 220, 0, 0, 96, 96, 10, 5.5, girassolBit};


    int continua=1;
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

    Opcoes opcoes[2];
    for(int i=0; i<2; i++){
        opcoes[i].posX = incioOpcoesX+(tamOpcoesX*i);
        opcoes[i].posY = incioOpcoesY;
        opcoes[i].recarga = 5;
    }
    opcoes[0].planta = ERVILHA;
    opcoes[1].planta = GIRASSOL;

    Opcoes opcSelecionada = {0, 0, 0, VAZIO};

    while(continua==1){
        al_wait_for_event(event_queue, &event);
        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(bg, 0, 0, 0);
        for(int i=0; i<2; i++){
            al_draw_bitmap_region(opcoes[i].planta.bitmap, opcoes[i].planta.tamX, opcoes[i].planta.tamY*0, opcoes[i].planta.tamX, opcoes[i].planta.tamY, incioOpcoesY+(tamOpcoesX*i), incioOpcoesY, 0);
        }
        
        for(int i=0; i<5; i++){
            for(int j=0; j<11; j++){
                // if(matriz[i][j].planta.id == ERVILHA.id){
                    al_draw_bitmap_region(matriz[i][j].planta.bitmap, matriz[i][j].planta.tamX*((int)(al_get_timer_count(timer)/10)%4), matriz[i][j].planta.tamY*0, matriz[i][j].planta.tamX, matriz[i][j].planta.tamY, incioXadrezX+(tamXadrezX*j), incioXadrezY+(tamXadrezY*i), 0);
                // }
            }
            al_draw_bitmap_region(zumbi, 128*((int)(al_get_timer_count(timer)/10)%4), 128*0, 128, 128, 1200-2*((int)(al_get_timer_count(timer)%700)), 220+(110*i), 0);
            al_draw_bitmap(tiro, 270+10*((int)(al_get_timer_count(timer)%90)), 230+(120*i), 0);
        }

        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            continua = -1;
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if(opcSelecionada.planta.id==0){
                printf("%d\n", opcSelecionada.planta.id);
                selcionaPlanta(event.mouse.x, event.mouse.y, &opcSelecionada, opcoes);
                printf("%d\n", opcSelecionada.planta.id);
            }
            else{
                addPlanta(event.mouse.x, event.mouse.y, &opcSelecionada, matriz);
            }
        }

        al_flip_display();
    }

    // al_destroy_bitmap(planta1);
    // al_destroy_bitmap(planta2);
    al_destroy_bitmap(ervilhaBit);
    al_destroy_bitmap(vazioBit);
    al_destroy_bitmap(zumbi);
    al_destroy_bitmap(tiro);
    al_destroy_bitmap(bg);


    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

  return 0;
}