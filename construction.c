#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "roomManip.h"
#include "construction.h"
#include <stdbool.h>

#define LABYRINTHDIMENSIONS 5
#define LABYRINTHSIZE (LABYRINTHDIMENSIONS*LABYRINTHDIMENSIONS)


ROOM *buildLabyrinth(){
    int row = LABYRINTHDIMENSIONS, col = LABYRINTHDIMENSIONS;
    ROOM *labyrinth[row][col] = malloc(LABYRINTHSIZE* sizeof(ROOM));
    for(int i = 0; i <= LABYRINTHDIMENSIONS; i++){
        for(int j = 0; j <= LABYRINTHDIMENSIONS; j++){
            labyrinth[i][j] = NULL;
        }
    }

    labyrinth[LABYRINTHDIMENSIONS/2][0] =genericRoomCreate();
    labyrinth[LABYRINTHDIMENSIONS/2][0]->start = true;
    labyrinth[LABYRINTHDIMENSIONS/2][0]->pathSouth = true;
    labyrinth[LABYRINTHDIMENSIONS/2][0]->xCoord = LABYRINTHDIMENSIONS/2;
    int currentSize = 1;

    ROOM *currentRoom = labyrinth[LABYRINTHDIMENSIONS/2][0];
    while (currentSize < LABYRINTHSIZE){ //Loop as long as Labyrinth is not at max size
        if(currentRoom->pathSouth && currentRoom->south == NULL){ //runs if there is meant to be a room connected in the given direction but one is not currently connected.
            if(labyrinth[currentRoom->xCoord][currentRoom->yCoord+1] == NULL){
                currentRoom->south = southRoomCreate(currentRoom);
                currentRoom = currentRoom->south;
                labyrinth[currentRoom->xCoord][currentRoom->yCoord] = currentRoom;
                currentSize++;
                randConnections(labyrinth, currentRoom, currentSize, LABYRINTHSIZE);
            }else if(labyrinth[currentRoom->xCoord][currentRoom->yCoord+1]->pathNorth) { //If room already exists but was not connected and should be
                currentRoom->south = labyrinth[currentRoom->xCoord][currentRoom->yCoord+1];
                labyrinth[currentRoom->xCoord][currentRoom->yCoord+1]->north = currentRoom;
            }else currentRoom->pathSouth = false;
        } 
        
        else if(currentRoom->pathWest && currentRoom->west == NULL){
            if(labyrinth[currentRoom->xCoord-1][currentRoom->yCoord] == NULL){
                currentRoom->west = westRoomCreate(currentRoom);
                currentRoom = currentRoom->west;
                labyrinth[currentRoom->xCoord][currentRoom->yCoord] = currentRoom;
                currentSize++;
                randConnections(labyrinth, currentRoom, currentSize, LABYRINTHSIZE);
            }else if(labyrinth[currentRoom->xCoord-1][currentRoom->yCoord]->pathEast) {
                currentRoom->west = labyrinth[currentRoom->xCoord-1][currentRoom->yCoord];
                labyrinth[currentRoom->xCoord-1][currentRoom->yCoord]->east = currentRoom;
            }else currentRoom->pathWest = false;

        } 
        
        else if(currentRoom->pathNorth && currentRoom->north == NULL){
            if(labyrinth[currentRoom->xCoord][currentRoom->yCoord-1] == NULL){ 
                currentRoom->north = northRoomCreate(currentRoom);
                currentRoom = currentRoom->north;
                labyrinth[currentRoom->xCoord][currentRoom->yCoord] = currentRoom;
                currentSize++;
                randConnections(labyrinth, currentRoom, currentSize, LABYRINTHSIZE);
            }else if(labyrinth[currentRoom->xCoord][currentRoom->yCoord-1]->pathSouth){
                currentRoom->north = labyrinth[currentRoom->xCoord][currentRoom->yCoord-1];
                labyrinth[currentRoom->xCoord][currentRoom->yCoord-1]->south = currentRoom;
            }else currentRoom->pathNorth = false;
        } 
        
        else if(currentRoom->pathEast && currentRoom->east == NULL){
            if(labyrinth[currentRoom->xCoord+1][currentRoom->yCoord] == NULL){
                currentRoom->east = northRoomCreate(currentRoom);
                currentRoom = currentRoom->east;
                labyrinth[currentRoom->xCoord][currentRoom->yCoord] = currentRoom;
                currentSize++;
                randConnections(labyrinth, currentRoom, currentSize, LABYRINTHSIZE);
            }else if (labyrinth[currentRoom->xCoord+1][currentRoom->yCoord]->pathWest) {
                currentRoom->east = labyrinth[currentRoom->xCoord+1][currentRoom->yCoord];
                labyrinth[currentRoom->xCoord+1][currentRoom->yCoord]->west = currentRoom;
            }else currentRoom->pathEast = false;
        } 
        
        else {
            switch (currentRoom->rootPath){ // backtrack by one and loop again to fill out rooms, or end generation.
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
    return labyrinth[LABYRINTHDIMENSIONS][LABYRINTHDIMENSIONS];
}

void randConnections(ROOM* labyrinth[LABYRINTHDIMENSIONS][LABYRINTHDIMENSIONS], ROOM* room, int curSize, int labSize){
    double  prob = (sqrt((labSize - curSize)*266));
    int probInt = floor(prob);
    switch (room->rootPath){
            case 12:
                if (room->xCoord < LABYRINTHDIMENSIONS &&(labyrinth[room->xCoord+1][room->yCoord] == NULL) && (((probInt)) >= rand() % 100)){
                    room-> pathEast = true;
                }
                if (room->xCoord > 0 &&(labyrinth[room->xCoord-1][room->yCoord] == NULL) && (probInt) >= rand() % 100){
                    room-> pathWest = true;
                }
                if (room->yCoord < LABYRINTHDIMENSIONS && (labyrinth[room->xCoord][room->yCoord+1] == NULL)){
                    if (room ->north->rootPath == 12){
                        if (room ->north->north->rootPath == 12){
                            if (((1 * probInt)/6) >= rand() % 100){
                            room->pathSouth = true;
                            }

                            else if (((1 * probInt)/3) >= rand() % 100){
                            room->pathSouth = true;
                            }
                        }
                    } else {
                        if (((2 * probInt)/3) >= rand() % 100){
                        room->pathSouth = true;
                        }
                    }
                }
                break;
            case 3:
                if (room->yCoord > 0 &&(labyrinth[room->xCoord][room->yCoord-1] == NULL) && (probInt) >= rand() % 100){
                    room-> pathNorth = true;
                }
                if(room->yCoord < LABYRINTHDIMENSIONS && (labyrinth[room->xCoord][room->yCoord+1] == NULL) && ((probInt) >= rand() % 100)){
                    room-> pathSouth = true;
                }
                if (room->xCoord > 0 &&(labyrinth[room->xCoord-1][room->yCoord] == NULL)){
                    if (room ->east->rootPath == 3){
                        if (room ->east->east->rootPath == 3){
                            if (((1 * probInt)/6) >= rand() % 100){
                            room->pathWest = true;
                            }
                
                            else if (((1 * probInt)/3) >= rand() % 100){
                            room->pathWest = true;
                            }
                        }
                    } else {
                        if (((2 * probInt)/3) >= rand() % 100){
                        room->pathWest = true;
                    }
                    }  
                }  
                break;
            case 6:
                if (room->xCoord < LABYRINTHDIMENSIONS &&(labyrinth[room->xCoord+1][room->yCoord] == NULL) && (probInt) >= rand() % 100){
                    room-> pathEast = true;
                }
                if (room->xCoord > 0 &&(labyrinth[room->xCoord-1][room->yCoord] == NULL) && (probInt) >= rand() % 100){
                    room-> pathWest = true;
                }
                if(room->yCoord > 0 && (labyrinth[room->xCoord][room->yCoord-1] == NULL)){
                    if (room ->south->rootPath == 6){
                        if (room ->south->south->rootPath == 6){
                            if (((1 * probInt)/6) >= rand() % 100){
                            room->pathNorth = true;
                            }

                            else if (((1 * probInt)/3) >= rand() % 100){
                            room->pathNorth = true;
                            }
                        }
                    } else {
                        if (((2 * probInt)/3) >= rand() % 100){
                        room->pathNorth = true;
                        }
                    }
                }
                break;
            case 9:
                if (room->yCoord > 0 &&(labyrinth[room->xCoord][room->yCoord-1] == NULL) && (probInt) >= rand() % 100){
                    room-> pathNorth = true;
                }
                if(room->yCoord < LABYRINTHDIMENSIONS && (labyrinth[room->xCoord][room->yCoord+1] == NULL) && ((probInt) >= rand() % 100)){
                    room-> pathSouth = true;
                }
                if (room->xCoord < LABYRINTHDIMENSIONS && (labyrinth[room->xCoord+1][room->yCoord] == NULL)){
                    if (room ->west->rootPath == 9){
                        if (room ->west->west->rootPath == 9){
                            if (((1 * probInt)/6) >= rand() % 100){
                            room->pathEast = true;
                            }
                    
                            else if (((1 * probInt)/3) >= rand() % 100){
                            room->pathEast = true;
                            }
                        }
                    } else {
                        if (((2 * probInt)/3) >= rand() % 100){
                        room->pathEast = true;
                        }
                    }
                }
                break;
            default:

                break;
    }
}

void deconstruct(ROOM *labyrinth[LABYRINTHDIMENSIONS][LABYRINTHDIMENSIONS]){
    for (int i = LABYRINTHDIMENSIONS; i >= 0; i--){
        for (int j = LABYRINTHDIMENSIONS; j >= 0; i--){
            free(labyrinth[i][j]);
        }
    }
    labyrinth = NULL;
}