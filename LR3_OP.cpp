
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;
#include "Deikstra.h"
#include "FileH.h"

int main()
{
	setlocale(LC_ALL, "Rusian");
	int kilkist = 0; //�-�� "�����" ������ ����� (������ ������� � �������)
	int rebra = 0; //�-�� ���� ���������
	int sizeArr[2]; //����� ������

	int fileSize = sizeSearch(sizeArr);

	int xsize = sizeArr[1];//�-��� ����� � �������
	int ysize = sizeArr[0]; //�-��� �������� � �������
	int poch = 16, kin = 4; //������ ���������� � ������� ������
	int** labir = new int* [xsize]; //�������
	timeAdd(labir, xsize, ysize);
	coutFile(sizeArr, labir, fileSize); //���� ������ � �����
	kilkist = fullGraf(labir, xsize, ysize);

	cout << "Enter for first peak: " << endl;
	poch = enterSize(labir, xsize, ysize);

	cout << "Enter for end peak: " << endl;
	kin = enterSize(labir, xsize, ysize);

	int* minvidstan = new int[kilkist]; //����� ��������� ��������
	int* predok = new int[kilkist]; //��� ������ ����
	int* data = new int[500]; //��� �������� ��i ���� � �����
	bool* usani = new bool[kilkist]; //��� ����� �� �� ��� ��������� �� �������
	rebra = read_data(data, labir, xsize, ysize);
	int ans;
	cout << "Choose type of sort (1-Dijkstra`s, 2-A*): \n";
	cin >> ans;
	while (ans != 1 && ans != 2)
	{
		cout << "Choose type of sort (1-Dijkstra`s, 2-A*): \n";
		cin >> ans;
	}
	if (ans == 1) {
		Deikstra(data, poch, xsize, ysize, minvidstan, predok, kilkist, rebra, usani);
		int* resultArr = new int[kilkist];
		findPath(predok, resultArr, poch, kin);
		int count = countNoZirro(resultArr, kilkist);//�-��� ������ �����
		writeInFile(labir, resultArr, count, xsize, ysize);
	}
	if (ans == 2) {
		int z = A(data, poch, xsize, ysize, minvidstan, predok, kilkist, rebra, kin, labir);
		if (z == 1) {
			int* resultArr = new int[kilkist];
			findPath(predok, resultArr, poch, kin);
			int count = countNoZirro(resultArr, kilkist);//�-��� ������ �����
			writeInFile(labir, resultArr, count, xsize, ysize);
		}
		else { cout << "No way!"; }
	}
	delete[] minvidstan;
	delete[] predok;
	delete[] data;
	delete[] usani;
	deleteBigArr(labir, xsize);
}

