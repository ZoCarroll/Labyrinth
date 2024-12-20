#ifndef ROOMMANIP_H
#define ROOMMANIP_H
#include <stdbool.h>

typedef struct ROOM ROOM;
struct ROOM{
        bool start;
        bool treasure;
        ROOM *east;
        bool pathEast;
        ROOM *west;
        bool pathWest;
        ROOM *north;
        bool pathNorth;
        ROOM *south;
        bool pathSouth;
    };
ROOM* roomCreate(ROOM *room);
// ROOM *readRoomFile(char *file, int *i);
#endif