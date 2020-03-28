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
	int kilkist = 0; //к-ть "вершн" нашого графа (пустих клітинок в лабіринті)
	int rebra = 0; //к-ть ребе неорграфа
	int xsize = 0, ysize = 0; //розміри лабіринта х і у відповідно
	int poch = 0;
	int kin=0; //номери початкових і кінцевих вершин
	int** labir = new int* [xsize]; //Лабіринт перетворений за пунктом 3 у плані
	kilkist = fullGraf(labir, xsize, ysize);
	int* minvidstan = new int[kilkist]; //масив мінімальних відстаней
	int* predok = new int[kilkist]; //Щоб знайти шлях
	int* data = new int[100]; //щоб записати всi дуги в графі
	bool* usani = new bool[kilkist]; //Щоб знати чи ми вже проходили цю вершину
	rebra = read_data(data, labir, xsize, ysize);
	Deikstra(data, poch, xsize, ysize, minvidstan, predok, kilkist, rebra, usani);
	
	

}

