#include <iostream>

#include "my_sort.h"

#include <windows.h>
#include <profileapi.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int ARRSIZE = 30000;

void show(int *arr, int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main(int argc, char* argv[])
{
	LARGE_INTEGER freq;
	LARGE_INTEGER start;
	LARGE_INTEGER end;

	int i, j;
	double diff;
	int arr[6][ARRSIZE];

	srand((unsigned)time(NULL));
	for (i = 0; i < 6; ++i)
	{
		for (j = 0; j < ARRSIZE; ++j)
			arr[i][j] = rand() % ARRSIZE;
	}

	QueryPerformanceCounter(&freq);

	//ð������
	QueryPerformanceCounter(&start);
	bubbleSort(arr[0], ARRSIZE);
	QueryPerformanceCounter(&end);
	diff = (double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
	cout << "ð��������ʱ" << diff << "s" << endl;
	//show(arr[0], ARRSIZE);

	//ѡ������
	QueryPerformanceCounter(&start);
	selectSort(arr[1], ARRSIZE);
	QueryPerformanceCounter(&end);
	diff = (double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
	cout << "ѡ��������ʱ" << diff << "s" << endl;
	//show(arr[1], ARRSIZE);

	//��������
	QueryPerformanceCounter(&start);
	insertSort(arr[2], ARRSIZE);
	QueryPerformanceCounter(&end);
	diff = (double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
	cout << "����������ʱ" << diff << "s" << endl;
	//show(arr[2], ARRSIZE);

	//ϣ������
	QueryPerformanceCounter(&start);
	shellSort(arr[3], ARRSIZE);
	QueryPerformanceCounter(&end);
	diff = (double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
	cout << "ϣ��������ʱ" << diff << "s" << endl;
	//show(arr[3], ARRSIZE);

	//��������
	QueryPerformanceCounter(&start);
	quickSort(arr[4], 0,ARRSIZE-1);
	QueryPerformanceCounter(&end);
	diff = (double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
	cout << "����������ʱ" << diff << "s" << endl;
	//show(arr[4], ARRSIZE);

	system("pause");
	return 0;
}