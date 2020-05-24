#include"sloveSudoku.h"

int SloveSudoku::ansTimes = 0;

SloveSudoku::SloveSudoku() {
	
}

bool SloveSudoku::solve(int grid[9][9], int ansGrid[9][9]) {

	PuzzleCheck P;
	
	//計算錯誤次數
	int FAIL = 0;
	//單格填入次數
	int count = 0;
	
	//九格格子
	for (int k = 0; k < 9; k++) {

		//3 * 3的區
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				//if(i=1) j=3 >> 3, 4, 5;if(i=2) j=6 >> 6, 7, 8;if(i=3) j=0 >> 0, 1, 2;
				if (grid[k / 3 * 3 + i][k % 3 * 3 + j] == 0) {
					for (int s = 1; s <= 9; s++) {
						int count = (k / 3 * 3 + i) * 9 + (k % 3 * 3 + j);
						if (P.nReaptingBlock(s, count, grid) && P.nReaptingCroner(s, count, grid) == false)
							grid[k / 3 * 3 + i][k % 3 * 3 + j] = s;
						else
							count++;
					}
				}
				if (count > 150) return false;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (grid[i][j] != ansGrid[i][j])
				return false;
		}
	}

	return true;


}//tail

int SloveSudoku::getAnsTimes() {
	return 0;
}