#include "Face.h"

Face::Face() {}

Face::Face(vector<vector<int>> matrix) {
	this->matrix = matrix;
}

vector<vector<int>> Face::getMatrix() {
	return matrix;
}

void Face::setMatrix(vector<vector<int>> matrix) {
	this->matrix = matrix;
}

void Face::rotate(int ro) {
	switch (ro) {
	case RO_RIGHT: {
		vector<vector<int>> newMatrix;
		newMatrix.resize(3);

		for (int i = 0; i < 3; ++i) {
			newMatrix.at(i).resize(3);
			for (int j = 2; j >= 0; --j) {
				newMatrix.at(i).at(2 - j) = matrix.at(j).at(i);
			}
		}

		matrix = newMatrix;

		break;
	}
	case RO_LEFT: {
		vector<vector<int>> newMatrix;
		newMatrix.resize(3);

		for (int i = 2; i >= 0; --i) {
			newMatrix.at(2 - i).resize(3);
			for (int j = 0; j < 3; ++j) {
				newMatrix.at(2 - i).at(j) = matrix.at(j).at(i);
			}
		}

		matrix = newMatrix;

		break;
	}
	}
}

vector<int> Face::getDir(int dir) {
	vector<int> result;

	switch (dir) {
	case DIR_NORTH: {
		for (int i = 0; i < 3; ++i) {
			result.push_back(matrix.at(0).at(i));
		}
		break;
	}
	case DIR_EAST: {
		for (int i = 0; i < 3; ++i) {
			result.push_back(matrix.at(i).at(2));
		}
		break;
	}
	case DIR_SOUTH: {
		for (int i = 2; i >= 0; --i) {
			result.push_back(matrix.at(2).at(i));
		}
		break;
	}
	case DIR_WEST: {
		for (int i = 2; i >= 0; --i) {
			result.push_back(matrix.at(i).at(0));
		}
		break;
	}
	}

	return result;
}

void Face::setDir(vector<int> value, int dir) {
	switch (dir) {
	case DIR_NORTH: {
		for (int i = 0; i < 3; ++i) {
			matrix.at(0).at(i) = value.at(i);
		}
		break;
	}
	case DIR_EAST: {
		for (int i = 0; i < 3; ++i) {
			matrix.at(i).at(2) = value.at(i);
		}
		break;
	}
	case DIR_SOUTH: {
		for (int i = 2; i >= 0; --i) {
			matrix.at(2).at(i) = value.at(2 - i);
		}
		break;
	}
	case DIR_WEST: {
		for (int i = 2; i >= 0; --i) {
			matrix.at(i).at(0) = value.at(2 - i);
		}
		break;
	}
	}
}

int Face::check() {
	int score = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (matrix.at(1).at(1) == matrix.at(i).at(j)) {
				++score;
			}
		}
	}
	return score;
}
