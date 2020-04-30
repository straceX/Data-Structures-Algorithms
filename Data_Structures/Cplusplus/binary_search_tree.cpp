#include "BST.h"

#include <iostream>

struct BST::node
	{
	 node *left;	 
     int data;
	 node *right;
	};

BST::BST() noexcept
    : m_root{ nullptr }
    {
    }

BST::~BST()
    {
    m_root = makeEmpty(m_root);
    }

auto BST::makeEmpty(BST::node *lroot) noexcept
    -> BST::node*
    {
    if (!lroot)
        return nullptr;
    makeEmpty(lroot->left);
    makeEmpty(lroot->right);
    delete lroot;
    return nullptr;
    }

auto BST::insert(int val, BST::node *lroot) noexcept
    -> BST::node*
    {
    if (!lroot)
        {
        lroot = new BST::node;
        lroot->data = val;
        lroot->left = lroot->right = nullptr;
        }
    else if (val < lroot->data)
        lroot->left = insert(val, lroot->left);
    else if (val > lroot->data)
        lroot->right = insert(val, lroot->right);
    return lroot;
}

auto BST::findMin(node *lroot) noexcept
    -> BST::node*
    {
    if (!lroot)
        return nullptr;
    else if (!lroot->left)
        return lroot;
    else
        return findMin(lroot->left);
    }

auto BST::findMax(node *lroot) noexcept
    -> BST::node*
    {
    if (!lroot)
        return nullptr;
    else if (!lroot->right)
        return lroot;
    else
        return findMax(lroot->right);
    }

auto BST::remove(int val, node *lroot) noexcept
    -> BST::node*
    {
    node* temp;
    if (!lroot)
        return nullptr;
    else if (val < lroot->data)
        lroot->left = remove(val, lroot->left);
    else if (val > lroot->data)
        lroot->right = remove(val, lroot->right);
    else if (lroot->left && lroot->right)
        {
        temp = findMin(lroot->right);
        lroot->data = temp->data;
        lroot->right = remove(lroot->data, lroot->right);
        }
    else
        {
        temp = lroot;
        if (!lroot->left)
            lroot = lroot->right;
        else if (!lroot->right)
            lroot = lroot->left;
        delete temp;
        }
    return lroot;
    }

auto BST::inorder(node *lroot) noexcept
    -> void
    {
    if (!lroot)
        return;
    inorder(lroot->left);
    std::cout << lroot->data << " ";
    inorder(lroot->right);
    }

auto BST::find(node *lroot, int val) noexcept
    -> BST::node*
    {
    if (!lroot)
        return nullptr;
    else if (val < lroot->data)
        return find(lroot->left, val);
    else if (val > lroot->data)
        return find(lroot->right, val);
    else
        return lroot;
    }

auto BST::insert(int val) noexcept
    -> void
    {
    m_root = insert(val, m_root);
    }

auto BST::remove(int val) noexcept
    -> void
    {
    m_root = remove(val, m_root);
    }

void BST::display() noexcept
    {
    inorder(m_root);
    std::cout << '\n';
    }

void BST::search(int val) noexcept
    {
    m_root = find(m_root, val);
    }
