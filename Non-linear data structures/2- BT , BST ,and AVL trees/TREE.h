#ifndef TREE_INCLUDED
#define TREE_INCLUDED

#include<iostream>
using namespace std;

// @m_abrazeg

/// @brief Represents a node in a binary tree 
template<typename T>
struct TreeNode { 
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode();
    TreeNode(const T&);
};

template<typename T>
class BinaryTree {
protected:
    TreeNode<T>*root;
    int number_of_nodes;
public:
    BinaryTree();
    ~BinaryTree();
    bool empty ();
    int height();
    int countLeaves();
    void copy(const BinaryTree<T>&);
    void print ();
    void destroy();
    int size ();

    const BinaryTree<T>&operator=(const BinaryTree<T>& otherTree);
protected:
    int height(TreeNode<T>*); 
    int countLeaves(TreeNode<T>*);
    void copy(TreeNode<T>*&,const TreeNode<T>*);
    void bfs (TreeNode<T>*);
    void destroy(TreeNode<T>*&current);
};

template<typename T>
class BT : public BinaryTree<T> { // abstract class
public:
    virtual void insert(const T&) = 0;
    virtual void remove(const T&) = 0;
    
    bool search(const T&);
    T getMax ();
    T getMin ();

protected:
    virtual TreeNode<T>* insert(TreeNode<T>*,const T&) = 0;
    virtual TreeNode<T>* remove(TreeNode<T>*,const T&) = 0;
    bool search(TreeNode<T>*,const T&);
    TreeNode<T>* getMin (TreeNode<T>*);
    TreeNode<T>* getMax (TreeNode<T>*);
};

template<typename T>
class BST : public BT<T> { 
public:
    void insert(const T&);
    void remove(const T&);
protected:
    TreeNode<T>* insert(TreeNode<T>*,const T&);
    TreeNode<T>* remove(TreeNode<T>*,const T&);
};

template<typename T>
class AVL : public BT<T> { 
public:
    void insert(const T&);
    void remove(const T&);
protected:
    TreeNode<T>* insert(TreeNode<T>*,const T&);
    TreeNode<T>* remove(TreeNode<T>*,const T&);
    int getBalanceFactor(TreeNode<T>*);

    TreeNode<T>* rightRotate(TreeNode<T>*);
    TreeNode<T>* leftRotate(TreeNode<T>*);
};

#endif // TREE_INCLUDED