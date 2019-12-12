#define  _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"


//С��

//���µ�����O( lg(n) )
//���µ�����ǰ���������������Ѿ�����ѵ������ˣ�
void AdjustDown(int* array, int size,int root)
{
	while (1)
	{
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		if (left >= size) //root��Ҷ��
			return;
		int min = left;
		if (right < size && array[right] < array[left])
		{
			min = right;
		}
		if (array[root] <= array[min])
			return;
		else
		{
			int tmp = array[min];
			array[min] = array[root];
			array[root] = tmp;
		}
		root = min;
	}
}

//���ѵ�ʱ�临�Ӷȣ�
//���������� O( n*lg(n) )
//��ȷ�����Ƴ���Ϊ O(n)
//�����Ǵ����һ����Ҷ�ӽڵ㿪ʼ���������µ���

void CreateHeap(int* array,int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
}

void HeapInit(heap* heap, int* array, int size)
{
	memcpy(heap->array_, array, sizeof(int)*size);
	heap->size_ = size;
	CreateHeap(heap->array_,heap->size_);
}

void HeapPrint(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void HeapPop(heap* heap)
{
	assert(heap);
	heap->array_[0] = heap->array_[heap->size_ - 1];
	AdjustDown(heap->array_, heap->size_ - 1, 0);
	heap->size_--;
}

//����ڵ���Ҫ���ڵ㲻�ϵ������ϵ���
void AdjustUp(int* array, int size, int child)
{
	while (child != 0)
	{
		int parent = (child - 1) / 2;
		if (array[parent] <= array[child])
			return;
		int tmp = array[parent];
		array[parent] = array[child];
		array[child] = tmp;

		child = parent;
	}
}

void HeapPush(heap* heap,int val)
{
	assert(heap);
	heap->array_[heap->size_++] = val;
	AdjustUp(heap->array_, heap->size_, heap->size_ - 1);
}
//�Ž���
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//O(lg(n))
void HeapSort(int* array, int size)
{
	CreateHeap(array, size);
	for (int i = 0; i < size - 1; i++)
	{
		swap(&array[0], &array[size - 1 - i]);
		AdjustDown(array, size -1 - i, 0);
	}
}