#ifndef __DEFS_H_
#define __DEFS_H_

struct Colision{
    int up, down, left, right;
};

typedef struct Planta{
    int vida, posX, posY, Flinha, Fcoluna, tamX, tamY, recarga;
    float ataque;
    char * local_img;
} Planta;

typedef struct Posicao{
    int posX, posY, tamX, tamY;
    Planta planta;
} Posicao;

//GLOBAIS
int tamXadrezX=108, tamXadrezY=108;
int incioXadrezX=120, incioXadrezY=265;

//PLANTAS
Planta ERVILHA = {10, 100, 220, 0, 0, 96, 96, 10, 5.5, "./img/ervilha.png"};
Planta VAZIO = {0, 0, 0, 0, 0, 96, 96, 1, 0, "./img/vazio.png"};

#endif