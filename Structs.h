#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct
{
    int x;
    int y;
} Coordinates;

typedef struct
{
    float x;
    float y;
} Position;

typedef struct
{
    float width;
    float height;
} Size;

typedef enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT
} Direction;

#endif // STRUCTS_H
