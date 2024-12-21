#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

ROOM* buildLabyrinth();
void randConnections(ROOM* room, int curSize, int labSize);
void deconstruct(ROOM *start);
#endif