#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include"SList.h"


//删除所有值为value的节点
void SListRemove(SList* slist, SLDataType value);

//反转单链表
SLNode* ReverseList(SList* slist);


//返回中间节点
//双指针遍历法
SLNode* MiddleNode(SList* slist);

//找倒数第 K 个节点
SLNode* FindKthToTail(SList* slist, unsigned int k);
//合并两个有序链表
SLNode* MergeTwoList(SList* slist1, SList* slist2);

//链表分割，小于x的值在前，大于等于x的值在后
SLNode* Partition(SList* slist, SLDataType x);

//有序链表删除重复节点 1-->2-->3-->3-->4-->4-->5     :      1-->2-->5
SLNode* DeleteDuplication(SList* slist);
