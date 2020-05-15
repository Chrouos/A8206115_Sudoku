#include"puzzleCheck.h"

PuzzleCheck::PuzzleCheck() {

}

//確認直、橫、區是否相加為45
bool PuzzleCheck::check(int grid[9][9]) {

    int checkHorizontal[9] = {};
    int checkStraight[9] = {};
    int checkThreeThree[9] = {};

    int k = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // 橫的加起來是45 
            checkHorizontal[i] += grid[i][j];
            // 直的加起來是45
            checkStraight[i] += grid[j][i];
            // 3*3加起來是45
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
//確認直的是否相加45
bool PuzzleCheck::checkStraight(int grid[9][9]) {

    int checkStraight[9] = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // 直的加起來是45
            checkStraight[i] += grid[j][i];
        }
        if (checkStraight[i] != 45) return false;
    }
    return true;

}
//確認橫的是否相加45
bool PuzzleCheck::checkHorizontal(int grid[9][9]){

    int checkHorizontal[9] = {};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // 橫的加起來是45 
            checkHorizontal[i] += grid[i][j];

        }
        if (checkHorizontal[i] != 45 )
            return false;
    }
    return true;
}
//確認區的是否相加45
bool PuzzleCheck::checkBlock(int grid[9][9]) {

    int checkThreeThree[9] = {};
    int k = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // 3*3加起來是45
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
    
    int row = count / 9;//第幾行
    int col = count % 9;//第幾個
   
    for (int i = 0; i < 9; i++) {
        //判斷橫的
        if (grid[row][col] == grid[row][i] && i != col) return false;
        //判斷直的
        else if (grid[row][col] == grid[i][col] && i != row) return false;
    }

    int areaRow = row / 3 * 3; // ex. 4/3*3=3, 7/3*3=6 做區塊
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

//確認數字 直的是否 1～9重複
bool PuzzleCheck::nReaptingStraight(int checkNumber, int count, int grid[9][9]) {

    int row = count / 9;//第幾行
    int col = count % 9;//第幾個

    for (int n = 0; n < 9; n++) {
        if (checkNumber == grid[n][col] && n != row)
            return false;
    }
    return true;
}
//確認數字 橫的是否 1～9重複
bool PuzzleCheck::nReaptingHorizontal(int checkNumber, int count, int grid[9][9]) {
    int row = count / 9;//第幾行
    int col = count % 9;//第幾個

    for (int n = 0; n < 9; n++) {
        if (checkNumber == grid[row][n] && n != col)
            return false;
    }
    return true;
}
//確認數字 區的是否 1～9重複
bool PuzzleCheck::nReaptingBlock(int checkNumber, int count, int grid[9][9]) {
    int row = count / 9;//第幾行
    int col = count % 9;//第幾個

    int areaRow = row / 3 * 3; // ex. 4/3*3=3, 7/3*3=6 做區塊
    int areaCol = col / 3 * 3;

    for (int i = areaRow; i < areaRow + 3; i++) {
        for (int j = areaCol; j < areaRow + 3; j++) {
            if (checkNumber == grid[row][col] && i != row && j != col) return false;
        }
    }
    return true;
}

//確認數字 直橫是否 1～9重複
bool PuzzleCheck::nReaptingCroner(int checkNumber, int count, int grid[9][9]) {
    int row = count / 9;//第幾行
    int col = count % 9;//第幾個

    for (int n = 0; n < 9; n++) {
        if (checkNumber == grid[row][n] && n != col)
            return true;
        if (checkNumber == grid[n][col] && n != row)
            return true;
    }
    return false;
}



