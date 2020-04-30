#include "binary_tree.h"

#include "tree_traversal.h"
#include <cmath>

BinaryTree::BinaryTree()
	:m_head{nullptr}
	{

	}

BinaryTree::~BinaryTree()
	{
	}

auto BinaryTree::display(const Traversal_Type &type) const
	-> void
	{
	switch(type)
		{
		case Traversal_Type::PRE_ORDER:
			{
			preorder(m_head);			
			return;
			}
		    case Traversal_Type::IN_ORDER:
			{
			inorder(m_head);
			return;
			}
		case Traversal_Type::POST_ORDER:
			{
			postorder(m_head);
			return;
			}
		default:
			break;
		}
	}

auto BinaryTree::insert(Node* &head, int value) 
	-> void
	{
	if (!head)
	   {
	   auto p   = new Node; 
	   p->data  = value;
	   p->left  = nullptr;
	   p->right = nullptr;
   	   head 	= p;
	   return;
	   }
	if (value <= head->data)
	   {
       if (!head->left)
       	   {
           auto p = new Node;
           p->data = value;
           p->left = nullptr;
           p->right = nullptr;
           head->left = p;
           return;
           }
        insert(head->left, value);
	   }
	else
		{
        if (!head->right)
       	   {
           auto p = new Node;
           p->data = value;
           p->left = nullptr;
           p->right = nullptr;
           head->right = p;
           return;
           }
        insert(head->right, value);
		}
	}

auto BinaryTree::height(Node *root)
	-> int
	{
    if(!root)
        return 0;
    return std::max(height(root->left), height(root->right)) + 1;
	}

auto BinaryTree::getHead()   
	-> Node*&
	{
	return m_head;
	}

auto BinaryTree::isBalanced(const Node *root)
	-> bool
	{
    if(!root)
        return true;
    if (std::abs(height(root->left) - height(root->right)) > 1)
        return false;
    else
        return (isBalanced(root->left) && isBalanced(root->right));
	}