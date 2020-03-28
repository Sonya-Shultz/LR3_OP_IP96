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
	int kilkist = 0; //к-ть "вершн" нашого графа (пустих клітинок в лабіринті)
	int rebra = 0; //к-ть ребе неорграфа
	int sizeArr[2]; //масив розмірів

	int fileSize = sizeSearch(sizeArr);

	int xsize = sizeArr[1];
	int ysize = sizeArr[0]; //розміри лабіринта х і у відповідно
	int poch = 16, kin=4; //номери початкових і кінцевих вершин
	int** labir = new int* [xsize]; //Лабіринт перетворений за пунктом 3 у плані
	timeAdd(labir, xsize, ysize);
	coutFile(sizeArr, labir, fileSize); //вивід данних з файлу
	kilkist = fullGraf(labir, xsize, ysize);
	int* minvidstan = new int[kilkist]; //масив мінімальних відстаней
	int* predok = new int[kilkist]; //Щоб знайти шлях
	int* data = new int[200]; //щоб записати всi дуги в графі
	bool* usani = new bool[kilkist]; //Щоб знати чи ми вже проходили цю вершину
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

