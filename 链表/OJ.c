#define  _CRT_SECURE_NO_WARNINGS 1

#include"OJ.h"
#include"SList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>


//逆置单链表
//方法一：头删，再头插的方式
#if 0
SLNode* ReverseList(SList* slist)
{
	assert(slist);
	if (slist->first_ == NULL || slist->first_->next_ == NULL)
		return slist->first_;
	SLNode* first = slist->first_;
	SLNode* next = first->next_;
	SLNode* newlist = NULL;
	while (first != NULL)
	{
		first->next_ = newlist;
		newlist = first;

		first = next;
		if (next != NULL)
			next = next->next_;
	}
	slist->first_ = NULL;
	slist = NULL;
	return newlist;
}
#endif

//方法二：前中后三个指针，直接改变指向关系
SLNode* ReverseList(SList* slist)
{
	assert(slist);
	if (slist->first_ == NULL || slist->first_->next_ == NULL)
		return slist->first_;

	SLNode* prev = NULL;
	SLNode* cur = slist->first_;
	SLNode* next = cur->next_;
	
	while (cur != NULL)
	{
		cur->next_ = prev;
		
		prev = cur;
		cur = next;
		if (next != NULL)
			next = next->next_;
	}
	return prev;
}

//删除所有值为value的节点
//注意要删除的是头节点和删除节点连着的情况
//先删除后面的相同节点，再来判断第一个节点
void SListRemove(SList* slist, SLDataType value)
{
	assert(slist && slist->first_);

	SLNode* prev = slist->first_;
	SLNode* cur = prev->next_;

	while (cur != NULL)
	{
		if (cur->value_ == value)
		{
			prev->next_ = cur->next_;
			free(cur);
			cur = prev->next_;
		}
		else
		{
			prev = cur;
			cur = cur->next_;
		}
	}
	if (slist->first_->value_ == value)
	{
		SLNode* del = slist->first_;
		slist->first_ = del->next_;
		free(del);
	}
}

//返回中间节点
//双指针遍历法
SLNode* MiddleNode(SList* slist)
{
	assert(slist && slist->first_);
	SLNode* slow = slist->first_;
	SLNode* fast = slist->first_;
	while (fast != NULL && fast->next_ != NULL)
	{
		slow = slow->next_;
		fast = fast->next_->next_;
	}
	return slow;
}


//注意特殊情况 ：1-->2, k = 3    //    1-->2 ,k = 2
SLNode* FindKthToTail(SList* slist, unsigned int k)
{
	assert(slist);
	SLNode* first = slist->first_;
	SLNode* slow = slist->first_;
	while (k--)
	{
		if (first == NULL)
			return NULL;
		first = first->next_;
		
	}	
	while (first != NULL)
	{
		first = first->next_;
		slow = slow->next_;
	}
	return slow;
}

//合并两个有序链表:用一个新链表不断做尾插
SLNode* MergeTwoList(SList* slist1, SList* slist2)
{
	if (slist1 == NULL)
		return slist2->first_;
	if (slist2 == NULL)
		return slist1->first_;
	SLNode* cur1 = slist1->first_;
	SLNode* cur2 = slist2->first_;

	
	SLNode* newlist_first = NULL;
	SLNode* newlist_tailnode = NULL;

	while (cur1 && cur2)
	{
		if (cur2->value_ < cur1->value_)
		{
			if (newlist_tailnode == NULL)
			{
				newlist_first = cur2;
				newlist_tailnode = cur2;
				cur2 = cur2->next_;
			}
			else
			{
				newlist_tailnode->next_ = cur2;
				newlist_tailnode = cur2;
				cur2 = cur2->next_;
			}
		}
		else
		{
			if (newlist_tailnode == NULL)
			{
				newlist_first = cur1;
				newlist_tailnode = cur1;
				cur1 = cur1->next_;
			}
			else
			{
				newlist_tailnode->next_ = cur1;
				newlist_tailnode = cur1;
				cur1 = cur1->next_;
			}
		}
	}
	
	if (cur1 == NULL)
	{
		newlist_tailnode->next_ = cur2;

	}
	else
	{
		newlist_tailnode->next_ = cur1;
	}
	
	return newlist_first;
}

SLNode* Partition(SList* slist, SLDataType x)
{
	assert(slist);
	if (slist->first_ == NULL)
		return NULL;
	SLNode* cur = slist->first_;
	
	SLNode* less_first = NULL;
	SLNode* less_tail = NULL;
	SLNode* great_first = NULL;
	SLNode* great_tail = NULL;

	while (cur != NULL)
	{
		if (cur->value_ < x)
		{
			if (less_tail == NULL)
			{
				less_first = less_tail = cur;
				cur = cur->next_;
			}
			else
			{
				less_tail->next_ = cur;
				less_tail = cur;

				cur = cur->next_;
			}
		}
		else {
			if (great_tail == NULL)
			{
				great_first = great_tail = cur;
				cur = cur->next_;
			}
			else
			{
				great_tail->next_ = cur;
				great_tail = cur;

				cur = cur->next_;
			}
		}
	}

	if (great_tail != NULL)
		great_tail->next_ = NULL; //避免链表带环
	if (less_tail != NULL)
	{
		less_tail->next_ = great_first;
		return less_first;
	}else
		return great_first;
}


SLNode* DeleteDuplication(SList* slist)
{
	assert(slist);
	if (slist->first_ == NULL)
		return NULL;
	
	SLNode* prev = NULL;
	SLNode* p1 = slist->first_;
	SLNode* p2 = p1->next_;

	SLNode* result = slist->first_;

	while (p2 != NULL)
	{
		if (p1->value_ != p2->value_)
		{
			prev = p1;
			p1 = p2;
			p2 = p2->next_;

		}
		else {
			
			while (p1->value_ == p2->value_ && p2!= NULL)
			{
				p2 = p2->next_;
			}
			SLNode* del = p1;
			while (del != p2)
			{
				SLNode* del_next = del->next_;
				free(del);
				del = del_next;
			}

			if (prev == NULL)
			{
				result = p1 = p2;
				if(p2 != NULL)
					p2 = p2->next_;
			}
			else
			{
				prev->next_ = p2;
				p1 = p2;
				if (p2 != NULL)
					p2 = p2->next_;
			}
		}
	}
	return result;
}