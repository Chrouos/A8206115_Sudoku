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

	//題目生產
	void Generator();

	//輸出
	void print();

	//將題目歸零
	void clear();
	//填入數字 太多就重新
	bool checkPutInGrid();

	int& operator[](int count);




private:

	int grid[9][9];

};



#endif // !grid_H
