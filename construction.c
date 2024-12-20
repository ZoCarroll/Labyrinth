#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "roomManip.h"
#include "construction.h"
#include <stdbool.h>



ROOM *buildLabyrinth(){
    int LABYRINTHSIZE = 2;

    //bool start, bool treasure, ROOM *north, ROOM *west, ROOM *south, ROOM *east, bool pNorth, bool pWest, bool pSouth, bool pEast  -  true, false, NULL, NULL, NULL, NULL,  false, false, false, false
    ROOM *labyrinthStart = malloc(LABYRINTHSIZE* sizeof(ROOM));
    labyrinthStart =genericRoomCreate();
    labyrinthStart->start = true;
    labyrinthStart->pathSouth = true;
    int currentSize = 1;
    ROOM *currentRoom = labyrinthStart;
    while (currentSize < LABYRINTHSIZE){
        if(currentRoom->pathNorth == true && currentRoom->north == NULL){
            currentRoom->north = northRoomCreate(currentRoom);
            currentRoom = currentRoom->north;
            currentSize++;
            continue;
        }
        else if(currentRoom->pathWest == true && currentRoom->west == NULL){
            currentRoom->west = westRoomCreate(currentRoom);
            currentRoom = currentRoom->west;
            currentSize++;
            continue;
        }
        else if(currentRoom->pathSouth == true && currentRoom->south == NULL){
            currentRoom->south = southRoomCreate(currentRoom);
            currentRoom = currentRoom->south;
            currentSize++;
            continue;
        }
        else if(currentRoom->pathEast == true && currentRoom->east == NULL){
            currentRoom->east = northRoomCreate(currentRoom);
            currentRoom = currentRoom->east;
            currentSize++;
            continue;
        }
        else currentSize++;
    }
    return labyrinthStart;
}