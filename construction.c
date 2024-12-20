#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
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
        } else if(currentRoom->pathWest == true && currentRoom->west == NULL){
            currentRoom->west = westRoomCreate(currentRoom);
            currentRoom = currentRoom->west;
            currentSize++;
        } else if(currentRoom->pathSouth == true && currentRoom->south == NULL){
            currentRoom->south = southRoomCreate(currentRoom);
            currentRoom = currentRoom->south;
            currentSize++;
        } else if(currentRoom->pathEast == true && currentRoom->east == NULL){
            currentRoom->east = northRoomCreate(currentRoom);
            currentRoom = currentRoom->east;
            currentSize++;
        } else {
            switch (currentRoom->rootPath){
            case 12:
                currentRoom = currentRoom->north;
                break;
            case 3:
                currentRoom = currentRoom->east;
                break;
            case 6:
                currentRoom = currentRoom->south;
                break;
            case 9:
                currentRoom = currentRoom->west;
                break;
            case 0:
                printf("Currently at start of labyrinth. The size of the labyrinth is %d rooms\nEnding labyrinth construction\n", currentSize);
                currentSize = LABYRINTHSIZE + 1;
                break;

            default:
                printf("There was an error\nStopping generation");
                currentSize = LABYRINTHSIZE + 1;
                break;
            }
        }
    }
    return labyrinthStart;
}

void randConnections(ROOM* room, int curSize, int labSize){
    double  prob = (((labSize - curSize)*2.5641025641)/curSize);
    int probInt = floor(prob);
    switch (room->rootPath){
            case 12:
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathEast = true;
                }
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathWest = true;
                }
                if (room ->north->rootPath == 12){
                    if (room ->north->north->rootPath == 12){
                        if (rand() % ((1 * probInt)/6) >= rand() % 100){
                        room->pathSouth = true;
                        }
                    
                        if (rand() % ((1 * probInt)/3) >= rand() % 100){
                        room->pathSouth = true;
                        }
                    }
                } else {
                    if (rand() % ((2 * probInt)/3) >= rand() % 100){
                    room->pathSouth = true;
                    }
                }
                break;
            case 3:
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathNorth = true;
                }
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathSouth = true;
                }
                if (room ->east->rootPath == 3){
                    if (room ->east->east->rootPath == 3){
                        if (rand() % ((1 * probInt)/6) >= rand() % 100){
                        room->pathWest = true;
                        }
                    
                        if (rand() % ((1 * probInt)/3) >= rand() % 100){
                        room->pathWest = true;
                        }
                    }
                } else {
                    if (rand() % ((2 * probInt)/3) >= rand() % 100){
                    room->pathWest = true;
                }
                }
                break;
            case 6:
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathEast = true;
                }
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathWest = true;
                }
                if (room ->south->rootPath == 6){
                    if (room ->south->south->rootPath == 6){
                        if (rand() % ((1 * probInt)/6) >= rand() % 100){
                        room->pathNorth = true;
                        }
                    
                        if (rand() % ((1 * probInt)/3) >= rand() % 100){
                        room->pathNorth = true;
                        }
                    }
                } else {
                    if (rand() % ((2 * probInt)/3) >= rand() % 100){
                    room->pathNorth = true;
                    }
                }
                break;
            case 9:
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathNorth = true;
                }
                if (rand() % ((probInt)) >= rand() % 100){
                    room-> pathSouth = true;
                }
                if (room ->west->rootPath == 9){
                    if (room ->west->west->rootPath == 9){
                        if (rand() % ((1 * probInt)/6) >= rand() % 100){
                        room->pathEast = true;
                        }
                    
                        if (rand() % ((1 * probInt)/3) >= rand() % 100){
                        room->pathEast = true;
                        }
                    }
                } else {
                    if (rand() % ((2 * probInt)/3) >= rand() % 100){
                    room->pathEast = true;
                    }
                }
                break;
            default:

                break;
    }
}