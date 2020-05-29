#include<iostream>
#include"grid.h"
#include"puzzleCheck.h"
#include"sloveSudoku.h"
#include"dig.h"
using namespace std;

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
    //畫格子
    cout << "A " << "B " << "C   " << "D " << "E " << "F   " << "G " << "H " << "I " << endl; //上面的字母編號
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) cout << "---------------------" << endl;
        for (int j = 0; j < 9; j++) {
            if (j!=0 && j % 3 == 0) cout << "| ";
            cout << showGrid[i][j] << " ";
        }
        cout << endl;
    }

    //左邊的字母編號
    /*
    數獨中的亂數有問題
    cout << "   " << "A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << endl;
    cout << "  ------------------" << endl;
    int j = 97;
    for (int i = 0; i < 9; i++) {
        while (j <=105 ){
            cout << char(j) << "| ";
            for (int k = 0; k < 9; k++) {
             cout << showGrid[i][k] << " ";
            }
            cout << endl;
            j++;
        }
    } 
    */

    //判斷及填入數字
    PuzzleCheck p;

    while (p.check(showGrid) == false) {//判斷直橫區是否相加有45
        cout << "Did not enter all digits in 0 ~9.Please enter the complete 0~9: ";//未輸入0~9內所有數字 請輸入完整的0~9
        for (int i = 0; i < 9; i++) {
            cout << "Enter a number: ";
            for (int j = 0; j < 9; j++) {
                if (showGrid[i][j] == 0) {
                    int input;
                    cin >> input;
                    showGrid[i][j] = input;//將數字填入
                    if (p.nReaptingBlock(input, 25, showGrid) == false || p.nReaptingCroner(input, 25, showGrid) == false) {//判斷此數字是否重複
                        showGrid[i][j] = 0;
                        cout << "This number is repeated.Please enter a new number: ";//這個數字重複了 請輸入一個新的數字
                        continue;
                    }
                    else {
                        for (int i = 0; i < 9; i++) {
                            if (i % 3 == 0) cout << "---------------------" << endl;
                            for (int j = 0; j < 9; j++) {
                                if (j != 0 && j % 3 == 0) cout << "| ";
                                cout << showGrid[i][j] << " "; //印出最新答案
                            }
                            cout << endl;
                        }
                    }
                }
            }
        }
    }

    SloveSudoku S;

    system("pause");
    return 0;
}
