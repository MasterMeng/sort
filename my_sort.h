#pragma once

//��ֵ����
void swap(int& a, int& b);
void swap(int arr[],int i,int j);

//ѡ������
void selectSort(int arr[], int arrSize);

//��������
void insertSort(int arr[], int arrSize);

//ð������
void bubbleSort(int arr[], int arrSize);

//ϣ������
void shellSort(int arr[], int arrSize);

//��������
void quickSort(int arr[],int start,int end);

//�鲢����
void mergeSort(int a[], int first, int last, int temp[]);
//��������������a[first...mid]��a[mid+1...last]�ϲ���
void mergeArray(int a[], int first, int mid, int last, int temp[]);

//������
void heapSort(int arr[], int arrSize);
//����
int buildHeap(int arr[], int arrSize);
//��ָ���ڵ㿪ʼ���½��жѵ���
void heap(int arr[], int i, int size);
