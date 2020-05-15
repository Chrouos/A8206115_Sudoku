#ifndef PuzzleCheck_H
#define PuzzleCheck_H

#include"grid.h"

class PuzzleCheck
{
public:

	PuzzleCheck();

	bool check(int grid[9][9]);
	bool checkStraight(int grid[9][9]);
	bool checkHorizontal(int grid[9][9]);
	bool checkBlock(int grid[9][9]);
	bool countCheck(int count, int grid[9][9]);

	//確認數字 直的是否 1～9重複
	bool nReaptingStraight(int checkNumber, int count, int grid[9][9]);
	//確認數字 橫的是否 1～9重複
	bool nReaptingHorizontal(int checkNumber, int count, int grid[9][9]);
	//確認數字 直橫是否 1～9重複
	bool nReaptingCroner(int checkNumber, int count, int grid[9][9]);
	//確認數字 區的是否 1～9重複
	bool nReaptingBlock(int checkNumber, int count, int grid[9][9]);

	


private:


};



#endif // !PuzzleCheck_H
