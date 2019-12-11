#define  _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<stack>
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
typedef char BTDataType;
typedef struct BTNode
{
	BTDataType value_;
	struct BTNode* left;
	struct BTNode* right;
}BTNode,node;

//用数组创建树
typedef struct result  //create函数的返回值
{
	node* root;  //构建的树的根节点
	int used;  //用掉的字符个数
}result;

result create(char preorder[], int size)
{
	if (size == 0)
	{
		result result;
		result.root = NULL;
		result.used = 0;
		return result;
	}
	char root_val = preorder[0];
	if (root_val == '#')
	{
		result result;
		result.root = NULL;
		result.used = 1;
		return result;
	}
	//构建根
	node* root = (node*)malloc(sizeof(node));
	root->value_ = root_val;
	root->left = root->right = NULL;

	result left_result = create(preorder + 1, size - 1);
	result right_result = create(preorder + 1 + left_result.used, size - 1 - left_result.used);

	root->left = left_result.root;
	root->right = right_result.root;

	result result;
	result.root = root;
	result.used = 1 + left_result.used + right_result.used;
	return result;
}
BTNode* NewNode(BTDataType value)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->value_ = value;
	newnode->left = newnode->right = NULL;
	
	return newnode;
}
//层序遍历：需要用队列，1.把根节点放到队列中 2，将队列头节点取出来打印的同时将节点的孩子带到队列中
void LevelOrderTravelsal(BTNode* root)
{
	if (root == NULL)
		return;
	std::queue<BTNode*>qu;
	qu.push(root);
	while (!qu.empty())
	{
		BTNode* front = qu.front();
		qu.pop();
		printf("%c ", front->value_);
		if(front->left != NULL)
			qu.push(front->left);
		if(front->right != NULL)
			qu.push(front->right);
	}
}

bool IsCompleteBinaryTree(BTNode* root)
{
	if (root == NULL)
		return true;
	std::queue<BTNode*> qu;
	while (1)
	{
		qu.push(root);
		BTNode* front = qu.front();
		qu.pop();
		if (front == NULL)
			break;
		//孩子为空也需要将空节点入队列
		qu.push(root->left);
		qu.push(root->right);
	}
	while (!qu.empty())
	{
		BTNode* front = qu.front();
		qu.pop();
		if (front != NULL)
			return false;
	}
	return true;
}
//非递归版的遍历，区分第一次，第二次，第三次经过节点的完整版
void PreOrderNotR(BTNode* root)
{
	std::stack<BTNode*> st;
	BTNode* cur = root;  //遍历节点的指针
	BTNode* top;  //返回栈顶数据的指针
	BTNode* last = NULL;  //上一个三次访问结束的节点
	while (!st.empty() || cur != NULL)
	{
		while (cur != NULL)
		{
			//第一次访问到节点：以cur的形式
			//printf("%c  ", cur->value_);
			st.push(cur);
			cur = cur->left;
		}
		top = st.top();
		if (top->right == NULL)
		{
			//right==NULL 第二次和第三次同时经过
			//right != NULL的情况，要看上一个三次访问结束的节点是不是右孩子
			//第二次和第三次都是以top的形式访问到的
			printf("%c  ", top->value_);
			cur = top->right;
			st.pop();
			last = top;
		}
		else
		{
			if (last != top->right)
			{
				//第二次
				//printf("%c  ", top->value_);

				cur = top->right;
			}
			else {
			
				//第三次
				printf("%c  ", top->value_);

				st.pop();
				last  = top;
			}
		}
	}
}
void PreOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c  ", root->value_);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c  ", root->value_);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c  ", root->value_);
}


//求二叉树的节点个数,都是用递归方法，但是有两种不同的思考方式，遍历和递归思想
void BinaryTreeSize1(BTNode* root,int* p_size)
{
	//遍历思路
	if (root == NULL)
		return;
	(*p_size)++;
	
	BinaryTreeSize1(root->left, p_size);
	BinaryTreeSize1(root->right, p_size);

}

int BinaryTreeSize2(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize2(root->left) + BinaryTreeSize2(root->right);
}
//求叶子节点个数
void BinaryTreeLeafSize1(BTNode* root, int* p_size)
{
	//遍历思路
	if (root == NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		(*p_size)++;
	BinaryTreeLeafSize1(root->left, p_size);
	BinaryTreeLeafSize1(root->right, p_size);
}
int BinaryTreeLeafSize2(BTNode* root)
{
	//遍历思路
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize2(root->left)+BinaryTreeLeafSize2(root->right);
}
//求第k层的节点个数:可以用层序遍历的递归，或者用递归的思路
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//查找一个值在不在树中
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->value_ == x)
		return root;
	BTNode* left_result = BinaryTreeFind(root->left, x);
	if (left_result != NULL)
		return left_result;
	return  BinaryTreeFind(root->right, x);
}
