#ifndef MANHATTAN_H
#define MANHATTAN_H

#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct {
    int x;
    int y;
} point;

int manhattan(point p1, point p2);

#endif // MANHATTAN_H