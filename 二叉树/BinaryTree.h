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

//�����鴴����
typedef struct result  //create�����ķ���ֵ
{
	node* root;  //���������ĸ��ڵ�
	int used;  //�õ����ַ�����
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
	//������
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
//�����������Ҫ�ö��У�1.�Ѹ��ڵ�ŵ������� 2��������ͷ�ڵ�ȡ������ӡ��ͬʱ���ڵ�ĺ��Ӵ���������
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
		//����Ϊ��Ҳ��Ҫ���սڵ������
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
//�ǵݹ��ı��������ֵ�һ�Σ��ڶ��Σ������ξ����ڵ��������
void PreOrderNotR(BTNode* root)
{
	std::stack<BTNode*> st;
	BTNode* cur = root;  //�����ڵ��ָ��
	BTNode* top;  //����ջ�����ݵ�ָ��
	BTNode* last = NULL;  //��һ�����η��ʽ����Ľڵ�
	while (!st.empty() || cur != NULL)
	{
		while (cur != NULL)
		{
			//��һ�η��ʵ��ڵ㣺��cur����ʽ
			//printf("%c  ", cur->value_);
			st.push(cur);
			cur = cur->left;
		}
		top = st.top();
		if (top->right == NULL)
		{
			//right==NULL �ڶ��κ͵�����ͬʱ����
			//right != NULL�������Ҫ����һ�����η��ʽ����Ľڵ��ǲ����Һ���
			//�ڶ��κ͵����ζ�����top����ʽ���ʵ���
			printf("%c  ", top->value_);
			cur = top->right;
			st.pop();
			last = top;
		}
		else
		{
			if (last != top->right)
			{
				//�ڶ���
				//printf("%c  ", top->value_);

				cur = top->right;
			}
			else {
			
				//������
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


//��������Ľڵ����,�����õݹ鷽�������������ֲ�ͬ��˼����ʽ�������͵ݹ�˼��
void BinaryTreeSize1(BTNode* root,int* p_size)
{
	//����˼·
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
//��Ҷ�ӽڵ����
void BinaryTreeLeafSize1(BTNode* root, int* p_size)
{
	//����˼·
	if (root == NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		(*p_size)++;
	BinaryTreeLeafSize1(root->left, p_size);
	BinaryTreeLeafSize1(root->right, p_size);
}
int BinaryTreeLeafSize2(BTNode* root)
{
	//����˼·
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize2(root->left)+BinaryTreeLeafSize2(root->right);
}
//���k��Ľڵ����:�����ò�������ĵݹ飬�����õݹ��˼·
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//����һ��ֵ�ڲ�������
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
