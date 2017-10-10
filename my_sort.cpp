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

//选择排序
void selectSort(int arr[], int arrSize)
{
	int min = 0;//初始时最小值位置
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

//插入排序
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

//冒泡排序
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

//希尔排序
void shellSort(int arr[], int arrSize)
{
	int step = arrSize / 2;//设置步长
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

//快速排序
void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int i = start;//起始位置
	int j = end;//最后一个元素的位置

	//基准值
	int tmp = arr[start];//以起始位置为基准

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

//将两个有序数列a[first...mid]和a[mid+1...last]合并。
void mergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;	// 第一个有序序列的开始下标
	int j = mid + 1;	// 第2个有序序列的开始下标

	int length = 0;
	// 合并两个有序序列
	while (i <= mid && j <= last)
	{
		// 找二者中比较小的数
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
	// 还剩下一个有序序列中有数据
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

	// 覆盖原来位置的无序序列
	for (int i = 0; i < length; ++i)
	{
		// 找到原来 的第一个有序序列的开始位置 - 开始覆盖
		a[first + i] = temp[i];
	}
}
//归并排序
void mergeSort(int a[], int first, int last, int temp[])
{
	// 递归结束的条件
	if (first == last)
	{
		return;
	}
	// 从中间位置拆分
	int mid = (first + last) / 2;
	// 拆分
	// 左半边
	mergeSort(a, first, mid, temp);
	// 右半边
	mergeSort(a, mid + 1, last, temp);
	// 合并两个有序序列
	mergeArray(a, first, mid, last, temp);
}

//堆排序
void heapSort(int arr[], int arrSize)
{
	int heapSize = buildHeap(arr, arrSize);
	while (heapSize > 1)
	{
		swap(arr, 0, --heapSize);
		heap(arr, 0, heapSize);
	}

}
//建堆
int buildHeap(int arr[], int arrSize)
{
	int heapSize = arrSize;
	for (int i = heapSize / 2 - 1; i >= 0; i--)
		heap(arr, i, heapSize);
	return heapSize;
}
//从指定节点开始向下进行堆调整
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