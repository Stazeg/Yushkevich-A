//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>
#include <vector>
#include <cstdlib>
using namespace std;
struct Content
{
	int Num;
	vector <int> data;
};

class Tree
{
public:
	Tree(int i)
	{
		Size = 0;
		isEmpty = true;
	}
	void Add(int val)
	{
		++Size;
		if (isEmpty)
		{
			root = new Node(val);
			isEmpty = false;
		}
		else   
			AddNode(root, val);
	}
	//void Erase(int val)
	long Max()
	{
		if (isEmpty)   return 0;
		Node *vertex = root;
		int MaxValue = 0;
		while (vertex->value != -1)
		{
			MaxValue = max(vertex->value, MaxValue);
			vertex = vertex->rightSon;
		}
		return MaxValue;
	}
	bool Find(int &val)
	{
		if (isEmpty)    return false;
		return findVal(root, val);
	}
	bool Empty()
	{
		return isEmpty;
	}

private:
	struct Node
	{
		Node *leftSon, *rightSon;
		int value;
		Node(int v) : value(v)
		{
			if (v == -1)   return;
			leftSon = new Node(-1);
			rightSon = new Node(-1);
		}
	};
	Node *root;
	int Size;
	bool isEmpty;

	void AddNode(Node *vertex, int &val)
	{
		if (val >= vertex->value)
		{
			if (vertex->rightSon->value == -1)
				vertex->rightSon = new Node(val);
			else
				AddNode(vertex->rightSon, val);
		}
		else
		{
			if (vertex->leftSon->value = -1)
				vertex->leftSon = new Node(val);
			else
				AddNode(vertex->leftSon, val);
		}
	}
	bool findVal(Node *vertex, int &val)
	{
		if (vertex->value == val)    return true;
		if (vertex->value < val)
		{
			if (vertex->rightSon->value == -1)    return false;
			else    return findVal(vertex->rightSon, val);
		}
		else
		{
			if (vertex->leftSon->value == -1)     return false;
			else    return findVal(vertex->leftSon, val);
		}
	}
};

void init()
{
	long N, n, a;
	cin >> N; 
	vector <Tree> v;
	for (long i = 0; i < N; ++i)
	{
		cin >> n;
		Tree A(0);
		for (long j = 0; j < n; ++j)
		{
			cin >> a;
			A.Add(a);
		}
		v.push_back(A);
	}
	cout << "answer:\n";
	for (long i = 0; i < N; ++i)
		cout << v[i].Max() << "\n";
	system("pause");
}

bool openFile(char *name)
{
	freopen(name, "r", stdin);
	return true;
}

int main()
{
	//openFile("input.txt");
	init();
    return 0;
}

