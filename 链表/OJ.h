#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include"SList.h"


//ɾ������ֵΪvalue�Ľڵ�
void SListRemove(SList* slist, SLDataType value);

//��ת������
SLNode* ReverseList(SList* slist);


//�����м�ڵ�
//˫ָ�������
SLNode* MiddleNode(SList* slist);

//�ҵ����� K ���ڵ�
SLNode* FindKthToTail(SList* slist, unsigned int k);
//�ϲ�������������
SLNode* MergeTwoList(SList* slist1, SList* slist2);

//����ָС��x��ֵ��ǰ�����ڵ���x��ֵ�ں�
SLNode* Partition(SList* slist, SLDataType x);

//��������ɾ���ظ��ڵ� 1-->2-->3-->3-->4-->4-->5     :      1-->2-->5
SLNode* DeleteDuplication(SList* slist);
