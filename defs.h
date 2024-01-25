#ifndef __DEFS_H_
#define __DEFS_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

struct Colision{
    int up, down, left, right;
};

typedef struct Planta{
    int id, vida, posX, posY, Flinha, Fcoluna, tamX, tamY, recarga;
    float ataque;
    ALLEGRO_BITMAP * bitmap;
} Planta;

typedef struct Opcoes{
    int posX, posY, recarga;
    Planta planta;
} Opcoes;

typedef struct Posicao{
    int posX, posY, tamX, tamY;
    Planta planta;
} Posicao;

//GLOBAIS
int tamXadrezX=108, tamXadrezY=108;
int incioXadrezX=120, incioXadrezY=265;
int incioOpcoesX=25, incioOpcoesY=25;
int tamOpcoesX=108, tamOpcoesY=108;


#endif