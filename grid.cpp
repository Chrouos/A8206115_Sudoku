#include"grid.h"
#include"puzzleCheck.h"

Grid::Grid() {

	Generator();
	
}


void Grid::Generator() {

	PuzzleCheck P;
	unsigned seed;
	seed = (unsigned)time(NULL); // ���o�ɶ��ǦC
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
		int row = count / 9;//�ĴX��
		int col = count % 9;//�ĴX��

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
		int row = count / 9;//�ĴX��
		int col = count % 9;//�ĴX��
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

//�N�D���k�s
void Grid::clear() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grid[i][j] = 0;
		}
	}
}


//��J�Ʀr �Ӧh�N���s
bool Grid::checkPutInGrid() {

	PuzzleCheck P;

	// ���o�ɶ��ǦC
	unsigned seed;
	seed = (unsigned)time(NULL); 
	srand(seed);

	//count ��m, FAIL �p����~����, numFail �@�ӼƦr���X��, numRand �ü�1��9
	int count, FAIL, numFail, numRand;
	//�Ʀr�O�_����
	bool nReaptingNum = true; 

	for (int n = 0; n < 9; n++) { // ��Ʀrn 1~9

		FAIL = 0; 
		for (int i = 1; i < 9; i++) {

			count = i / 3 * 27 + i % 3 * 3; //�E�c�檺�Ĥ@��
			numFail = 0; 

			int row = count / 9;
			int col = count % 9;

			while (nReaptingNum == true) {
				numRand = rand() % 9;

				int tempCount = count + numRand / 3 * 9 + numRand % 3;
				nReaptingNum = P.nReaptingCroner(n + 1, tempCount, grid);
				
				++FAIL;
				++numFail;

				int tempRow = tempCount / 9;//�ĴX��
				int tempCol = tempCount % 9;//�ĴX��

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
						int fRow = m / 9;//�ĴX��
						int fCol = m % 9;//�ĴX��
						if (grid[fRow][fCol] == n + 1) {
							grid[fRow][fCol] = 0;
						}
					}
					int mCount = n / 3 * 9 + n % 3;
					int mRow = mCount / 9;//�ĴX��
					int mCol = mCount % 9;//�ĴX��
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

