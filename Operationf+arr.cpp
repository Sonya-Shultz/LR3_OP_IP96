#include "FileH.h"

void coutFile(int* sizeArr, int** labArr, int fileSize) {
	string path = "Data.txt";
	string str;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) { cout << "Can't open file "; }
	else {
		int size1 = 0;
		while (!fin.eof()) {
			getline(fin, str, '\n');
			int a = 0;
			for (int j = 0; j < fileSize; j = j + 2) {
				if (str[j] == 'x' && a < sizeArr[0]) { labArr[size1][a] = -1; a++; }
				else { labArr[size1][a] = 0; a++; }
			}
			size1++;
		}
		fin.close();
	}
}

void timeAdd(int** tempArr, int tempSize, int tempSizeTwo) {
	for (int i = 0; i < tempSize; i++) {
		tempArr[i] = new int[tempSizeTwo];
	}
}

void ziroArr(int** tempArr, int tempSize, int tempSizeTwo) {
	for (int i = 0; i < tempSize; i++) {
		for (int j = 0; j < tempSizeTwo; j++) {
			tempArr[i][j] = 0;
		}
	}
}

int sizeSearch(int* sizeArr) {
	string path = "Data.txt";
	string str;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) { cout << "Can't open file "; }
	else {
		int i = 0;
		int m = 0;
		int size = 0;
		while (!fin.eof()) {
			getline(fin, str, '\n');
			size = str.size();
			for (int j = 0; j < size; j++) {
				if (str[j] == 'x' && i == 0) { m++; }
			}
			i++;
		}
		sizeArr[1] = i;
		sizeArr[0] = m;
		fin.close();
		return size;
	}
}

void deleteBigArr(int** tempArr, int tempSize) {
	for (int i = 0; i < tempSize; i++) {
		delete[] tempArr[i];
	}
}