#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rusian");
	int kilkist; //к-ть "вершн" нашого графа (пустих клітинок в лабіринті)
	int rebra; //к-ть ребе неорграфа
	int xsize, ysize; //розміри лабіринта х і у відповідно
	int poch, kin; //номери початкових і кінцевих вершин
	int** labir = new int* [xsize]; //Лабіринт перетворений за пунктом 3 у плані
	kilkist = fullGraf(labir, xsize, ysize);
	int* minvidstan = new int[kilkist]; //масив мінімальних відстаней
	int* predok = new int[kilkist]; //Щоб знайти шлях
	int* data = new int[100]; //щоб записати всi дуги в графі
	bool* usani = new bool[kilkist]; //Щоб знати чи ми вже проходили цю вершину
	rebra = read_data(data, labir, xsize, ysize);
	Deikstra(data, poch, xsize, ysize, minvidstan, predok, kilkist, rebra, usani);
}

int fullGraf(int** labir, int xsize, int ysize)
{
	int kilkist = 0;
	for (int i = 0; i < xsize; i++)
	{
		for (int j = 0; j < ysize; j++)
		{
			if (labir[i][j] != -1) { kilkist++; labir[i][j] = kilkist; }
		}
	}
	return kilkist;
}

int read_data(int* data, int** labnom, int xsize, int ysize)
{
	int q = 0;
	for (int i = 1; i < xsize-1; i++)
	{
		for (int j = 1; j < ysize - 1; j++)
		{
			if (labnom[i][j] != -1)
			{
				if (labnom[i - 1][j] != -1) {
					data[q] = labnom[i][j]; data[q + 1] = labnom[i - 1][j]; q = q + 2;
				}
				if (labnom[i][j-1] != -1) {
					data[q] = labnom[i][j]; data[q + 1] = labnom[i][j-1]; q = q + 2;
				}
				if (labnom[i + 1][j] != -1) {
					data[q] = labnom[i][j]; data[q + 1] = labnom[i + 1][j]; q = q + 2;
				}
				if (labnom[i][j + 1] != -1) {
					data[q] = labnom[i][j]; data[q + 1] = labnom[i][j + 1]; q = q + 2;
				}
			}
		}
	}
	return q/2;
}

int* fulbignum(int* mas, int size)
{
	int max = 3000;
	for (int i = 0; i < size; i++)
	{
		mas[i] = max;
	}
	return mas;
}

int* zanul(int* mas, int size)
{
	for (int i = 0; i < size; i++) {mas[i] = 0;}
	return mas;
}

bool* ansNO(bool* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = false;
	}
	return mas;
}

int minserch(int*minvids, int size, bool* usani)
{
	int min = minvids[0];
	for (int i = 1; i < size; i++)
	{
		if (min > minvids[i] && !usani[i]) { min = i+1; }
	}
	return min;
}

void Deikstra(int* data, int poch, int xsize, int ysize, int* minvids, int* predok, int kilkist, int rebra, bool* usani)
{
	minvids = fulbignum(minvids, kilkist);
	usani = ansNO(usani, kilkist);
	minvids[poch-1] = 0;
	int ver0 = poch;
	predok[ver0-1] = 0;
	int* help = new int[kilkist];
	for (int i = 0; i < kilkist; i++)
	{
		int ver = minserch(minvids, kilkist, usani);
		predok[ver-1] = ver0;
		usani[ver - 1] = true;
		int j = serchall(data, ver, rebra*2, help);
		for (int i = 0; i < j;i++)
		{
			int ver2 = help[i];
			minvids[ver2-1] = min(minvids[ver2-1], minvids[ver-1]+1);
		}
		ver0 = ver;
	}
}

int min(int a, int b)
{
	if (a < b) { return a; }
	else { return b; }
}

int serchall(int * data, int ver, int size, int* help)
{
	int j = 0;
	for (int i = 0; i < size; i=i+2)
	{
		if (data[i] = ver)
		{
			help[j] = data[i + 1]; 
			j++;
		}
	}
	return j;
}

int A(int* data, int poch, int xsize, int ysize, int* minvids, int* predok, int kilkist, int rebra,  int kin, int**labir)
{
	vector <int> usana;
	vector <int> look;
	usana.push_back(poch);
	int* evrist = new int[kilkist];
	int* help = new int[kilkist];
	minvids[poch-1] = 0;
	evrist = fulbignum(evrist, kilkist);
	evrist[poch-1] = minvids[poch-1] + h(poch, labir, xsize, ysize, kin);
	while (!usana.empty())
	{
		int ver = verserch(usana, minvids);
		if (ver = kin) { return 1; }
		usana=remove(usana, ver);
		look.push_back(ver);
		int j = serchall(data, ver, rebra * 2, help);
		for (int i = 0; i < j; i++)
		{
			int v = help[j];
			int maylong = minvids[ver]+1;
			if (maylong < minvids[v] or !nal(look, v))
			{
				predok[v - 1] = ver;
				minvids[v - 1] = maylong;
				evrist[v - 1] = minvids[v - 1] + h(v, labir, xsize, ysize, kin);
				if (!nal(usana, v)) { usana.push_back(v); }
			}
		}
	}
	return 0;
}

bool nal(vector<int> look, int a)
{
	for (vector<int>::iterator it = look.begin(); it != look.end(); it++)
	{
		if (*it = a) { return true; }
	}
	return false;
}

vector <int> remove(vector<int> usana, int a)
{
	for (vector<int>::iterator it = usana.begin(); it != usana.end(); it++)
	{
		if (*it = a) { usana.erase(it); }
	}
	return usana;
}

int verserch(vector <int> usana, int* minvids)
{
	int min = 300, ver;
	for (vector<int>::iterator it = usana.begin(); it != usana.end(); it++)
	{
		if (min > minvids[*it-1]) { min = minvids[*it-1]; ver = *it; }
	}
	return ver;
}

int h(int poch, int** labir, int xsize, int ysize, int kin)
{
	int x1, x2, y1, y2;
	for (int i = 0; i < xsize; i++)
	{
		for (int j = 0; j < ysize; j++)
		{
			if (labir[i][j] == poch) { x1 = i, y1=j; }
			if (labir[i][j] == kin) { x2 = i, y2 = j; }
		}
	}
	int evr = abs(x1-x2)+abs(y1-y2);
	return evr;
}

int abs(int a)
{
	if (a >= 0) { return a; }
	else { return -a; }
}