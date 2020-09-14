#pragma once

class BST
    {
    struct Node;

    public:
        BST() noexcept;
        ~BST();

        auto insert(int val) noexcept -> void;
        auto remove(int val) noexcept -> void;
        auto search(int val) noexcept -> void;
        auto display()       noexcept -> void;

    
    private:
        auto insert(int val, Node* lroot) noexcept -> Node*;
        auto remove(int val, Node* lroot) noexcept -> Node*;
        auto find(Node* lroot, int val)   noexcept -> Node*;
        auto findMin(Node* lroot)         noexcept -> Node*;
        auto findMax(Node* lroot)         noexcept -> Node*;
        auto makeEmpty(Node *lroot)       noexcept -> Node*;
        auto inorder(Node *lroot)         noexcept -> void;

        Node* m_root;
    };