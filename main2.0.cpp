#include<iostream>
#include"grid.h"
#include"puzzleCheck.h"
#include"sloveSudoku.h"
#include"dig.h"
using namespace std;

//判斷數獨中是否還有空格
bool BlankCheck(int showGrid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (showGrid[i][j] == 0) return false;
        }
    }
}

//印出數獨中的最新數字
void print(int showGrid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << showGrid[i][j];
        }
        cout << endl;
    }
}

//畫格子
void lattice(int showGrid[9][9]) {
    cout << "  x" << "0 " << "1 " << "2   " << "3 " << "4 " << "5   " << "6 " << "7 " << "8 " << endl; //位置編號
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) cout << "y|-----------------------" << endl;
        for (int j = 0; j < 9; j++) {
            if (j == 0) cout << i << "| ";
            else if (j != 0 && j % 3 == 0) cout << "| ";
            cout << showGrid[i][j] << " ";
        }
        cout << endl;
    }
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

    Dig D;
    D.dig_simple(showGrid);
    
    //print
    while (BlankCheck(showGrid) == false) {
        //使用者輸入位置
        int x, y;
        cout << "請輸入您要填入數字的x軸位置: ";
        cin >> x;
        cout << "請輸入您要填入數字的y軸位置: ";
        cin >> y;
        //判斷輸入者輸入的位置是否為0
    }

    SloveSudoku S;

    system("pause");
    return 0;
}