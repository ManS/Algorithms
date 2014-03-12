#include "Graph.h"
#include <vector>
#include <stack>
#include <queue>
#include "LinkedList.h"

//////////////////////////////////////////////////////////////////////
//4.1 check if the tree is balanced or not.

int MinTreeDepth(TreeNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
		return min(MinTreeDepth(node->GetLeftChild()),MinTreeDepth(node->GetRightChild()))+1;
}
int MaxTreeDepth(TreeNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
		return max(MaxTreeDepth(node->GetLeftChild()),MaxTreeDepth(node->GetRightChild()))+1;
}
bool Balanced(TreeNode* root)
{
	if (MaxTreeDepth(root) - MinTreeDepth(root) > 1)
	{
		return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//4.2 Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

bool CheckRouteExist(vector< vector<int> > graph, int nodeA, int nodeB)
{
	vector<bool> visited(graph.size(), false);
	stack<int> dfsStack;
	dfsStack.push(nodeA);

	while (!dfsStack.empty())
	{
		int currentNode = dfsStack.top();
		dfsStack.pop();
		for (int i = 0; i < graph[currentNode].size(); i++)
		{
			
			if (!visited[graph[currentNode][i]])
			{
				if (graph[currentNode][i] == nodeB)
				{
					return true;
				}
				dfsStack.push(graph[currentNode][i]);
			}
		}
		visited[currentNode] = true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//4.3 Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.

TreeNode* addToTree(int arr[], int start, int end)
{
	if (end < start)
	{
		return NULL;
	}
	int mid = start+end /2;
	TreeNode* root = new TreeNode(arr[mid]);
	root->SetLeftChild(addToTree(arr,start,mid-1));
	root->SetRightChild(addToTree(arr,mid+1, end));
	
	return root;
}

TreeNode* BuildMinimalDepthTree(int sortedArray[], int length)
{
	return addToTree(sortedArray, 0, length-1);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//4.4 Given a binary search tree, design an algorithm which creates a linked list of all the nodes 
//		at each depth (eg, if you have a tree with depth D, you’ll have D linked lists.

vector< vector<TreeNode*> > BuildLevelLinkedList(TreeNode* root)
{
	//make BFS (level by level traversal).
	int level = 0;
	vector<vector<TreeNode*>> result;
	
	vector<TreeNode*> firstLinkedList;
	firstLinkedList.push_back(root);
	
	result.push_back(firstLinkedList);

	while (true)
	{
		vector<TreeNode*> currentLevelLinkedList;

		for (int i = 0; i < result[level].size(); i++)
		{
			TreeNode* node = result[level][i];
			if (node!=NULL)
			{
				if (node->GetLeftChild() != NULL)
				{
					currentLevelLinkedList.push_back(node->GetLeftChild());
				}
				if (node->GetRightChild() != NULL)
				{
					currentLevelLinkedList.push_back(node->GetRightChild());
				}
			}
		}
		if (currentLevelLinkedList.size() >0 )
		{
			result.push_back(currentLevelLinkedList);
		}
		else
		{
			break;
		}

		level++;
	}
	return result;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//4.5 Design an algorithm and write code to find the first common ancestor of two nodes 
//in a binary tree Avoid storing additional nodes in a data structure NOTE: This is not 
//necessarily a binary search tree.
bool covers(TreeNode* root, TreeNode* p)
{
	if (root == NULL)
	{
		return false;
	}
	if (root == p)
	{
		return true;
	}
	return covers(root->GetLeftChild(), p) || covers(root->GetRightChild(),p);

}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (covers(root->GetLeftChild(),p) && covers(root->GetLeftChild(),q))
	{
		return commonAncestor(root->GetLeftChild(),p,q);
	}
	if (covers(root->GetRightChild(),p) && covers(root->GetRightChild(),q))
	{
		return commonAncestor(root->GetRightChild(),p,q);
	}
	return root;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//4.7 You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes 
//		Create an algorithm to decide if T2 is a subtree of T1

bool matchTree(TreeNode* T1, TreeNode* T2)
{
	if (T1 == NULL && T2 == NULL)
	{
		return true;
	}
	if (T1==NULL || T2 == NULL)
	{
		return false;
	}
	if (T1->GetNodeData() != T2->GetNodeData())
	{
		return false;
	}
	return (matchTree(T1->GetLeftChild(),T2->GetLeftChild()) && 
			matchTree(T1->GetRightChild(), T2->GetRightChild()));
}

bool isSubTree(TreeNode* T1, TreeNode* T2)
{
	if (T1 == NULL)
	{
		return false;
	}
	if (T1->GetNodeData() == T2->GetNodeData())
	{
		if(matchTree(T1,T2))
			return true;
	}
	return (isSubTree(T1->GetLeftChild(),T2) || isSubTree(T1->GetRightChild(), T2));
}

bool containsTree(TreeNode* T1, TreeNode* T2)
{
	if (T2 == NULL)
		return true;

	return isSubTree(T1,T2);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//4.8 You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes 
//		Create an algorithm to decide if T2 is a subtree of T1

void print(vector<int> buffer, int i2, int level)
{
	for (int i = level; i <= i2; i++)
	{
		cout<<buffer[i]<<" ";
	}
	cout<<endl;
}

void findSum(TreeNode* head, int sum, vector<int> buffer, int level)
{
	if (head == NULL)
	{
		return;
	}
	int tmp = sum;
	buffer.push_back(head->GetNodeData());
	for (int i = level; i >=0 ; i--)
	{
		tmp -= buffer[i];
		if (tmp == 0)
		{
			print(buffer,i, level);
		}
	}
	vector<int> c1 = buffer;
	vector<int> c2 = buffer;

	findSum(head->GetLeftChild(),sum , c1, level+1);
	findSum(head->GetRightChild(), sum, c2, level+1);
}