#include"dig.h"

Dig::Dig() {

}

//初級挖空
void Dig::dig_simple(int showGrid[9][9]) {

	int randNum;
	for (int i = 0; i < 25; i++) {
		randNum = rand() % 81;

		int row = randNum / 9;//第幾行
		int col = randNum % 9;//第幾個

		//如果未挖空的話
		if (showGrid[row][col] != 0) {
			showGrid[row][col] = 0;
		}
	}

}