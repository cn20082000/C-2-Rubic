#pragma once
#include <vector>

using namespace std;

class Face {
private:
	vector<vector<int>> matrix;
public:
	// static
	static const int DIR_NORTH = 1;
	static const int DIR_EAST = 2;
	static const int DIR_SOUTH = 3;
	static const int DIR_WEST = 4;

	static const int RO_LEFT = 101;
	static const int RO_RIGHT = 102;

	// contructor
	Face();
	Face(vector<vector<int>> matrix);

	// get, set
	vector<vector<int>> getMatrix();
	void setMatrix(vector<vector<int>> matrix);

	// 
	void rotate(int ro);
	vector<int> getDir(int dir);
	void setDir(vector<int> value, int dir);
	int check();
};