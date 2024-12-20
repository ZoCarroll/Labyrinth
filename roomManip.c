#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringManip.h"
#include "roomManip.h"

#define INITIAL_CAP  2

ROOM* roomCreate(ROOM *room){
    ROOM *newRoom = malloc(sizeof(ROOM));
    strcpy(newRoom->name, room->name);
    strcpy(newRoom->code, room->code);
    strcpy(newRoom->description, room->description);
    newRoom->north = NULL;
    newRoom->west = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;

    return newRoom;
}



ROOM *readRoomFile(char *file, int *i){

    FILE *fp = fopen(file, "r");
    printf("%s\n", file);
    if(fp == NULL){
        printf("File could not be opened.\n");
        return NULL;
    }
    int capacity = INITIAL_CAP;
    char dungeonRoom[2048];
    int index = -1;
    ROOM *newRooms = malloc(capacity * sizeof(ROOM));

    while(fgets(dungeonRoom, sizeof(dungeonRoom), fp) != NULL){

        if(strncmp(dungeonRoom, "Room Name:",10) == 0){ //run if at start of new room data
            if(index >= capacity - 1){
                capacity *= 2;
                ROOM *tempRoom = realloc(newRooms, capacity * sizeof(ROOM));
                if (tempRoom == NULL){
                    perror("problem with realloc");
                    free(newRooms);
                    return NULL;
                }
                newRooms = tempRoom;
            }
            index++;
             
            char *tempName =str_trim(dungeonRoom) ;
            tempName += 11;
            strcpy(newRooms->name, tempName);    
        }

        else if(strncmp(dungeonRoom, "Room Code:",10) == 0){ //run if at start of new room code line
            char *tempCode =str_trim(dungeonRoom) ;
            tempCode += 11;
            strcpy(newRooms->code, tempCode); 
        }

        else if(strncmp(dungeonRoom, "Room Description:",17) == 0){ //run if at start of new room description line
            char *tempDesc =str_trim(dungeonRoom) ;
            tempDesc += 18;
            strcpy(newRooms->description, tempDesc);
        }
    }

    *i = index + 1;

    return newRooms;
}