#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringManip.h"
#include "roomManip.h"
#include <stdbool.h>

#define INITIAL_CAP  2

ROOM* roomCreate(bool start, bool treasure, ROOM *north, ROOM *west, ROOM *south, ROOM *east, bool pNorth, bool pWest, bool pSouth, bool pEast){
    ROOM *newRoom = malloc(sizeof(ROOM));
    newRoom->start = start;
    newRoom->treasure = treasure;
    newRoom->north = north;
    newRoom->pathNorth = pNorth;
    newRoom->west = west;
    newRoom->pathWest = pWest;
    newRoom->south = south;
    newRoom->pathSouth = pSouth;
    newRoom->east = east;
    newRoom->pathEast = pEast;

    return newRoom;
}

ROOM* northRoomCreate(ROOM *south){
    bool start = false;
    bool treasure = false;
    ROOM *north = NULL;
    bool pathNorth = false;
    ROOM *west = NULL;
    bool pathWest = false;
    ROOM *south = south;
    bool pathSouth = true;
    ROOM *east = NULL;
    bool pathEast = false;

    return roomCreate(start, treasure, north, west, south, east, pathNorth, pathWest, pathSouth, pathEast);
}

ROOM* southRoomCreate(ROOM *north){
    bool start = false;
    bool treasure = false;
    ROOM *north = north;
    bool pathNorth = true;
    ROOM *west = NULL;
    bool pathWest = false;
    ROOM *south = NULL;
    bool pathSouth = false;
    ROOM *east = NULL;
    bool pathEast = false;

    return roomCreate(start, treasure, north, west, south, east, pathNorth, pathWest, pathSouth, pathEast);
}

ROOM* westRoomCreate(ROOM *east){
    bool start = false;
    bool treasure = false;
    ROOM *north = NULL;
    bool pathNorth = false;
    ROOM *west = NULL;
    bool pathWest = false;
    ROOM *south = NULL;
    bool pathSouth = false;
    ROOM *east = east;
    bool pathEast = true;

    return roomCreate(start, treasure, north, west, south, east, pathNorth, pathWest, pathSouth, pathEast);
}

ROOM* eastRoomCreate(ROOM *west){
    bool start = false;
    bool treasure = false;
    ROOM *north = NULL;
    bool pathNorth = false;
    ROOM *west = west;
    bool pathWest = true;
    ROOM *south = NULL;
    bool pathSouth = false;
    ROOM *east = NULL;
    bool pathEast = false;

    return roomCreate(start, treasure, north, west, south, east, pathNorth, pathWest, pathSouth, pathEast);
}

// ROOM* genericRoomCreate(ROOM *south){
//     bool start = false;
//     bool treasure = false;
//     ROOM *north = NULL;
//     bool pathNorth = false;
//     ROOM *west = NULL;
//     bool pathWest = false;
//     ROOM *south = NULL;
//     bool pathSouth = false;
//     ROOM *east = NULL;
//     bool pathEast = false;

//     return roomCreate(start, treasure, north, west, south, east, pathNorth, pathWest, pathSouth, pathEast);
// }




//  ROOM *readRoomFile(char *file, int *i){

//     FILE *fp = fopen(file, "r");
//     printf("%s\n", file);
//     if(fp == NULL){
//         printf("File could not be opened.\n");
//         return NULL;
//     }
//     int capacity = INITIAL_CAP;
//     char dungeonRoom[2048];
//     int index = -1;
//     ROOM *newRooms = malloc(capacity * sizeof(ROOM));

//     while(fgets(dungeonRoom, sizeof(dungeonRoom), fp) != NULL){

//         if(strncmp(dungeonRoom, "Room Name:",10) == 0){ //run if at start of new room data
//             if(index >= capacity - 1){
//                 capacity *= 2;
//                 ROOM *tempRoom = realloc(newRooms, capacity * sizeof(ROOM));
//                 if (tempRoom == NULL){
//                     perror("problem with realloc");
//                     free(newRooms);
//                     return NULL;
//                 }
//                 newRooms = tempRoom;
//             }
//             index++;
             
//             char *tempName =str_trim(dungeonRoom) ;
//             tempName += 11;
//             strcpy(newRooms->name, tempName);    
//         }

//         else if(strncmp(dungeonRoom, "Room Code:",10) == 0){ //run if at start of new room code line
//             char *tempCode =str_trim(dungeonRoom) ;
//             tempCode += 11;
//             strcpy(newRooms->code, tempCode); 
//         }

//         else if(strncmp(dungeonRoom, "Room Description:",17) == 0){ //run if at start of new room description line
//             char *tempDesc =str_trim(dungeonRoom) ;
//             tempDesc += 18;
//             strcpy(newRooms->description, tempDesc);
//         }
//     }

//     *i = index + 1;

//     return newRooms;
// }