// 串.cpp: 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <iostream>
#include <string>
//二叉链表的定义
using namespace std;
typedef char TElemType;
typedef struct BinaryTreeNode {
	TElemType data;
	struct BinaryTreeNode *lchild, *rchild;
}BinaryTreeNode, *BinaryTree;
//二叉树的构建
void InorOderTraverse(BinaryTree T)
{
	if (T == NULL)
	{
		cout << "#" << "  ";
		return;
	}
	InorOderTraverse(T->lchild);
	cout << T->data << "  ";
	InorOderTraverse(T->rchild);
}
//二叉树前序遍历算法
void PreOderTraverse(BinaryTree T)
{
	if (T == NULL)
	{
		cout << "#" << "  ";
		return;
	}
	cout << T->data << "  ";
	PreOderTraverse(T->lchild);
	PreOderTraverse(T->rchild);
}
//二叉树的后遍历算法
void PostOderTraverse(BinaryTree T)
{
	if (T == NULL)
	{
		cout << "#" << "  ";
		return;
	}
	PostOderTraverse(T->lchild);
	PostOderTraverse(T->rchild);
	cout << T->data << "  ";
}

void CreateBinaryTree(BinaryTree *T)
{
	TElemType ch;
	cin >> ch;
	if (ch == '$')
	{
		return;
	}
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = new BinaryTreeNode;
		if (!*T)return;
		(*T)->data = ch;
		CreateBinaryTree(&(*T)->lchild);
		CreateBinaryTree(&(*T)->rchild);
	}
}

int main()
{
	BinaryTree tree = new BinaryTreeNode;
	cout << "构建一颗由字符构成的二叉树，#代表空" << endl;
	CreateBinaryTree(&tree);
	cout << "二叉树的前序遍历输出" << endl;
	PreOderTraverse(tree);
	cout << endl;
	cout << "二叉树的中序遍历输出" << endl;
	InorOderTraverse(tree);
	cout << endl;
	cout << "二叉树的后序遍历输出" << endl;
	PostOderTraverse(tree);
	cout << endl;
	return 0;
}
//二叉树中序遍历算法

