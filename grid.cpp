#include"grid.h"
#include"puzzleCheck.h"

Grid::Grid() {

	Generator();
	
}


void Grid::Generator() {

	PuzzleCheck P;
	unsigned seed;
	seed = (unsigned)time(NULL); // 取得時間序列
	srand(seed);

	clear();

	int filledInNum[9] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++) {
	/*
	replay:
		int numRand = (rand() % 9) + 1;
		if (filledInNum[numRand - 1] == 0) goto replay;

		for (int j = 0; j < 9; j++) {
			if (numRand == filledInNum[j]) filledInNum[j] = 0;
			//cout << numRand;
		}
		*/
		int count = i / 3 * 9 + i % 3;
		int row = count / 9;//第幾行
		int col = count % 9;//第幾個

		grid[row][col] = i+1;

		/*
		if (i <= 2)	grid[0][i] = numRand;
		else if (i <= 5)grid[1][i - 3] = numRand;
		else if (i <= 8) grid[2][i - 6] = numRand;
*/
	}

	bool check = false;
	while (!check) {
		check = checkPutInGrid();
	}

	
	
	
	int numtmp[9] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++) {
		int numRand = rand() % 9;
		int temp = numtmp[i];
		numtmp[i] = numtmp[numRand];
		numtmp[numRand] = temp;
	}
			
	for (int count = 0; count < 81; count++) {
		int row = count / 9;//第幾行
		int col = count % 9;//第幾個
		grid[row][col] = numtmp[grid[row][col] - 1];
	}
	
	



}




void Grid::print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

//將題目歸零
void Grid::clear() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = 0;
		}
	}
}


//填入數字 太多就重新
bool Grid::checkPutInGrid() {

	PuzzleCheck P;

	// 取得時間序列
	unsigned seed;
	seed = (unsigned)time(NULL); 
	srand(seed);

	//count 位置, FAIL 計算錯誤次數, numFail 一個數字錯幾次, numRand 亂數1～9
	int count, FAIL, numFail, numRand;
	//數字是否重複
	bool nReaptingNum = true; 

	for (int n = 0; n < 9; n++) { // 填數字n 1~9

		FAIL = 0; 
		for (int i = 1; i < 9; i++) {

			count = i / 3 * 27 + i % 3 * 3; //九宮格的第一格
			numFail = 0; 

			int row = count / 9;
			int col = count % 9;

			while (nReaptingNum == true) {
				numRand = rand() % 9;

				int tempCount = count + numRand / 3 * 9 + numRand % 3;
				nReaptingNum = P.nReaptingCroner(n + 1, tempCount, grid);
				
				++FAIL;
				++numFail;

				int tempRow = tempCount / 9;//第幾行
				int tempCol = tempCount % 9;//第幾個

				if (grid[tempRow][tempCol] == 0 && nReaptingNum == false) {
					grid[tempRow][tempCol] = n + 1;
					nReaptingNum = true;
					break;
				}
				else {
					nReaptingNum = true;
				}
				if (numFail > 100) {
					for (int m = 0; m < 81; m++) {
						int fRow = m / 9;//第幾行
						int fCol = m % 9;//第幾個
						if (grid[fRow][fCol] == n + 1) {
							grid[fRow][fCol] = 0;
						}
					}
					int mCount = n / 3 * 9 + n % 3;
					int mRow = mCount / 9;//第幾行
					int mCol = mCount % 9;//第幾個
					grid[mRow][mCol] = n + 1;
					i = 0;
					break;
				}
				if (FAIL > 1000)
					return false;
			}
		}
	}
	return true;
}

