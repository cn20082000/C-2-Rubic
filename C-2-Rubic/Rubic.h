#pragma once
#include "Face.h"

/*
	4
0	1	2	3
	5
*/

class Rubic {
private:
	Face f[6];

	//
	void rotateRight(int index);
	void rotateLeft(int index);

	void rotateRight(int center, int north, int dirNorth, int east, int dirEast, int south, int dirSouth, int west, int dirWest);
	void rotateLeft(int center, int north, int dirNorth, int east, int dirEast, int south, int dirSouth, int west, int dirWest);
public:
	// constructor
	Rubic();
	Rubic(Face f[6]);
	Rubic(Rubic pre, int index, int ro);

	// get, set
	Face getF(int index);
	void setF(Face f, int index);
	void setF(Face f[]);

	//
	void rotate(int index, int ro);
	int check();
};