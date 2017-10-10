#pragma once

//两值交换
void swap(int& a, int& b);
void swap(int arr[],int i,int j);

//选择排序
void selectSort(int arr[], int arrSize);

//插入排序
void insertSort(int arr[], int arrSize);

//冒泡排序
void bubbleSort(int arr[], int arrSize);

//希尔排序
void shellSort(int arr[], int arrSize);

//快速排序
void quickSort(int arr[],int start,int end);

//归并排序
void mergeSort(int a[], int first, int last, int temp[]);
//将两个有序数列a[first...mid]和a[mid+1...last]合并。
void mergeArray(int a[], int first, int mid, int last, int temp[]);

//堆排序
void heapSort(int arr[], int arrSize);
//建堆
int buildHeap(int arr[], int arrSize);
//从指定节点开始向下进行堆调整
void heap(int arr[], int i, int size);
