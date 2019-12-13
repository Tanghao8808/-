#pragma once
#include<stdio.h>
#include<windows.h>

void printf_array(int array[], int size)
{
	for (int i = 0; i < size; i++) {
	
		printf("%d\t", array[i]);
	}
}
//插入排序：分为直接插入排序和希尔排序，插入排序适用于数据量比较小，并且接近有序的时候
//直接插入排序
//时间复杂度：
//最好：o(n)  平均：o(n^2） 最坏：o(n^2)
//空间复杂度：o（1）
//稳定
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++) {

		int k = array[i];
		int j = 0;
		for (j = i - 1; j >= 0 ; j--) {
		
			if(array[j] <= k)
				break;
			else
				array[j+1] = array[j];

		}
		array[j + 1] = k;  //j == -1
	}
}

//希尔排序就是，就是在快排之前分组插排，做预处理，
//让数据尽可能的有序
void InsertSortwithGap(int array[], int size,int gap)
{
	for (int i = gap; i < size; i++) {

		int k = array[i];
		int j = 0;
		for (j = i - gap; j >= 0 && array[j] > k; j-=gap) {

			array[j + gap] = array[j];
		}
		array[j + gap] = k;
	}
}
//时间复杂度：
//最好：o(n)  平均：o(n^1.2 - n^1.3） 最坏：o(n^2) 遇到最环情况的概率小
//空间复杂度：o（1）
//不稳定 （相同数字不能保证分到同一个组里）
void ShellSort(int array[], int size) {

	int gap = size;
	while (1) {
		gap = (gap / 3) + 1;
		InsertSortwithGap(array, size, gap);
		if (gap == 1) {
			
				break;
		}
	}
}
void swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}
//选择排序：分为直接选择排序，堆排序，都是对数据顺序不敏感的，即无论是有序，乱序，逆序都是O(n)
//直接选择排序：O(n^2)  无论什么情况下的数据，都是O(n^2) 
//空间复杂度：O(1)
//不稳定
void SelectSort(int array[], int size) {

	for (int i = 0; i < size; i++) {

		int min = i; //最小数的下标 
		for (int j = i + 1; j < size; j++) {

			if (array[min] > array[j]) {
				min = j;
			}
		}
		swap(array + i, array + min);

	}
}

//选择排序的优化版：每次把最大和最小的都找出来
//O(n^2)
void SelectSortOP(int array[], int size) {
	int minspace = 0;
	int maxspace = size - 1;
	while (minspace < maxspace)
	{
		int min = minspace;
		int max = minspace;
		
		for (int i = minspace + 1; i <= maxspace; i++) {
			if (array[min] > array[i]) {
				min = i;
			}
			if (array[max] < array[i]) {
				max = i;
			}

		}
		swap(array + min, array + minspace);
		if (max == minspace) //这里需要注意
			max = min;
		swap(array + max, array + maxspace);
		minspace++;
		maxspace--;
	}
}



//堆排序
//排升序：建大堆
//O(n*lg(n))
//O(1)
//不稳定

void AdjustDown(int* array, int size, int root)
{
	while (1)
	{
		int left = 2 * root + 1;
		int right = 2 * root + 2;
		if (left >= size)  //没有左孩子就是叶子节点
			return;
		int max = left;
		if (right < size && array[right] > array[left])
			max = right;
		if (array[max] <= array[root])
			return;
		swap(&array[root], &array[max]);
		root = max;
	}
}
void CreateHeap(int* array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}
void HeapSort(int* array,int size)
{
	CreateHeap(array, size);
	for (int i = 0; i < size - 1; i++)
	{
		swap(&array[0], &array[size - 1 - i]);
		AdjustDown(array, size-1-i, 0);
	}
}

//冒泡排序：
//最好：O(n),有序
//最坏和平均：O(n^2)
//稳定
void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int is_sort = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				is_sort = 0;
			}
		}
		if (is_sort == 1)
			return;
	}
}



//快速排序
int Partition_1(int* array, int left, int right)  //hoare法（左右拉帘子，拉不动了就交换）
{
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && array[begin] < array[right])
		{
			begin++;
		}
		while (begin<end && array[end] > array[right])
		{
			end--;
		}
		swap(&array[begin], &array[end]);

	}
	swap(&array[begin], &array[right]);
	return begin;
}
int Partition_2(int* array, int left, int right)   //挖坑法
{
	int begin = left;
	int end = right;
	int pivot = array[right];  //选最右处为基准值，将基准值记住，right处就为坑
	while (begin < end)
	{
		while (begin < end && array[begin] <= pivot)
		{
			begin++;
		}
		array[end] = array[begin]; //填坑，begin处为坑
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;
	return begin;
}
int Partition_3(int* array, int left, int right) //前后下标法
{
	int d = left;
	for(int i = left; i < right; i++)
	{
		if (array[i] < array[right])
		{
			swap(array + i, array + d);
			d++;
		}
	}
	swap(array + d, array + right);
	return d;
}
void _QuickSort(int* array, int left, int right)
{

	if (left >= right)  //当区间里只有一个数或者没有数了，排序就结束了
		return;
	int div;  //基准值所在的下标
	div = Partition_3(array,left,right); //比基准值小的放在左边，比基准值大的放在基准值的右边
	_QuickSort(array, 0, div - 1);
	_QuickSort(array, div + 1, right);
}
void QuickSort(int* array, int size)
{
	_QuickSort(array, 0, size - 1);
}