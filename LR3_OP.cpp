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

	int xsize = sizeArr[1];
	int ysize = sizeArr[0]; //������ �������� � � � ��������
	int poch = 16, kin=4; //������ ���������� � ������� ������
	int** labir = new int* [xsize]; //������� ������������ �� ������� 3 � ����
	timeAdd(labir, xsize, ysize);
	coutFile(sizeArr, labir, fileSize); //���� ������ � �����
	kilkist = fullGraf(labir, xsize, ysize);
	int* minvidstan = new int[kilkist]; //����� ��������� ��������
	int* predok = new int[kilkist]; //��� ������ ����
	int* data = new int[200]; //��� �������� ��i ���� � �����
	bool* usani = new bool[kilkist]; //��� ����� �� �� ��� ��������� �� �������
	rebra = read_data(data, labir, xsize, ysize);
	predok = zanul(predok,kilkist);
	Deikstra(data, poch, xsize, ysize, minvidstan, predok, kilkist, rebra, usani);
	for (int i = 0; i < kilkist; i++)
	{
		cout << predok[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < kilkist; i++)
	{
		cout << minvidstan[i] << " ";
	}
	cout << endl;
	delete[] minvidstan;
	delete[] predok;
	delete[] data;
	delete[] usani;
	deleteBigArr(labir, xsize);
}

