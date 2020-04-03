
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

	int xsize = sizeArr[1];//к-сть рядків в лабіринті
	int ysize = sizeArr[0]; //к-сть стовбців в лабіринті
	int poch = 16, kin = 4; //номери початкових і кінцевих вершин
	int** labir = new int* [xsize]; //Лабіринт
	timeAdd(labir, xsize, ysize);
	coutFile(sizeArr, labir, fileSize); //вивід данних з файлу
	kilkist = fullGraf(labir, xsize, ysize);

	cout << "Enter for first peak: " << endl;
	poch = enterSize(labir, xsize, ysize);

	cout << "Enter for end peak: " << endl;
	kin = enterSize(labir, xsize, ysize);

	int* minvidstan = new int[kilkist]; //масив мінімальних відстаней
	int* predok = new int[kilkist]; //Щоб знайти шлях
	int* data = new int[500]; //щоб записати всi дуги в графі
	bool* usani = new bool[kilkist]; //Щоб знати чи ми вже проходили цю вершину
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
		int count = countNoZirro(resultArr, kilkist);//к-сть вершин шляху
		writeInFile(labir, resultArr, count, xsize, ysize);
	}
	if (ans == 2) {
		int z = A(data, poch, xsize, ysize, minvidstan, predok, kilkist, rebra, kin, labir);
		if (z == 1) {
			int* resultArr = new int[kilkist];
			findPath(predok, resultArr, poch, kin);
			int count = countNoZirro(resultArr, kilkist);//к-сть вершин шляху
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

