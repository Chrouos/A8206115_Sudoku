#include<iostream>
#include"grid.h"
#include"puzzleCheck.h"
#include"sloveSudoku.h"
#include"dig.h"
using namespace std;

void ShowBoard(int grid[9][9]);
bool checkNumDown(int grid[9][9]);
int returnX(char xNum);
bool checkAns(int showGrid[9][9], int ansGrid[9][9]);

int main()
{

    Grid ansGrid; // 為 Grid 完整版 = 答案

    //GRID 轉換成 INT
    int grid[9][9];
    for (int i = 0; i < 81; i++) {
        int row = i / 9;//第幾行
        int col = i % 9;//第幾個
        grid[row][col] = ansGrid[i];
    }

    //製作一個讓使用填入的 (ShowGrid = 顯示在畫面上的棋盤)
    int showGrid[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            showGrid[i][j] = grid[i][j];
        }
    }

    Dig D; // 挖空物件呼叫
    D.dig_simple(showGrid); // 對 showGrid進行挖空


    PuzzleCheck P;

    // 遊戲開始前說明
    cout << "哈囉哈囉，歡迎你開啟了這個「數獨小遊戲」，以下為遊戲說明!!\n\n"
        << "說明：\n遊戲目的為將 9x9 的方塊填滿數字\n讓每一行、每一列及每一格 3x3 的方塊中，?有1至9的數字，不可重複。"
        << "點擊 Enter 便開始遊戲哦!! \n\n";
    system("pause");

    char xNum;
    int yNum, ansNumber; // X為橫軸位置，Y為豎軸位置，ansNumber
    bool checkDownTheGame = false;
    while (checkDownTheGame != true) {

        system("CLS");
        ShowBoard(showGrid);

        cout << "請填入想輸入數字的位置，如(5A, 6C, 9I...)\n請先輸入左邊位置( 1 ~ 9 ): ";
        cin >> yNum;
        cout << "請填入想輸入數字的位置，如(5A, 6C, 9I...)\n請先輸入上邊位置( A ~ I ): ";
        cin >> xNum;

        if (returnX(xNum) == -1 || yNum < 0 || yNum>9) {
            cout << "你輸入的數字不再範圍內" << endl;
            system("pause");
            system("CLS");
            continue;
        }

        cout << "請輸入你想輸入的值 ( 1 ~ 9 ): ";
        cin >> ansNumber;

        int count = (yNum - 1) * 9 + returnX(xNum);
        if (showGrid[yNum - 1][returnX(xNum)] == 0 && P.nReaptingCroner(ansNumber, count, showGrid) == false 
            && P.nReaptingBlock(ansNumber, count, showGrid) == true) 
            showGrid[yNum - 1][returnX(xNum)] = ansNumber;  // 將數字輸入進去

        else if (P.nReaptingCroner(ansNumber, count, showGrid) != false
            || P.nReaptingBlock(ansNumber, count, showGrid) != true) {
            cout << "輸入的數字已重複" << endl;
            system("pause");
            system("CLS");
            continue;
        }

        else {
            cout << "不可輸入已有數字的地方" << endl;
            system("pause");
            system("CLS");
            continue; 
        }
        
        checkDownTheGame = checkNumDown(showGrid);  // 確認數字有沒有輸入完成

    }

    system("CLS");
    ShowBoard(showGrid);
    
    if (checkAns(showGrid, grid) == true) { // 如果答案一致
        cout << "恭喜你!!!! 這是正解。";
    }
    else {
        cout << "很可惜，你輸了。";
    }

    cout << "正解為: " << endl << endl;

    ShowBoard(grid);
    
    
    system("pause");
    return 0;
}


// 製作棋盤(有格式)的呼叫
void ShowBoard(int grid[9][9]) {

    cout << "    A B C   D E F   G H I" << endl;
    int topicNum = 1;
    for (int i = 0; i < 9; i++) {       
        if (i % 3 == 0) { // 0, 2, 5, 8 時畫 -------
            cout << "  －－－－－－－－－－－－" << endl;
        }
        cout << topicNum++ << " ";
        for (int j = 0; j < 9; j++) {
            if ( j % 3 == 0 ) cout << "| ";
            
            cout << grid[i][j] << " ";
        }     
        cout << "|" << endl;
        
    }
    cout << "  －－－－－－－－－－－－" << endl;


}

// 判斷是否全部填完
bool checkNumDown(int grid[9][9]) {
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) return false; //回傳 false 代表還沒填完
        }
    }
    return true; // 回傳 true 代表填完了

}

// 將 A ~ I 轉為 0 ~ 9
int returnX(char xNum) {

    switch (xNum)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    case 'G':
        return 6;
    case 'H':
        return 7;
    case 'I':
        return 8;
    default:
        break;
    }

    return -1;

}

// 確認和答案一不一致
bool checkAns(int showGrid[9][9], int ansGrid[9][9]) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (showGrid[i][j] != ansGrid[i][j]) {
                return false; // 有任何一個不一樣，就回傳失敗
            }
        }
    }
    return true;
    

}

