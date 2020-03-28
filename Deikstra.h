#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std; 

int fullGraf(int** labir, int xsize, int ysize);
int read_data(int* data, int** labnom, int xsize, int ysize);
int* fulbignum(int* mas, int size);
int* zanul(int* mas, int size);
bool* ansNO(bool* mas, int size);
int minserch(int* minvids, int size, bool* usani);
void Deikstra(int* data, int poch, int xsize, int ysize, int* minvids, int* predok, int kilkist, int rebra, bool* usani);
int min(int a, int b);
int serchall(int* data, int ver, int size, int* help);
int A(int* data, int poch, int xsize, int ysize, int* minvids, int* predok, int kilkist, int rebra, int kin, int** labir);
bool nal(vector<int> look, int a);
vector <int> remove(vector<int> usana, int a);
int verserch(vector <int> usana, int* minvids);
int h(int poch, int** labir, int xsize, int ysize, int kin);
int abs(int a);

