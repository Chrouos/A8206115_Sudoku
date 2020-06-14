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

    Grid ansGrid; // �� Grid ���㪩 = ����

    //GRID �ഫ�� INT
    int grid[9][9];
    for (int i = 0; i < 81; i++) {
        int row = i / 9;//�ĴX��
        int col = i % 9;//�ĴX��
        grid[row][col] = ansGrid[i];
    }

    //�s�@�@�����ϥζ�J�� (ShowGrid = ��ܦb�e���W���ѽL)
    int showGrid[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            showGrid[i][j] = grid[i][j];
        }
    }

    Dig D; // ���Ū���I�s
    D.dig_simple(showGrid); // �� showGrid�i�����


    PuzzleCheck P;

    // �C���}�l�e����
    cout << "���o���o�A�w��A�}�ҤF�o�ӡu�ƿW�p�C���v�A�H�U���C������!!\n\n"
        << "�����G\n�C���ت����N 9x9 ������񺡼Ʀr\n���C�@��B�C�@�C�ΨC�@�� 3x3 ��������A?��1��9���Ʀr�A���i���ơC"
        << "�I�� Enter �K�}�l�C���@!! \n\n";
    system("pause");

    char xNum;
    int yNum, ansNumber; // X����b��m�AY���ݶb��m�AansNumber
    bool checkDownTheGame = false;
    while (checkDownTheGame != true) {

        system("CLS");
        ShowBoard(showGrid);

        cout << "�ж�J�Q��J�Ʀr����m�A�p(5A, 6C, 9I...)\n�Х���J�����m( 1 ~ 9 ): ";
        cin >> yNum;
        cout << "�ж�J�Q��J�Ʀr����m�A�p(5A, 6C, 9I...)\n�Х���J�W���m( A ~ I ): ";
        cin >> xNum;

        if (returnX(xNum) == -1 || yNum < 0 || yNum>9) {
            cout << "�A��J���Ʀr���A�d��" << endl;
            system("pause");
            system("CLS");
            continue;
        }

        cout << "�п�J�A�Q��J���� ( 1 ~ 9 ): ";
        cin >> ansNumber;

        int count = (yNum - 1) * 9 + returnX(xNum);
        if (showGrid[yNum - 1][returnX(xNum)] == 0 && P.nReaptingCroner(ansNumber, count, showGrid) == false 
            && P.nReaptingBlock(ansNumber, count, showGrid) == true) 
            showGrid[yNum - 1][returnX(xNum)] = ansNumber;  // �N�Ʀr��J�i�h

        else if (P.nReaptingCroner(ansNumber, count, showGrid) != false
            || P.nReaptingBlock(ansNumber, count, showGrid) != true) {
            cout << "��J���Ʀr�w����" << endl;
            system("pause");
            system("CLS");
            continue;
        }

        else {
            cout << "���i��J�w���Ʀr���a��" << endl;
            system("pause");
            system("CLS");
            continue; 
        }
        
        checkDownTheGame = checkNumDown(showGrid);  // �T�{�Ʀr���S����J����

    }

    system("CLS");
    ShowBoard(showGrid);
    
    if (checkAns(showGrid, grid) == true) { // �p�G���פ@�P
        cout << "���ߧA!!!! �o�O���ѡC";
    }
    else {
        cout << "�ܥi���A�A��F�C";
    }

    cout << "���Ѭ�: " << endl << endl;

    ShowBoard(grid);
    
    
    system("pause");
    return 0;
}


// �s�@�ѽL(���榡)���I�s
void ShowBoard(int grid[9][9]) {

    cout << "    A B C   D E F   G H I" << endl;
    int topicNum = 1;
    for (int i = 0; i < 9; i++) {       
        if (i % 3 == 0) { // 0, 2, 5, 8 �ɵe -------
            cout << "  �ССССССССССС�" << endl;
        }
        cout << topicNum++ << " ";
        for (int j = 0; j < 9; j++) {
            if ( j % 3 == 0 ) cout << "| ";
            
            cout << grid[i][j] << " ";
        }     
        cout << "|" << endl;
        
    }
    cout << "  �ССССССССССС�" << endl;


}

// �P�_�O�_������
bool checkNumDown(int grid[9][9]) {
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) return false; //�^�� false �N���٨S��
        }
    }
    return true; // �^�� true �N��񧹤F

}

// �N A ~ I �ର 0 ~ 9
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

// �T�{�M���פ@���@�P
bool checkAns(int showGrid[9][9], int ansGrid[9][9]) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (showGrid[i][j] != ansGrid[i][j]) {
                return false; // ������@�Ӥ��@�ˡA�N�^�ǥ���
            }
        }
    }
    return true;
    

}

