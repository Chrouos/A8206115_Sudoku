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
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << showGrid[i][j] << " ";
        }
        cout << endl;
    }
    

    SloveSudoku S;


    


    system("pause");
    return 0;
}



