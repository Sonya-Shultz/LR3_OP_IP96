#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;
#include "Deikstra.h"

int main()
{
	setlocale(LC_ALL, "Rusian");
	int kilkist = 0; //�-�� "�����" ������ ����� (������ ������� � �������)
	int rebra = 0; //�-�� ���� ���������
	int xsize = 0, ysize = 0; //������ �������� � � � ��������
	int poch = 0;
	int kin=0; //������ ���������� � ������� ������
	int** labir = new int* [xsize]; //������� ������������ �� ������� 3 � ����
	kilkist = fullGraf(labir, xsize, ysize);
	int* minvidstan = new int[kilkist]; //����� ��������� ��������
	int* predok = new int[kilkist]; //��� ������ ����
	int* data = new int[100]; //��� �������� ��i ���� � �����
	bool* usani = new bool[kilkist]; //��� ����� �� �� ��� ��������� �� �������
	rebra = read_data(data, labir, xsize, ysize);
	Deikstra(data, poch, xsize, ysize, minvidstan, predok, kilkist, rebra, usani);
	
	

}

