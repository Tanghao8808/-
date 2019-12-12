#define  _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<stdio.h>
#include<windows.h>

typedef struct heap
{
	int array_[100];
	int size_;
}heap;

void HeapInit(heap* heap, int* array, int size);
void HeapPrint(int* array, int size);
void AdjustDown(int* array, int size, int root);

//pop是删除堆顶元素，删除其他位置的元素没有任何意义
void HeapPop(heap* heap);

//插入在最后，需要不断做向上调整
void HeapPush(heap* heap,int val);


//排升序，建大堆，
//排降序，建小堆
//才能让堆的最值和后面的元素交换，然后进行向下调整，时间复杂度为O(lg(n))

void HeapSort(int* array, int size);