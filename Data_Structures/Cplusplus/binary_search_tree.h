#pragma once

class BST
    {
    struct node;

    public:
        BST() noexcept;
        ~BST();

        auto insert(int val) noexcept -> void;
        auto remove(int val) noexcept -> void;
        auto search(int val) noexcept -> void;
        auto display()       noexcept -> void;

    
    private:
        auto insert(int val, node* lroot) noexcept -> node*;
        auto remove(int val, node* lroot) noexcept -> node*;
        auto find(node* lroot, int val)   noexcept -> node*;
        auto findMin(node* lroot)         noexcept -> node*;
        auto findMax(node* lroot)         noexcept -> node*;
        auto makeEmpty(node *lroot)       noexcept -> node*;
        auto inorder(node *lroot)         noexcept -> void;

        node* m_root;
    };