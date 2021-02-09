#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define W_WIDTH 80
#define W_HEIGHT 24

typedef struct room_struct {
    int xpos;
    int ypos;
    int xsize;
    int ysize;
} room;

void createrooms(room *rooms, int numrooms);
int validrooms(room *rooms, int numrooms);
void initDisplay(char display[W_HEIGHT][W_WIDTH]);

int main() {
    srand(time(NULL));

    int i, j; //, k;
    int numrooms;
    room *rooms;
    char display[W_HEIGHT][W_WIDTH];

    numrooms = 6 + rand() % 4;
    rooms = malloc(sizeof(room) * numrooms);
    createrooms(rooms, numrooms);
    initDisplay(display);
    /*
    for (i = 0; i < numrooms; i++) {
        for (j = 0; j < rooms[i].ysize; j++) {
            for (k = 0; k < rooms[i].xsize; k++) {
                display[rooms[i].ypos + k][rooms[i].xpos + j] = '.';
            }
        }
    }
    */
    for (i = 0; i < W_HEIGHT; i++) {
        for (j = 0; j < W_WIDTH; j++) {
            printf("%c", display[i][j]);
        }
        printf("\n");
    }
    
    free(rooms);
}

void createrooms(room *rooms, int numrooms) {
    int i;
    do {
        for (i = 0; i < numrooms; i++) {
            rooms[i].xsize = 4 + rand() % 10;
            rooms[i].ysize = 3 + rand() % 10;
            rooms[i].xpos = rand() % (W_WIDTH - rooms[i].xsize);
            rooms[i].ypos = rand() % (W_HEIGHT - rooms[i].ysize);
        }
    } while(0 /*!validrooms(rooms, numrooms)*/);
}

int validrooms(room *rooms, int numrooms) {
    int i, j;
    for (i = 1; i < numrooms; i++) {
        for (j = 0; j < i; j++) {
            if (!(rooms[i].xpos + rooms[i].xsize <= rooms[j].xpos || rooms[j].xpos + rooms[j].xsize <= rooms[i].xpos)
                    && !(rooms[i].ypos + rooms[i].ysize <= rooms[j].ypos || rooms[j].ypos + rooms[j].ysize <= rooms[i].ypos)) {
                return 0;
            }
        }
    }
    return 1;
}

void initDisplay(char display[W_HEIGHT][W_WIDTH]) {
    int i, j;
    for (i = 0; i < W_HEIGHT; i++) {
        for (j = 0; j < W_WIDTH; j++) {
            display[i][j] = ' ';
        }
    }
}
