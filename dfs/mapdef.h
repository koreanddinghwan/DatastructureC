#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

//matrix
/*
 *    x ->
 *  y 0 1 2 3 4
 *  | 1
 *    2
 *    3
 * */

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// down
	{1, 0},			// right
	{0, 1},			// up
	{-1, 0}			// left
};

#define DOWN DIRECTION_OFFSETS[0]
#define RIGHT DIRECTION_OFFSETS[1]
#define UP DIRECTION_OFFSETS[2]
#define LEFT DIRECTION_OFFSETS[3]

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2, P, E };

#endif
