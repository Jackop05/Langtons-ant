#include <stdio.h>
#include <stdlib.h>
#include "antMotion.h"



// Funckja przuwa mrowke w podanym kierunku o jedno pole 
// oraz zmienia pole, na ktorym stala przed przesunieciem, na odwrotny kolor
void moveAnt(type_mrowka mrowka, int currentDirection, int **map, int width, int height){
    //printf("antX: %d, antY: %d, direction: %d\n", mrowka->x, mrowka->y, currentDirection);
    
    // Zmienne pomocnicze
    int moveX = 0;
    int moveY = 0;

    // Ustalenie kierunku ruchu mrowki
    switch(currentDirection){
        case 0: 
            moveY = 1;
            break;
        case 1: 
            moveX = 1;
            break;
        case 2:
            moveY = -1;
            break;
        case 3:
            moveX = -1;
            break;
        default:
            break;
    }

    // Sprawdzenie czy ruch jest mozliwy 
    // ( jesli nir ==> mrowka zostala juz obrocona a algorytm sie nie wykona wiec pozostanie ona na tym samym polu )  
    if(mrowka->x + moveX >= 0 && mrowka->x + moveX <= width-1 && mrowka->y + moveY >= 0 && mrowka->y + moveY <= height-1){
        // Zmiana nowego pola na inny kolor
        if(map[mrowka->x][mrowka->y] == 1){
            map[mrowka->x][mrowka->y] = 0;
        } else if(map[mrowka->x][mrowka->y] == 0){
            map[mrowka->x][mrowka->y] = 1;
        } 

        // Nadanie mrowce nowych wspolrzednych
        mrowka->x = mrowka->x + moveX;
        mrowka->y = mrowka->y + moveY;
        
    } else {

        // Zmiana nowego pola na inny kolor
        if(map[mrowka->x][mrowka->y] == 1){ 
            map[mrowka->x][mrowka->y] = 0;
        } else if(map[mrowka->x][mrowka->y] == 0){
            map[mrowka->x][mrowka->y] = 1;
        } 

        if(mrowka->x + moveX < 0){
            mrowka->x = width-1;
        } else if(mrowka->x + moveX > (width-1)) {
            mrowka->x = 0;
        } else if(mrowka->y + moveY < 0) {
            mrowka->y = height-1;
        } else if(mrowka->y + moveY > (height-1)) {
            mrowka->y = 0;
        }      
    }
}