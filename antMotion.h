typedef struct Mrowka {
    int x;
    int y;
} *type_mrowka;



void moveAnt(type_mrowka mrowka, int currentDirection, int **map, int width, int height);