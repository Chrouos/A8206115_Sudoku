#ifndef grid_H
#define grid_H

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<ctime>
using namespace std;

class Grid
{
public:
	
	Grid();

	//�D�إͲ�
	void Generator();

	//��X
	void print();

	//�N�D���k�s
	void clear();
	//��J�Ʀr �Ӧh�N���s
	bool checkPutInGrid();

	int& operator[](int count);




private:

	int grid[9][9];

};



#endif // !grid_H
