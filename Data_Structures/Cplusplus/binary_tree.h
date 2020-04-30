#pragma once

class BinaryTree 
	{
    public:
        struct Node
            {
            Node *left;
            int data;
            Node *right;
            };

        enum class Traversal_Type
            {
            PRE_ORDER,
            IN_ORDER,
            POST_ORDER
            };

        BinaryTree();
        ~BinaryTree();

        auto display(const Traversal_Type &type) const -> void;
        auto insert(Node* &head, int value)            -> void;
        auto getHead()                                 -> Node*&;
        auto height(Node *root)                        -> int;
        auto isBalanced(const Node *root)              -> bool;
    
    private:
    	Node *m_head;
	}; 
