#include "mannhatan.h"

int mannhatan(point a, point b){
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}