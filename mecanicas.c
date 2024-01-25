#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "defs.h"
#include "mecanicas.h"

void addPlanta(int posX, int posY, Opcoes *opcSelecionada, Posicao posicao[5][11]){
    int finalX=-1, finalY=-1;
    for(int i=0; i<5; i++){
        for(int j=0; j<11; j++){
            if(posX>=posicao[i][j].posX && posX<=(posicao[i][j].posX+tamXadrezX) && posY>=posicao[i][j].posY && posY<=(posicao[i][j].posY+tamXadrezY)){
                finalX=i;
                finalY=j;
            }
        }
    }
    if(finalX>-1 && finalY> -1){
        posicao[finalX][finalY].planta = opcSelecionada->planta;
    }
    opcSelecionada->planta.id = 0;
}

void selcionaPlanta(int posX, int posY, Opcoes *opcSelecionada, Opcoes opcoes[2]){
    int final=-1;
    for(int i=0; i<2; i++){
        if(posX>=opcoes[i].posX && posX<=(opcoes[i].posX+tamXadrezX) && posY>=opcoes[i].posY && posY<=(opcoes[i].posY+tamXadrezY)){
            final=i;
        }
    }
    if(final>-1){
        opcSelecionada->planta = opcoes[final].planta;
    }

}