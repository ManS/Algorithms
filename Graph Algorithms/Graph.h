#include <vector>
using namespace std;

class TreeNode
{

private:
	int data;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode()
	{
		left = NULL;
		right = NULL;
	}

	TreeNode(int p_data)
	{
		left = NULL;
		right = NULL;
		data = p_data;
	}

	TreeNode* GetLeftChild()
	{
		return left;
	}
	TreeNode* GetRightChild()
	{
		return right;
	}

	int GetNodeData()
	{
		return data;
	}

	void SetLeftChild(TreeNode* pleft)
	{
		this->left = pleft;
	}

	void SetRightChild(TreeNode* pright)
	{
		this->right = pright;
	}

};
