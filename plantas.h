#ifndef __PLANTAS_H_
#define __PLANTAS_H_
//CLASSES
struct Colision{
    int up, down, left, right;
};
typedef struct Planta{
    int vida, posX, posY, Flinha, Fcoluna, tamX, tamY, recarga;
    float ataque;
    char * local_img;
} Planta;

//PLANTAS
Planta ERVILHA = {10, 100, 220, 0, 0, 96, 96, 10, 5.5, "./img/ervilha.png"};

#endif