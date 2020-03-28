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
	int kilkist = 0; //к-ть "вершн" нашого графа (пустих кл≥тинок в лаб≥ринт≥)
	int rebra = 0; //к-ть ребе неорграфа
	int sizeArr[2]; //масив розм≥р≥в

	int fileSize = sizeSearch(sizeArr);

	int xsize = sizeArr[1];//к-сть р€дк≥в в лаб≥ринт≥
	int ysize = sizeArr[0]; //к-сть стовбц≥в в лаб≥ринт≥
	int poch = 16, kin=4; //номери початкових ≥ к≥нцевих вершин
	int** labir = new int* [xsize]; //Ћаб≥ринт
	timeAdd(labir, xsize, ysize);
	coutFile(sizeArr, labir, fileSize); //вив≥д данних з файлу
	kilkist = fullGraf(labir, xsize, ysize);

	cout << "Enter for first peak: "<<endl;
	poch =enterSize(labir, xsize, ysize);

	cout << "Enter for end peak: "<<endl;
	kin = enterSize(labir, xsize, ysize);

	int* minvidstan = new int[kilkist]; //масив м≥н≥мальних в≥дстаней
	int* predok = new int[kilkist]; //ўоб знайти шл€х
	int* data = new int[200]; //щоб записати всi дуги в граф≥
	bool* usani = new bool[kilkist]; //ўоб знати чи ми вже проходили цю вершину
	rebra = read_data(data, labir, xsize, ysize);
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

