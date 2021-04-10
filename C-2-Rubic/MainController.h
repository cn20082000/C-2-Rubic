#pragma once
#include "MainView.h"

class MainController {
private:
	MainView view;
	Rubic r;
	int score;
public:
	MainController();
	void run();
};