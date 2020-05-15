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

	//�T�{�Ʀr �����O�_ 1��9����
	bool nReaptingStraight(int checkNumber, int count, int grid[9][9]);
	//�T�{�Ʀr ��O�_ 1��9����
	bool nReaptingHorizontal(int checkNumber, int count, int grid[9][9]);
	//�T�{�Ʀr ����O�_ 1��9����
	bool nReaptingCroner(int checkNumber, int count, int grid[9][9]);
	//�T�{�Ʀr �Ϫ��O�_ 1��9����
	bool nReaptingBlock(int checkNumber, int count, int grid[9][9]);

	


private:


};



#endif // !PuzzleCheck_H
