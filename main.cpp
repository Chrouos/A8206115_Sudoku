#include<iostream>
#include"grid.h"
#include"puzzleCheck.h"
#include"sloveSudoku.h"
#include"dig.h"
#include<ctime>
using namespace std;

bool outOf(int num) {
	if (num == -1) {
		cout << "你輸入了-1,即將重新重新輸入" << endl;
		system("pause");
		system("CLS");
		return false;
	}
	return true;
}

//判斷數獨中是否還有空格
bool BlankCheck(int showGrid[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (showGrid[i][j] == 0) return false;
		}
	}
}

//畫格子及印出
void lattice(int showGrid[9][9]) {
	cout << "    " << "0 " << "1 " << "2   " << "3 " << "4 " << "5   " << "6 " << "7 " << "8 " << endl; //位置編號
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) cout << "  ————————————" << endl;
		for (int j = 0; j < 9; j++) {
			if (j == 0) cout << i << " | ";
			else if (j != 0 && j % 3 == 0) cout << "| ";
			cout << showGrid[i][j] << " ";
		}
		cout << endl;
	}
	cout << "  ————————————" << endl;
}

int main()
{
	Grid ansGrid;
	// Grid showGrid(ansGrid);

	 //GRID 轉換成 INT
	int grid[9][9];
	for (int i = 0; i < 81; i++) {
		int row = i / 9;//第幾行
		int col = i % 9;//第幾個
		grid[row][col] = ansGrid[i];
	}

	int showGrid[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			showGrid[i][j] = grid[i][j];
		}
	}

	cout << "哈囉哈囉，歡迎你開啟了這個「數獨小遊戲」，以下為遊戲說明及規則↓↓↓\n\n"
		<< "說明:\n遊戲目的為將9x9的方塊填滿數字\n讓每一行、每一列及每一格3x3的方塊中都填滿數字\n0為空格表示需要輸入數字的位置\n\n"
		<< "規則:\n只能填入1到9之間的數字且不能重複\n\n"
		<< "點擊Enter便開始遊戲哦!!!";

	cin.ignore(); //暫停之後再執行

	Dig D;
	D.dig_simple(showGrid);

	clock_t start, stop; //宣告計時器
	start = clock(); //計時器開始

	//print
	while (BlankCheck(showGrid) == false) {

		system("CLS");
		lattice(showGrid);

		//使用者輸入位置
		int x, y, number;
		cout << "請輸入您要填入數字的左邊位置(輸入-1可重新填入位置): ";
		cin >> x;
		if (outOf(x) == false) continue;

		cout << "請輸入您要填入數字的上邊位置(輸入-1可重新填入位置): ";
		cin >> y;
		//判斷輸入者輸入的位置是否為0
		if (outOf(y) == false) continue;
		if (showGrid[x][y] != 0) {
			cout << "您輸入的位置為題目,不可更改,請重新輸入位置" << endl;
			system("pause");
			continue;
		}

		cout << "請輸入要更改的數字(輸入-1可重新填入位置): ";
		cin >> number;

		PuzzleCheck pc;
		while (pc.nReaptingCroner(number, 9 * x + y, showGrid) == true || pc.nReaptingBlock(number, 9 * x + y, showGrid) == false
			|| number == -1 || number < 0 || number > 9) {
			cout << "此數字是錯誤的~請換個數字再次輸入" << endl;
			cout << "請輸入要更改的數字: ";
			cin >> number;
		}
		if (outOf(number) == false) continue;

		showGrid[x][y] = number;
	}

	stop = clock();//計時器結束
	cout << "恭喜你完成了本次「數獨小遊戲」\n"
		<< "你總共遊玩了: " << double(stop - start) / CLOCKS_PER_SEC << "秒!\n" //印出計時器的時間
		<< "點擊Enter鍵可獲得精美小禮物呦!!!" << endl;
	cin.ignore();
	cout << "花那麼久 小嫩嫩! 有種再挑戰一次呀 OuOb" << endl;

	system("pause");
	return 0;
}
