#include "MainController.h"

MainController::MainController() {}

void MainController::run() {
	// Nhap rubic
	view = MainView();
	r = view.inputRubic();
	score = r.check();

	// Hien thi diem hien tai
	view.showScore(score);

	// Bat dau tinh toan
	int newScore = score;
	int index, ro;
	int re = 0;
	while (true) {
		index = -1;
		ro = -1;
		for (int i = 0; i < 6; ++i) {
			for (int j = Face::RO_LEFT; j <= Face::RO_RIGHT; ++j) {
				int sc = Rubic(r, i, j).check();
				if (sc >= newScore) {
					if (re < 20) {
						newScore = sc;
						++re;
						index = i;
						ro = j;
					}
					else {
						continue;
					}
				}
			}
		}

		if (index != -1 && ro != -1) {
			r.rotate(index, ro);
			score = r.check();

			view.showStep(index, ro);
			view.showScore(score);
		}
		else {
			break;
		}
	}

	// Ket thuc tim kiem
	view.showEnd(score);
}
