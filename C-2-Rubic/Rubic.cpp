#include "Rubic.h"

void Rubic::rotateRight(int index) {
	switch (index) {
	case 0: {
		rotateRight(0, 4, Face::DIR_WEST, 1, Face::DIR_WEST, 5, Face::DIR_WEST, 3, Face::DIR_EAST);
		break;
	}
	case 1: {
		rotateRight(1, 4, Face::DIR_SOUTH, 2, Face::DIR_WEST, 5, Face::DIR_NORTH, 0, Face::DIR_EAST);
		break;
	}
	case 2: {
		rotateRight(2, 4, Face::DIR_EAST, 3, Face::DIR_WEST, 5, Face::DIR_EAST, 1, Face::DIR_EAST);
		break;
	}
	case 3: {
		rotateRight(3, 4, Face::DIR_NORTH, 0, Face::DIR_WEST, 5, Face::DIR_NORTH, 2, Face::DIR_EAST);
		break;
	}
	case 4: {
		rotateRight(4, 3, Face::DIR_NORTH, 2, Face::DIR_NORTH, 1, Face::DIR_NORTH, 0, Face::DIR_NORTH);
		break;
	}
	case 5: {
		rotateRight(5, 1, Face::DIR_SOUTH, 2, Face::DIR_SOUTH, 3, Face::DIR_SOUTH, 0, Face::DIR_SOUTH);
		break;
	}
	}
}

void Rubic::rotateLeft(int index) {
	switch (index) {
	case 0: {
		rotateLeft(0, 4, Face::DIR_WEST, 1, Face::DIR_WEST, 5, Face::DIR_WEST, 3, Face::DIR_EAST);
		break;
	}
	case 1: {
		rotateLeft(1, 4, Face::DIR_SOUTH, 2, Face::DIR_WEST, 5, Face::DIR_NORTH, 0, Face::DIR_EAST);
		break;
	}
	case 2: {
		rotateLeft(2, 4, Face::DIR_EAST, 3, Face::DIR_WEST, 5, Face::DIR_EAST, 1, Face::DIR_EAST);
		break;
	}
	case 3: {
		rotateLeft(3, 4, Face::DIR_NORTH, 0, Face::DIR_WEST, 5, Face::DIR_NORTH, 2, Face::DIR_EAST);
		break;
	}
	case 4: {
		rotateLeft(4, 3, Face::DIR_NORTH, 2, Face::DIR_NORTH, 1, Face::DIR_NORTH, 0, Face::DIR_NORTH);
		break;
	}
	case 5: {
		rotateLeft(5, 1, Face::DIR_SOUTH, 2, Face::DIR_SOUTH, 3, Face::DIR_SOUTH, 0, Face::DIR_SOUTH);
		break;
	}
	}
}

void Rubic::rotateRight(int center, int north, int dirNorth, int east, int dirEast, int south, int dirSouth, int west, int dirWest) {
	f[center].rotate(Face::RO_RIGHT);

	vector<int> temp = f[north].getDir(dirNorth);
	f[north].setDir(f[west].getDir(dirWest), dirNorth);
	f[west].setDir(f[south].getDir(dirSouth), dirWest);
	f[south].setDir(f[east].getDir(dirEast), dirSouth);
	f[east].setDir(temp, dirEast);
}

void Rubic::rotateLeft(int center, int north, int dirNorth, int east, int dirEast, int south, int dirSouth, int west, int dirWest) {
	f[center].rotate(Face::RO_LEFT);

	vector<int> temp = f[north].getDir(dirNorth);
	f[north].setDir(f[east].getDir(dirEast), dirNorth);
	f[east].setDir(f[south].getDir(dirSouth), dirEast);
	f[south].setDir(f[west].getDir(dirWest), dirSouth);
	f[west].setDir(temp, dirWest);
}

Rubic::Rubic() {}

Rubic::Rubic(Face f[6]) {
	setF(f);
}

Rubic::Rubic(Rubic pre, int index, int ro) {
	for (int i = 0; i < 6; ++i) {
		setF(pre.getF(i), i);
	}
	rotate(index, ro);
}

Face Rubic::getF(int index) {
	return f[index];
}

void Rubic::setF(Face f, int index) {
	this->f[index] = f;
}

void Rubic::setF(Face f[]) {
	for (int i = 0; i < 6; ++i) {
		setF(f[i], i);
	}
}

void Rubic::rotate(int index, int ro) {
	switch (ro) {
	case Face::RO_LEFT: {
		rotateLeft(index);
		break;
	}
	case Face::RO_RIGHT: {
		rotateRight(index);
		break;
	}
	}
}

int Rubic::check() {
	int score = 0;
	for (int i = 0; i < 6; ++i) {
		score += f[i].check();
	}
	return score;
}
