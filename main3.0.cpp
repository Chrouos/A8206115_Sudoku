#include<iostream>
#include"grid.h"
#include"puzzleCheck.h"
#include"sloveSudoku.h"
#include"dig.h"
#include<ctime>
using namespace std;

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

    cout << endl;
    lattice(showGrid);
    clock_t start, stop; //宣告計時器
    start = clock(); //計時器開始

    //print
    while (BlankCheck(showGrid) == false) {
        //使用者輸入位置
        int x, y, number;
        cout << "請輸入您要填入數字的左邊位置: ";
        cin >> x;
        cout << "請輸入您要填入數字的上邊位置: ";
        cin >> y;
        //判斷輸入者輸入的位置是否為0
        while (showGrid[x][y] != 0 || x>9 || y>9) {
            cout << "輸入位置錯誤!!!請輸入在題目中數字為0的位置哦" << endl;
            cout << "請輸入您要填入數字的左邊位置: ";
            cin >> x;
            cout << "請輸入您要填入數字的上邊位置: ";
            cin >> y;
        }

        cout << "請輸入要更改的數字: ";
        cin >> number;
        PuzzleCheck pc;
        while (pc.nReaptingCroner(number, 9*x+y, showGrid) == true || pc.nReaptingBlock(number, 9*x+y, showGrid) == false) {
            cout << "此數字已重複囉~請換個數字再次輸入" << endl;
            cout << "請輸入要更改的數字: ";
            cin >> number;
        }
        showGrid[x][y] = number;
        system("CLS");
        lattice(showGrid);
    }
    stop = clock();//計時器結束
    cout << "恭喜你完成了本次「數獨小遊戲」\n"
        << "你總共遊玩了: " << double(stop - start) / CLOCKS_PER_SEC << "秒!\n" //印出計時器的時間
        << "點擊Enter鍵可獲得精美小禮物呦!!!" << endl;
    cin.ignore();
        cout << "花那麼久小嫩嫩! 有種再挑戰一次呀OuOb" << endl;

    system("pause");
    return 0;
}
