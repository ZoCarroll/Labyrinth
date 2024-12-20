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
        int xCoord;
        int yCoord;
    };
ROOM* roomCreate(bool start, bool treasure, ROOM *north, ROOM *west, ROOM *south, ROOM *east, bool pNorth, bool pWest, bool pSouth, bool pEast, int x, int y);
ROOM* northRoomCreate(ROOM *south);
ROOM* southRoomCreate(ROOM *north);
ROOM* westRoomCreate(ROOM *east);
ROOM* eastRoomCreate(ROOM *west);
ROOM* genericRoomCreate();
// ROOM *readRoomFile(char *file, int *i);
#endif