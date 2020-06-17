#include<iostream>
#include"grid.h"
#include"puzzleCheck.h"
#include"sloveSudoku.h"
#include"dig.h"
#include<ctime>
using namespace std;

bool outOf(int num) {
	if (num == -1) {
		cout << "�A��J�F-1,�Y�N���s���s��J" << endl;
		system("pause");
		system("CLS");
		return false;
	}
	return true;
}

//�P�_�ƿW���O�_�٦��Ů�
bool BlankCheck(int showGrid[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (showGrid[i][j] == 0) return false;
		}
	}
}

//�e��l�ΦL�X
void lattice(int showGrid[9][9]) {
	cout << "    " << "0 " << "1 " << "2   " << "3 " << "4 " << "5   " << "6 " << "7 " << "8 " << endl; //��m�s��
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) cout << "  �X�X�X�X�X�X�X�X�X�X�X�X" << endl;
		for (int j = 0; j < 9; j++) {
			if (j == 0) cout << i << " | ";
			else if (j != 0 && j % 3 == 0) cout << "| ";
			cout << showGrid[i][j] << " ";
		}
		cout << endl;
	}
	cout << "  �X�X�X�X�X�X�X�X�X�X�X�X" << endl;
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

	cout << "���o���o�A�w��A�}�ҤF�o�ӡu�ƿW�p�C���v�A�H�U���C�������γW�h������\n\n"
		<< "����:\n�C���ت����N9x9������񺡼Ʀr\n���C�@��B�C�@�C�ΨC�@��3x3����������񺡼Ʀr\n0���Ů��ܻݭn��J�Ʀr����m\n\n"
		<< "�W�h:\n�u���J1��9�������Ʀr�B���୫��\n\n"
		<< "�I��Enter�K�}�l�C���@!!!";

	cin.ignore(); //�Ȱ�����A����

	Dig D;
	D.dig_simple(showGrid);

	clock_t start, stop; //�ŧi�p�ɾ�
	start = clock(); //�p�ɾ��}�l

	//print
	while (BlankCheck(showGrid) == false) {

		system("CLS");
		lattice(showGrid);

		//�ϥΪ̿�J��m
		int x, y, number;
		cout << "�п�J�z�n��J�Ʀr�������m(��J-1�i���s��J��m): ";
		cin >> x;
		if (outOf(x) == false) continue;

		cout << "�п�J�z�n��J�Ʀr���W���m(��J-1�i���s��J��m): ";
		cin >> y;
		//�P�_��J�̿�J����m�O�_��0
		if (outOf(y) == false) continue;
		if (showGrid[x][y] != 0) {
			cout << "�z��J����m���D��,���i���,�Э��s��J��m" << endl;
			system("pause");
			continue;
		}

		cout << "�п�J�n��諸�Ʀr(��J-1�i���s��J��m): ";
		cin >> number;

		PuzzleCheck pc;
		while (pc.nReaptingCroner(number, 9 * x + y, showGrid) == true || pc.nReaptingBlock(number, 9 * x + y, showGrid) == false
			|| number == -1 || number < 0 || number > 9) {
			cout << "���Ʀr�O���~��~�д��ӼƦr�A����J" << endl;
			cout << "�п�J�n��諸�Ʀr: ";
			cin >> number;
		}
		if (outOf(number) == false) continue;

		showGrid[x][y] = number;
	}

	stop = clock();//�p�ɾ�����
	cout << "���ߧA�����F�����u�ƿW�p�C���v\n"
		<< "�A�`�@�C���F: " << double(stop - start) / CLOCKS_PER_SEC << "��!\n" //�L�X�p�ɾ����ɶ�
		<< "�I��Enter��i��o����p§����!!!" << endl;
	cin.ignore();
	cout << "�ᨺ��[ �p���! ���ئA�D�Ԥ@���r OuOb" << endl;

	system("pause");
	return 0;
}
