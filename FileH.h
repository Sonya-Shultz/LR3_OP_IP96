#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void coutFile(int* sizeArr, int** labArr, int fileSize);
int sizeSearch(int* sizeArr);
void timeAdd(int** tempArr, int tempSize, int tempSizeTwo);
void ziroArr(int** tempArr, int tempSize, int tempSizeTwo);
void deleteBigArr(int** tempArr, int tempSize);
int enterSize(int** tempLabir, int rib, int col);