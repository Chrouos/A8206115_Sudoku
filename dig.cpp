#include"dig.h"

Dig::Dig() {

}

//��ū���
void Dig::dig_simple(int showGrid[9][9]) {

	int randNum;
	for (int i = 0; i < 25; i++) {
		randNum = rand() % 81;

		int row = randNum / 9;//�ĴX��
		int col = randNum % 9;//�ĴX��

		//�p�G�����Ū���
		if (showGrid[row][col] != 0) {
			showGrid[row][col] = 0;
		}
	}

}