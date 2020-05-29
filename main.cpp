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
    //�e��l
    cout << "   " << "0 " << "1 " << "2   " << "3 " << "4 " << "5   " << "6 " << "7 " << "8 " << endl; //��m�s��
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) cout << " |-----------------------" << endl;
        for (int j = 0; j < 9; j++) {
            if (j==0) cout << i << "| ";
            else if (j!=0 && j % 3 == 0) cout << "| ";
            cout << showGrid[i][j] << " ";
        }
        cout << endl;
    }

    //�p�g���r���s��
    /*
    �ƿW�����üƦ����D
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

    //�P�_�ζ�J�Ʀr
    PuzzleCheck p;

    while (p.check(showGrid) == false) {//�P�_����ϬO�_�ۥ[��45
        cout << "Did not enter all digits in 1~9.Please enter the complete 1~9 ";//����J0~9���Ҧ��Ʀr �п�J���㪺0~9
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (showGrid[i][j] == 0) {
                    int input;
                    cout << "in(" << i << "," << j << "): ";
                    cin >> input;
                    showGrid[i][j] = input;//�N�Ʀr��J
                    if (p.nReaptingBlock(input, 9*i+j, showGrid) == false || p.nReaptingCroner(input, 9*i+j, showGrid) == true) {//�P�_���Ʀr�O�_����
                        showGrid[i][j] == 0;
                        cout << "This number is repeated.Please enter a new number: ";//�o�ӼƦr���ƤF �п�J�@�ӷs���Ʀr
                        break;
                    }
                    else {
                        for (int i = 0; i < 9; i++) {
                            if (i % 3 == 0) cout << "---------------------" << endl;
                            for (int j = 0; j < 9; j++) {
                                if (j != 0 && j % 3 == 0) cout << "| ";
                                cout << showGrid[i][j] << " "; //�L�X�̷s����
                            }
                            cout << endl;
                        }
                    }
                    cout << "Enter a number: ";
                }
            }
        }
    }

    SloveSudoku S;

    system("pause");
    return 0;
}