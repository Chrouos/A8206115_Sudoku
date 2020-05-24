#ifndef SloveSudoku_H
#define SloveSudoku_H

#include"grid.h"
#include"puzzleCheck.h"

class SloveSudoku
{
public:

	SloveSudoku();

	bool solve(int grid[9][9], int ansGrid[9][9]);
	
	int getAnsTimes();

private:

	const int SIZE = 9;
	static int ansTimes;

};

#endif // !SloveSudoku_H
