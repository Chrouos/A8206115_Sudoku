#include"puzzleCheck.h"

PuzzleCheck::PuzzleCheck() {

}

//�T�{���B��B�ϬO�_�ۥ[��45
bool PuzzleCheck::check(int grid[9][9]) {

    int checkHorizontal[9] = {};
    int checkStraight[9] = {};
    int checkThreeThree[9] = {};

    int k = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // ��[�_�ӬO45 
            checkHorizontal[i] += grid[i][j];
            // �����[�_�ӬO45
            checkStraight[i] += grid[j][i];
            // 3*3�[�_�ӬO45
            if (j <= 2)
                checkThreeThree[k] += grid[i][j];
            else if (j <= 5)
                checkThreeThree[k + 1] += grid[i][j];
            else if (j <= 8)
                checkThreeThree[k + 2] += grid[i][j];

        }
        if (checkHorizontal[i] != 45 || checkStraight[i] != 45 || checkThreeThree[i] != 45)
            return false;

        if (i == 2 || i == 5 || i == 8)
            k += 3;
    }
    return true;
}
//�T�{�����O�_�ۥ[45
bool PuzzleCheck::checkStraight(int grid[9][9]) {

    int checkStraight[9] = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // �����[�_�ӬO45
            checkStraight[i] += grid[j][i];
        }
        if (checkStraight[i] != 45) return false;
    }
    return true;

}
//�T�{��O�_�ۥ[45
bool PuzzleCheck::checkHorizontal(int grid[9][9]){

    int checkHorizontal[9] = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // ��[�_�ӬO45 
            checkHorizontal[i] += grid[i][j];

        }
        if (checkHorizontal[i] != 45 )
            return false;
    }
    return true;
}
//�T�{�Ϫ��O�_�ۥ[45
bool PuzzleCheck::checkBlock(int grid[9][9]) {

    int checkThreeThree[9] = {};
    int k = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // 3*3�[�_�ӬO45
            if (j <= 2)
                checkThreeThree[k] += grid[i][j];
            else if (j <= 5)
                checkThreeThree[k + 1] += grid[i][j];
            else if (j <= 8)
                checkThreeThree[k + 2] += grid[i][j];

        }
        if (checkThreeThree[i] != 45)
            return false;
        if (i == 2 || i == 5 || i == 8)
            k += 3;
    }
    return true;
}

bool PuzzleCheck::countCheck(int count, int grid[9][9]) {
    
    int row = count / 9;//�ĴX��
    int col = count % 9;//�ĴX��
   
    for (int i = 0; i < 9; i++) {
        //�P�_�
        if (grid[row][col] == grid[row][i] && i != col) return false;
        //�P�_����
        else if (grid[row][col] == grid[i][col] && i != row) return false;
    }

    int areaRow = row / 3 * 3; // ex. 4/3*3=3, 7/3*3=6 ���϶�
    int areaCol = col / 3 * 3; 
    //ex. areaRow = 0, i=0; i<3;  0~2
    //ex. areaCol = 7, i=2; j<6;  2~5
    for (int i = areaRow; i < areaRow + 3; i++) {
        for (int j = areaCol; j < areaRow + 3; j++) {
            if (grid[i][j] == grid[row][col] && i != row && j != col) return false;
        }
    }
    return true;

}

//�T�{�Ʀr �����O�_ 1��9����
bool PuzzleCheck::nReaptingStraight(int checkNumber, int count, int grid[9][9]) {

    int row = count / 9;//�ĴX��
    int col = count % 9;//�ĴX��

    for (int n = 0; n < 9; n++) {
        if (checkNumber == grid[n][col] && n != row)
            return false;
    }
    return true;
}
//�T�{�Ʀr ��O�_ 1��9����
bool PuzzleCheck::nReaptingHorizontal(int checkNumber, int count, int grid[9][9]) {
    int row = count / 9;//�ĴX��
    int col = count % 9;//�ĴX��

    for (int n = 0; n < 9; n++) {
        if (checkNumber == grid[row][n] && n != col)
            return false;
    }
    return true;
}
//�T�{�Ʀr �Ϫ��O�_ 1��9����
bool PuzzleCheck::nReaptingBlock(int checkNumber, int count, int grid[9][9]) {
    int row = count / 9;//�ĴX��
    int col = count % 9;//�ĴX��

    int areaRow = row / 3 * 3; // ex. 4/3*3=3, 7/3*3=6 ���϶�
    int areaCol = col / 3 * 3;

    for (int i = areaRow; i < areaRow + 3; i++) {
        for (int j = areaCol; j < areaRow + 3; j++) {
            if (checkNumber == grid[row][col] && i != row && j != col) return false;
        }
    }
    return true;
}

//�T�{�Ʀr ����O�_ 1��9����
bool PuzzleCheck::nReaptingCroner(int checkNumber, int count, int grid[9][9]) {
    int row = count / 9;//�ĴX��
    int col = count % 9;//�ĴX��

    for (int n = 0; n < 9; n++) {
        if (checkNumber == grid[row][n] && n != col)
            return true;
        if (checkNumber == grid[n][col] && n != row)
            return true;
    }
    return false;
}



