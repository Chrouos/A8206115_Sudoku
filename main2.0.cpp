#include<iostream>
#include"grid.h"
#include"puzzleCheck.h"
#include"sloveSudoku.h"
#include"dig.h"
using namespace std;

//�P�_�ƿW���O�_�٦��Ů�
bool BlankCheck(int showGrid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (showGrid[i][j] == 0) return false;
        }
    }
}

//�L�X�ƿW�����̷s�Ʀr
void print(int showGrid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << showGrid[i][j];
        }
        cout << endl;
    }
}

//�e��l
void lattice(int showGrid[9][9]) {
    cout << "  x" << "0 " << "1 " << "2   " << "3 " << "4 " << "5   " << "6 " << "7 " << "8 " << endl; //��m�s��
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

    //GRID �ഫ�� INT
    int grid[9][9];
    for (int i = 0; i < 81; i++) {
        int row = i / 9;//�ĴX��
        int col = i % 9;//�ĴX��
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
        //�ϥΪ̿�J��m
        int x, y;
        cout << "�п�J�z�n��J�Ʀr��x�b��m: ";
        cin >> x;
        cout << "�п�J�z�n��J�Ʀr��y�b��m: ";
        cin >> y;
        //�P�_��J�̿�J����m�O�_��0
    }

    SloveSudoku S;

    system("pause");
    return 0;
}