#include "my_sort.h"

void swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//ѡ������
void selectSort(int arr[], int arrSize)
{
	int min = 0;//��ʼʱ��Сֵλ��
	for (int i = 0; i < arrSize - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < arrSize; ++j)
			if (arr[min] > arr[j])
				min = j;

		if (min != i)
			swap(arr[min], arr[i]);
	}
}

//��������
void insertSort(int arr[], int arrSize)
{
	int i, j;
	for (i = 1; i < arrSize; ++i)
	{
		int tmp = arr[i];
		for (j = i; j > 0 && tmp<arr[j-1]; --j)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

//ð������
void bubbleSort(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
	{
		for (int j = 1; j < arrSize - i; ++j)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

//ϣ������
void shellSort(int arr[], int arrSize)
{
	int step = arrSize / 2;//���ò���
	int i, j;
	int tmp;
	while (step >= 1)
	{
		for (i = step; i < arrSize; ++i)
		{
			tmp = arr[i];
			j = i - step;
			while (j > 0 && arr[j] > tmp)
			{
				arr[j + step] = arr[j];
				j -= step;
			}
			arr[j + step] = tmp;
		}
		step /= 2;
	}
}

//��������
void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int i = start;//��ʼλ��
	int j = end;//���һ��Ԫ�ص�λ��

	//��׼ֵ
	int tmp = arr[start];//����ʼλ��Ϊ��׼

	while (i < j)
	{
		while (i < j&&arr[j] >= tmp)
			j--;
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}

		while (i < j&&arr[i] < tmp)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}

	arr[i] = tmp;

	quickSort(arr, start, i - 1);
	quickSort(arr, i + 1, end);

}

//��������������a[first...mid]��a[mid+1...last]�ϲ���
void mergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;	// ��һ���������еĿ�ʼ�±�
	int j = mid + 1;	// ��2���������еĿ�ʼ�±�

	int length = 0;
	// �ϲ�������������
	while (i <= mid && j <= last)
	{
		// �Ҷ����бȽ�С����
		if (a[i] < a[j])
		{
			temp[length] = a[i];
			i++;
		}
		else
		{
			temp[length] = a[j];
			j++;
		}
		length++;
	}
	// ��ʣ��һ������������������
	while (i <= mid)
	{
		temp[length] = a[i];
		i++;
		length++;
	}
	while (j <= last)
	{
		temp[length++] = a[j++];
	}

	// ����ԭ��λ�õ���������
	for (int i = 0; i < length; ++i)
	{
		// �ҵ�ԭ�� �ĵ�һ���������еĿ�ʼλ�� - ��ʼ����
		a[first + i] = temp[i];
	}
}
//�鲢����
void mergeSort(int a[], int first, int last, int temp[])
{
	// �ݹ����������
	if (first == last)
	{
		return;
	}
	// ���м�λ�ò��
	int mid = (first + last) / 2;
	// ���
	// ����
	mergeSort(a, first, mid, temp);
	// �Ұ��
	mergeSort(a, mid + 1, last, temp);
	// �ϲ�������������
	mergeArray(a, first, mid, last, temp);
}

//������
void heapSort(int arr[], int arrSize)
{
	int heapSize = buildHeap(arr, arrSize);
	while (heapSize > 1)
	{
		swap(arr, 0, --heapSize);
		heap(arr, 0, heapSize);
	}

}
//����
int buildHeap(int arr[], int arrSize)
{
	int heapSize = arrSize;
	for (int i = heapSize / 2 - 1; i >= 0; i--)
		heap(arr, i, heapSize);
	return heapSize;
}
//��ָ���ڵ㿪ʼ���½��жѵ���
void heap(int arr[], int i, int size)
{
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 1;
	int max = i;

	if (leftChild<size&&arr[leftChild]>arr[max])
		max = leftChild;
	if (rightChild<size&&arr[rightChild]>arr[max])
		max = rightChild;
	if (max != i)
	{
		swap(arr, i, max);
		heap(arr, max, size);
	}
}