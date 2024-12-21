#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
#include "roomManip.h"
#include "stringManip.h"
#include "construction.h"
#include <stdbool.h>

int main(int argc, char *argv[]){
    printf("Hello World\n");
    ROOM *labyrinth[5][5] = buildLabyrinth();
    printf("Start of labrynth is at %d, %d\n", labyrinth[3][0]->xCoord, labyrinth[3][0]->yCoord );
    printf("The fourth room is at %d, %d\n", labyrinth[3][0]->south->xCoord, labyrinth[3][0]->south->yCoord);
    free(labyrinth);
    return 0;
}