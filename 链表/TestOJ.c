#define  _CRT_SECURE_NO_WARNINGS 1

#include"OJ.h"
#include"SList.h"
#include<windows.h>
#include<stdio.h>
void TestReverseList()
{
	SList slist;
	SListInit(&slist);

	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	PrintValue(&slist);

	SLNode* reverse_first = ReverseList(&slist);

	SList newlist;
	newlist.first_ = reverse_first;
	PrintValue(&newlist);
	

	SListDestroy(&slist);
}
void TestSListRemove()
{
	SList slist;
	SListInit(&slist);

	SListPushBack(&slist, 1);
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	PrintValue(&slist);

	SListRemove(&slist, 1);
	PrintValue(&slist);


	SListDestroy(&slist);

}
void TestFindMiddleNode()
{
	SList slist;
	SListInit(&slist);

	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	PrintValue(&slist);

	SLNode* node =  MiddleNode(&slist);
	printf("%d", node->value_);
}
void TestFindKthToTail()
{
	SList slist;
	SListInit(&slist);

	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	PrintValue(&slist);

	SLNode* node = FindKthToTail(&slist,2);
	printf("%d", node->value_);

	SListDestroy(&slist);
}


void TestMergeTwoList()
{
	SList slist1;
	SListInit(&slist1);

	SListPushBack(&slist1, 1);
	SListPushBack(&slist1, 2);
	SListPushBack(&slist1, 5);
	SListPushBack(&slist1, 8);
	SListPushBack(&slist1, 9);
	PrintValue(&slist1);

	SList slist2;
	SListInit(&slist2);

	SListPushBack(&slist2, 1);
	SListPushBack(&slist2, 3);
	SListPushBack(&slist2, 6);
	SListPushBack(&slist2, 6);
	SListPushBack(&slist2, 7);
	PrintValue(&slist2);


	SList newlist;
	SListInit(&newlist);
	newlist.first_ = MergeTwoList(&slist1, &slist2);
	PrintValue(&newlist);

	SListDestroy(&newlist);

}

void TestPartition()
{
	SList slist1;
	SListInit(&slist1);

	SListPushBack(&slist1, 8);
	SListPushBack(&slist1, 6);
	SListPushBack(&slist1, 4);
	SListPushBack(&slist1, 9);
	SListPushBack(&slist1, 5);
	PrintValue(&slist1);

	
	SList newlist;
	SListInit(&newlist);
	newlist.first_ = Partition(&slist1, 7);
	PrintValue(&newlist);

	SListDestroy(&newlist);
}
void TestDeleteDuplication()
{
	SList slist1;
	SListInit(&slist1);

	SListPushBack(&slist1, 1);
	SListPushBack(&slist1, 1);
	SListPushBack(&slist1, 1);
	SListPushBack(&slist1, 1);
	SListPushBack(&slist1, 1);
	SListPushBack(&slist1, 1);

	SListPushBack(&slist1, 1);
	PrintValue(&slist1);


	SList newlist;
	SListInit(&newlist);
	newlist.first_ = DeleteDuplication(&slist1);
	PrintValue(&newlist);

	SListDestroy(&newlist);
}

#if 1
int main()
{
	//TestReverseList();
	//TestSListRemove();
	//TestFindMiddleNode();
	//TestFindKthToTail();
	//TestMergeTwoList();
	//TestPartition();
	TestDeleteDuplication();
	system("pause");
	return 0;
}
#endif