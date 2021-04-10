#pragma once
#include "Rubic.h"

using namespace std;

class MainView {
public:
	// constructor
	MainView();

	//
	Rubic inputRubic();
	void showScore(int score);
	void showStep(int index, int ro);
	void showEnd(int score);
};