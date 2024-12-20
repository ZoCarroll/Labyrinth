#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "roomManip.h"
#include "stringManip.h"
#include "construction.h"
#include <stdbool.h>

int main(int argc, char *argv[]){
    printf("Hello World\n");
    ROOM *labyrinth = buildLabyrinth();
    printf("Start of labrynth is at %d, %d\n", labyrinth->xCoord, labyrinth->yCoord );
    printf("The secont room is at %d, %d\n", labyrinth->south->xCoord, labyrinth->south->yCoord);

    return 0;
}