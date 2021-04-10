#include <iostream>
#include "MainView.h"

MainView::MainView() {}

Rubic MainView::inputRubic() {
	// Lua chon mau sac
	string mau[6];
	for (int i = 0; i < 6; ++i) {
		cout << "Lua chon mau sac tuong ung voi so " << i << ": ";
		cin >> mau[i];
	}
	system("cls");
	for (int i = 0; i < 6; ++i) {
		cout << "\t" << i << ": " << mau[i] << "\n";
	}

	// Nhap rubic
	Face f[6];
	vector<vector<int>> matrix;
	matrix.resize(3);
	for (int i = 0; i < 3; ++i) {
		matrix.at(i).resize(3);
	}

	cout << "\t\t4\n";
	cout << "\t0\t1\t2\t3\n";
	cout << "\t\t5\n";

	for (int i = 0; i < 6; ++i) {
		cout << "Nhap ma tran " << i << ": ";
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				cin >> matrix.at(j).at(k);
			}
		}
		f[i] = Face(matrix);
	}
	system("cls");
 	return Rubic(f);
}

void MainView::showScore(int score) {
	cout << "Diem hien tai: " << score << "\n\n";
}

void MainView::showStep(int index, int ro) {
	cout << "Xoay mat thu " << index << " ve ben ";
	if (ro == Face::RO_LEFT) {
		cout << "trai\n";
	}
	else {
		cout << "phai\n";
	}
}

void MainView::showEnd(int score) {
	cout << "Tim kiem ket thuc, ket qua dat duoc la " << score << "/36 diem.\n";
}
