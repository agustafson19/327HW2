#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct room_struct {
    int xpos;
    int ypos;
    int xsize;
    int ysize;
} room;

int validrooms(room *rooms, int numrooms);

int main() {
    srand(time(NULL));
    int i;
    //char display[21][81];
    int numrooms = 6 + rand() % 4;
    room *rooms = malloc(sizeof(room) * numrooms);
    do {
        for (i = 0; i < numrooms; i++) {
            rooms[i].xsize = 1 + rand() % 20;
            rooms[i].ysize = 1 + rand() % 20;
            rooms[i].xpos = rand() % (80 - rooms[i].xsize);
            rooms[i].ypos = rand() % (21 - rooms[i].ysize);
        }
    } while(!validrooms(rooms, numrooms));
    free(rooms);
}

int validrooms(room *rooms, int numrooms) {
    return 0;
}
