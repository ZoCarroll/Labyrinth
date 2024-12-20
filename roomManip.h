#ifndef ROOMMANIP_H
#define ROOMMANIP_H
typedef struct ROOM ROOM;
struct ROOM{
        char code[16];
        char name[128];
        char description[1028];
        ROOM *east;
        ROOM *west;
        ROOM *north;
        ROOM *south;
    };
ROOM* roomCreate(ROOM *room);
ROOM *readRoomFile(char *file, int *i);
#endif