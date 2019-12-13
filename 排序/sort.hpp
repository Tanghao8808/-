#pragma once
#include<stdio.h>
#include<windows.h>

void printf_array(int array[], int size)
{
	for (int i = 0; i < size; i++) {
	
		printf("%d\t", array[i]);
	}
}
//�������򣺷�Ϊֱ�Ӳ��������ϣ�����򣬲��������������������Ƚ�С�����ҽӽ������ʱ��
//ֱ�Ӳ�������
//ʱ�临�Ӷȣ�
//��ã�o(n)  ƽ����o(n^2�� ���o(n^2)
//�ռ临�Ӷȣ�o��1��
//�ȶ�
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

//ϣ��������ǣ������ڿ���֮ǰ������ţ���Ԥ����
//�����ݾ����ܵ�����
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
//ʱ�临�Ӷȣ�
//��ã�o(n)  ƽ����o(n^1.2 - n^1.3�� ���o(n^2) ���������ĸ���С
//�ռ临�Ӷȣ�o��1��
//���ȶ� ����ͬ���ֲ��ܱ�֤�ֵ�ͬһ�����
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
//ѡ�����򣺷�Ϊֱ��ѡ�����򣬶����򣬶��Ƕ�����˳�����еģ�����������������������O(n)
//ֱ��ѡ������O(n^2)  ����ʲô����µ����ݣ�����O(n^2) 
//�ռ临�Ӷȣ�O(1)
//���ȶ�
void SelectSort(int array[], int size) {

	for (int i = 0; i < size; i++) {

		int min = i; //��С�����±� 
		for (int j = i + 1; j < size; j++) {

			if (array[min] > array[j]) {
				min = j;
			}
		}
		swap(array + i, array + min);

	}
}

//ѡ��������Ż��棺ÿ�ΰ�������С�Ķ��ҳ���
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
		if (max == minspace) //������Ҫע��
			max = min;
		swap(array + max, array + maxspace);
		minspace++;
		maxspace--;
	}
}



//������
//�����򣺽����
//O(n*lg(n))
//O(1)
//���ȶ�

void AdjustDown(int* array, int size, int root)
{
	while (1)
	{
		int left = 2 * root + 1;
		int right = 2 * root + 2;
		if (left >= size)  //û�����Ӿ���Ҷ�ӽڵ�
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

//ð������
//��ã�O(n),����
//���ƽ����O(n^2)
//�ȶ�
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



//��������
int Partition_1(int* array, int left, int right)  //hoare�������������ӣ��������˾ͽ�����
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
int Partition_2(int* array, int left, int right)   //�ڿӷ�
{
	int begin = left;
	int end = right;
	int pivot = array[right];  //ѡ���Ҵ�Ϊ��׼ֵ������׼ֵ��ס��right����Ϊ��
	while (begin < end)
	{
		while (begin < end && array[begin] <= pivot)
		{
			begin++;
		}
		array[end] = array[begin]; //��ӣ�begin��Ϊ��
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;
	return begin;
}
int Partition_3(int* array, int left, int right) //ǰ���±귨
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

	if (left >= right)  //��������ֻ��һ��������û�����ˣ�����ͽ�����
		return;
	int div;  //��׼ֵ���ڵ��±�
	div = Partition_3(array,left,right); //�Ȼ�׼ֵС�ķ�����ߣ��Ȼ�׼ֵ��ķ��ڻ�׼ֵ���ұ�
	_QuickSort(array, 0, div - 1);
	_QuickSort(array, div + 1, right);
}
void QuickSort(int* array, int size)
{
	_QuickSort(array, 0, size - 1);
}