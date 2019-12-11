#define  _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"

#include<windows.h>
void testTravelsal()
{
	BTNode* a = NewNode(1);
	BTNode* b = NewNode(2);
	BTNode* c = NewNode(3);
	BTNode* d = NewNode(4);
	BTNode* e = NewNode(5);
	BTNode* f = NewNode(6);
	BTNode* g = NewNode(7);

	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;
	d->right = f;
	e->right = g;

	PreOrder(a);
}
void TestCreateTree()
{
	char preorder[] = "abc##de#g##f###";
	int size = strlen(preorder);
	result result = create(preorder, size);
	InOrder(result.root);
	int node_size = 0;
	BinaryTreeSize1(result.root, &node_size);
	printf("\n node_size = %d  ", node_size);
	printf("node_size = %d\n", BinaryTreeSize2(result.root));

	int leafnode_size = 0;
	BinaryTreeLeafSize1(result.root, &leafnode_size);
	printf("\n leafnode_size = %d  ", leafnode_size);
	printf("leafnode_size = %d  \n", BinaryTreeLeafSize2(result.root));

	printf("��һ��ڵ������%d  \n", BinaryTreeLevelKSize(result.root, 1));
	printf("�ڶ���ڵ������%d  \n", BinaryTreeLevelKSize(result.root, 2));
	printf("������ڵ������%d  \n", BinaryTreeLevelKSize(result.root, 3));
	printf("���Ĳ�ڵ������%d  \n", BinaryTreeLevelKSize(result.root, 4));
	printf("�����ڵ������%d  \n", BinaryTreeLevelKSize(result.root, 5));
	printf("������ڵ������%d  \n", BinaryTreeLevelKSize(result.root, 6));

	BTDataType x = 'f';
	BTNode* find_result_node = BinaryTreeFind(result.root, x);
	if (find_result_node == NULL)
	{
		printf("����û�в鵽��Ԫ��\n");

	}
	else
	{
		printf("���ҵ��Ľڵ�ֵΪ��%c\n", find_result_node->value_);
	}
	printf("���������");
	LevelOrderTravelsal(result.root);
	bool iscompleteBT = IsCompleteBinaryTree(result.root);
	if (iscompleteBT == true)
		printf("��������ȫ��������\n");
	else
		printf("����������ȫ��������\n");
	printf("�ݹ��ǰ�������\n");
	PostOrder(result.root);
	
	printf("\n�ǵݹ��ǰ�������\n");
	PreOrderNotR(result.root);
}

int main()
{
	//testTravelsal();
	TestCreateTree();
	system("pause");
	return 0;
}


