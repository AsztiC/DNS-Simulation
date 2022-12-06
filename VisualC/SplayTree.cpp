#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct TreeNode
{
	std::string URL;
	std::string IPA;
	TreeNode* left;
	TreeNode* right;
	TreeNode(std::string x, std::string y) : URL(x), IPA(y), left(nullptr), right(nullptr) {}
};

class SplayTree
{
public:
	TreeNode* rNode = nullptr;

	TreeNode* Zig(TreeNode* root) // right rotation
	{
		TreeNode* nLeft = root->left;
		root->left = nLeft->right;
		nLeft->right = root;
		return nLeft;
	}

	TreeNode* Zag(TreeNode* root) // left rotation
	{
		TreeNode* nRight = root->right;
		root->right = nRight->left;
		nRight->left = root;
		return nRight;
	}

	TreeNode* Splay(TreeNode* root, std::string _URL)
	{
		if (root)
		{
			if (root->URL == _URL) // base case: URL to splay with is found
			{
				return root;
			}
			else if (_URL < root->URL) // check the left subtree
			{
				if (root->left) // check if there is a left subtree before trying to access it
				{
					if (_URL < root->left->URL)
					{
						if (root->left->left) // check that the left subtree has a left subtree
						{
							root->left->left = Splay(root->left->left, _URL);
							root = Zig(root);
						}
					}
					else if (_URL > root->left->URL)
					{
						if (root->left->right) // check that the left subtree has a right subtree
						{
							root->left->right = Splay(root->left->right, _URL);
							root->left = Zag(root->left);
						}
					}
					return Zig(root); // perform base left rotation regardless of whether or not left subtree has subtrees
				}
			}
			else if (_URL > root->URL) // check the right subtree
			{
				if (root->right) // check there is a right subtree before trying to access it
				{
					if (_URL < root->right->URL)
					{
						if (root->right->left) // check that the right subtree has a left subtree
						{
							root->right->left = Splay(root->right->left, _URL);
							root->right = Zig(root->right);
						}
					}
					else if (_URL > root->right->URL)
					{
						if (root->right->right) // check that the right subtree has a right subtree
						{
							root->right->right = Splay(root->right->right, _URL);
							root = Zag(root);
						}
					}
					return Zag(root); // perform base right rotation regardless of whether or not right subtree has subtrees
				}
			}
		}
		return root;
	}

	TreeNode* insert(TreeNode* root, std::string URL, std::string IPA, bool& success)
	{
		if (!root)
		{
			success = true;
			root = new TreeNode(URL, IPA);
			return root;
		}
		else
		{
			if (URL < root->URL)
			{
				root->left = insert(root->left, URL, IPA, success);
			}
			else if (URL > root->URL)
			{
				root->right = insert(root->right, URL, IPA, success);
			}
			else
			{
				std::cout << "unsuccessful" << std::endl;
			}
		}
		return root;
	}

	void insertHelp(std::string URL, std::string IPA)
	{
		if (!rNode)
		{
			rNode = new TreeNode(URL, IPA);
		}
		else
		{
			bool success = false;
			insert(rNode, URL, IPA, success);
			if (success == true)
			{
				rNode = Splay(rNode, URL);
				std::cout << rNode->URL << std::endl;
			}
		}
	}

	std::string Search(std::string key)
	{
		rNode = Splay(rNode, key);
		if (rNode->URL == key)
		{
			std::cout << rNode->URL << " " << rNode->IPA << std::endl;
			return rNode->IPA;
		}
		else
		{
			std::cout << "unsuccessful" << std::endl;
			return "";
		}
	}

	TreeNode* clear(TreeNode* root)
	{
		if (root)
		{
			root->right = clear(root->right);
			root->left = clear(root->left);

			if (!rNode->right && !rNode->left)
			{
				TreeNode* temp = rNode;
				delete rNode;
				rNode = nullptr;
				return rNode;
			}

			TreeNode* temp = root;
			delete temp;
			root = nullptr;
			return root;
		}
		return root;
	}

	void clearHelp()
	{
		clear(rNode);
	}

	void PROString(TreeNode* root, std::string& retString)
	{
		if (root)
		{
			retString += root->URL;
			retString += ", ";
			PROString(root->left, retString);
			PROString(root->right, retString);
		}
	}

	void printPreorder(TreeNode* root)
	{
		if (!root)
		{
			std::cout << "empty list" << std::endl;
		}
		else
		{
			std::string nameString = "";
			PROString(rNode, nameString);
			std::string printString = nameString.substr(0, nameString.length() - 2);
			std::cout << printString << std::endl;
		}
	}

	void pproHelp()
	{
		printPreorder(rNode);
	}
};