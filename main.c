#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "antMotion.h"



// example run:   ./langtons_ant.exe 100 100 100000 file 0 

// Funkcja main()                 
int main(int argc, char **argv){

    printf("██");

    // Zmienne wejscia
    int m;
    int n;
    int i;
    char *fileName;     
    int currentDirection;                   // {0 , 1 , 2 , 3} gdzie 0 to gora a reszta liczb odpowiada kierunkom idacym zgodnie ze wskazowkami zegara
    int **starterMap = NULL;

    // argv: 0.nazwa 1.liczba_wierszy 2.liczba_kolumn 3.liczba_iteracji 4.przedrostek_plikow 
    // 5.poczatkowy_kierunek 6.plik_wczytana_mapa 7.czy_generowaclosowa__mape
    if(argc < 6 || argc > 8){
        printf("Zla liczba argumentow!\n");
        return 1;

    } else if(argc == 7 && argc != 8){
        if(atoi(argv[6]) == 0){
            printf("Jesli plik ma byc odczytany, argument 7 musi byc nazwa pliku do odczytania\n");
            return 1;
        }
        starterMap ;                        // = readFile(argv[6])

    } else if(argc == 8){
        if(atoi(argv[6]) != 0){
            printf("Jesli mapa ma byc wygenerowana losowo, parametr 6 musi byc rowny 0\n");
            return 1;
        }
        if(atoi(argv[7]) == 1){
            starterMap ;                    // = generateRandomMap();
        }
    } 

    // Przypisanie pozostalych zmiennych wejsciowych
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    i = atoi(argv[3]);
    currentDirection = atoi(argv[5]);

    // Stworzenie mapy 
    int **map = (int**)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        map[i] = (int*)malloc(m * sizeof(int *));
    }
    if(starterMap == NULL){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                map[j][k] = 0;              // 0 odpowiada bialemu polu , 1 odpowiada czarnemu polu
                
            }
        }
    }
    
    // Stworzenie struktury dla mrowki
    type_mrowka mrowka = (type_mrowka)malloc(sizeof(type_mrowka));
    mrowka->x = m/2;
    mrowka->y = n/2;

    // Petla odpowiadajaca za poruszanie sie mrowki i razy
    for(int j = 0; j < i; j++){

        // Jesli pole na ktorym stoi mrowka jest czarne 
        if(map[mrowka->x][mrowka->y] == 1){
            if(currentDirection == 0){
                currentDirection = 3;
            } else {
                currentDirection -= 1;
            }

        // Jesli pole na ktorym stoi mrowka jest biale
        } else if(map[mrowka->x][mrowka->y] == 0){
            if(currentDirection == 3){
                currentDirection = 0;
            } else {
                currentDirection += 1;
            }
        }

        moveAnt(mrowka, currentDirection, map, m, n); 
    }

    printf(" ");
    for(int i = 0; i < 2*n; i++) {
        printf("─");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("│");
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("│\n");
    }
    printf(" ");
    for(int i = 0; i < 2*n; i++) {
        printf("─");
    }
    printf("\n");

}