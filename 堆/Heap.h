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

//pop��ɾ���Ѷ�Ԫ�أ�ɾ������λ�õ�Ԫ��û���κ�����
void HeapPop(heap* heap);

//�����������Ҫ���������ϵ���
void HeapPush(heap* heap,int val);


//�����򣬽���ѣ�
//�Ž��򣬽�С��
//�����öѵ���ֵ�ͺ����Ԫ�ؽ�����Ȼ��������µ�����ʱ�临�Ӷ�ΪO(lg(n))

void HeapSort(int* array, int size);