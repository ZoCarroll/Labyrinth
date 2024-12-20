#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "roomManip.h"
#include "construction.h"
#include <stdbool.h>



ROOM *buildLabyrinth(){
    int LABYRINTHSIZE = 40;

    //bool start, bool treasure, ROOM *north, ROOM *west, ROOM *south, ROOM *east, bool pNorth, bool pWest, bool pSouth, bool pEast  -  true, false, NULL, NULL, NULL, NULL,  false, false, false, false
    ROOM *labyrinthStart = malloc(LABYRINTHSIZE* sizeof(ROOM));
    labyrinthStart =GenericRoomCreate();
    labyrinthStart->start = true;
    labyrinthStart->pathSouth = true;
    
    ROOM *currentRoom = labyrinthStart;
    if(currentRoom->pathNorth == true && currentRoom->north == NULL){
        
    }
}