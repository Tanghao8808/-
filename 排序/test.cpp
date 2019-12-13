#define  _CRT_SECURE_NO_WARNINGS 1
#include"sort.hpp"


int main()
{
	int array[] = {3,1,4,7,6,9,8,5,2,0};
	int size = sizeof(array) / sizeof(int);
	printf_array(array, size);
	printf("\n");
	//InsertSort(array, size);
	//InsertSortwithGap(array, size,1);
	//ShellSort(array, size);
	//SelectSort(array, size);
	//SelectSortOP(array, size);
	//HeapSort(array, size);
	//BubbleSort(array, size);
	QuickSort(array, size);
	printf_array(array, size);

	system("pause");
	return 0;
}

