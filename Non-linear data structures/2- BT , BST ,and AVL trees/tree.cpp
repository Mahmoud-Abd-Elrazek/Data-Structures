// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <queue>
#include <algorithm>
#include "TREE.h"
using namespace std;

int main() {    

    AVL<int> avl;
    avl.insert(4);
    avl.insert(2);
    avl.insert(6);
    avl.insert(1);
    avl.insert(1); // not inserted because it's duplicate
    avl.insert(3);

    cout << avl.size() << endl;
    cout << avl.height() << endl;

    avl.print();
    
    return 0;
}

template<typename T>
TreeNode<T>::TreeNode() { 
    left = nullptr;
    right = nullptr;
}

template<typename T>
TreeNode<T>::TreeNode(const T&val) { 
    left = nullptr;
    right = nullptr;
    data = val;
}

// ================== Binary Tree Start ==================
template<typename T>
BinaryTree<T>::BinaryTree() { 
    root = nullptr;
    number_of_nodes = 0;
}

template<typename T>
bool BinaryTree<T>::empty() { 
    return root == nullptr;
}

template<typename T>
int BinaryTree<T>::size () {
    return number_of_nodes;
}

template<typename T>
int BinaryTree<T>::height() { 
    return height(root);
}

template<typename T>
int BinaryTree<T>::height(TreeNode<T>*current) { 
    if(current == nullptr)
        return 0;
    return 1 + max( height(current->left),height(current->right) );
}

template<typename T>
int BinaryTree<T>::countLeaves() { 
    return countLeaves(root);
}

template<typename T>
int BinaryTree<T>::countLeaves(TreeNode<T>*current) { 

    int number_of_leaves = 0;

    queue<TreeNode<T>*> nextToVisit;
    nextToVisit.push(current);
    
    while (nextToVisit.empty() == false) {
        TreeNode<T>*front = nextToVisit.front();
        nextToVisit.pop();

        if (front->left == nullptr && front->right == nullptr)
            number_of_leaves += 1;
        else {
            if (front->left != nullptr)
                nextToVisit.push(front->left); 

            if (front->right != nullptr)
                nextToVisit.push(front->right); 
        }
    }

    return number_of_leaves;

}

template<typename T>
void BinaryTree<T>::copy(const BinaryTree<T>&other) {
    number_of_nodes = other.number_of_nodes;
    copy(root,other.root);
}

template<typename T>
void BinaryTree<T>::copy(TreeNode<T>*&current,const TreeNode<T>*other) {
    if (other == nullptr)
        current = nullptr;
    else {
        current = new TreeNode<T>(other->data);
        copy(current->left,other->left);
        copy(current->right,other->right);
    }
     
}

template<typename T>
void BinaryTree<T>::print () {
    if (empty() == true)
        return;

    bfs(root);
}

template<typename T>
void BinaryTree<T>::bfs (TreeNode<T>*current) {
    queue<TreeNode<T>*>nextToVisit;
    nextToVisit.push(current);

    while (nextToVisit.empty() == false) { 
        
        TreeNode<T>*front = nextToVisit.front();
        nextToVisit.pop();

        cout << front->data << " ";
        if (front->left != nullptr) 
            nextToVisit.push(front->left);

        if (front->right != nullptr) 
            nextToVisit.push(front->right);

    }
}

template<typename T>
void BinaryTree<T>::destroy() { 
    number_of_nodes = 0;
    destroy(root);
}

template<typename T>
void BinaryTree<T>::destroy(TreeNode<T>*&root) { 
    if (root != nullptr) { 
        destroy(root->left);
        destroy(root->right);
        delete root;
        root = nullptr;
    }        
}

template<typename T>
BinaryTree<T>::~BinaryTree() { 
    destroy(root);
    number_of_nodes = 0;
}

template<typename T>
const BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& otherTree) {

    if (this != &otherTree) { // avoid self-copy
        if (empty() == false)
            destroy();

        if (otherTree.root == nullptr)
            root = nullptr;
        else
            copy(root , otherTree.root);
    }

    return *this;
}
// ================== Binary Tree End ==================

// ================== BT interface Start ==================
template<typename T>
bool BT<T>::search(const T&item) { 
    return search(this->root,item);
}

template<typename T>
bool BT<T>::search(TreeNode<T>*current,const T&item) { 
    if (current == nullptr)
        return false;
    
    if (current->data == item)
        return true;

    if (current->data <= item)
        return search(current -> right , item);
    
    return search(current->left , item);
}

template<typename T>
TreeNode<T>* BT<T>::getMin (TreeNode<T>*current) { 
    return current->left != nullptr ? current->left : current;
} 

template<typename T>
TreeNode<T>* BT<T>::getMax (TreeNode<T>*current) { 
    return current->right != nullptr ? current->right : current;
}

template<typename T>
T BT<T>::getMax () { 
    if (getMax(this->root))
        return getMax(this->root)->data;
    exit(1);
}

template<typename T>
T BT<T>::getMin () { 
    if (getMin(this->root))
        return getMin(this->root)->data;
    exit(1);
}
// ================== BT interface Start ==================

// ================== Binary Search Tree Start ==================
template<typename T>
void BST<T>::insert(const T& item) { 
    this->root = insert(this->root,item);
    (this->number_of_nodes)++;
}

template<typename T>
TreeNode<T>* BST<T>::insert(TreeNode<T>*current,const T& item) {
    if (current == nullptr)
        return new TreeNode<T>(item);
    if (current->data <= item) 
        current->right = insert(current->right , item);
    else current->left = insert(current->left , item);
}

template<typename T>
void BST<T>::remove(const T&item) { 
    this->root = remove(this->root,item);
}

template<typename T>
TreeNode<T>* BST<T>::remove(TreeNode<T>*root,const T&item) {

    if (root == nullptr)
        return root;

    // search data
    if (item < root->data) // left 
        root->left = remove(root->left,item);
    else if (item > root->data) // right
        root->right = remove(root->right,item);
    else { // equal 
        // found the node to be deleted
        if (root->left == NULL) { // no left child || no child 
            TreeNode<T>* rightSubTree = root->right;
            delete root;      
            (this->number_of_nodes)--;       
            return rightSubTree;
        } 
        else if (root->right == NULL) { // no right child || no child 
            TreeNode<T>* leftSubTree = root->left;
            delete root;
            (this->number_of_nodes)--;
            return leftSubTree;
        } else { // has to chidldren
            T maxValue = this->getMax(root->left)->data;
            root->data = maxValue;
            root->left = this->remove(root->left, maxValue);
        }
    }

}
// ================== Binary Search Tree End ==================


// ================== AVL Tree Start ==================
template<typename T>
int AVL<T>::getBalanceFactor(TreeNode<T>*current) {
    return current == nullptr ? 0 : this->height(current->left) - this->height(current->right);
}

template<typename T>
TreeNode<T>* AVL<T>::rightRotate(TreeNode<T>*root) { 

    TreeNode<T>*newRoot = root->left;
    TreeNode<T>*rightSubTree = newRoot->right;
    
    // perform rotation
    newRoot->right = root;
    root->left = rightSubTree;

    return newRoot;
}

template<typename T>
TreeNode<T>* AVL<T>::leftRotate(TreeNode<T>*root) { 
    TreeNode<T>*newRoot = root->right;
    TreeNode<T>*leftSubTree = newRoot->left;

    // perform rotation
    newRoot->left = root;
    root->right = leftSubTree;
    return newRoot;
}

template<typename T>
void AVL<T>::insert(const T&item) {
    this->root = insert(this->root,item);
}

template<typename T>
TreeNode<T>* AVL<T>::insert(TreeNode<T>*current,const T&item) {
    if (current == nullptr) { 
        current = new TreeNode<T>(item);
        this->number_of_nodes += 1;
        return current;
    }
    
    if (current->data < item)
        current->right = insert(current->right ,item);
    else if(current->data > item)
        current->left = insert(current->left ,item);
    else return current; // no duplicate values

    int bf = getBalanceFactor(current);

    bool Is_left_heavy = (bf > 1);
    bool Is_right_heavy = (bf < -1);

    bool Is_left_left = (Is_left_heavy &&  item < current->left->data); 
    bool Is_right_right = (Is_right_heavy && item > current->right->data); 
    bool Is_Left_Right = (Is_left_heavy && item > current->left->data);
    bool Is_Right_Left = (Is_right_heavy && item < current->right->data);

    if (Is_left_left == true) return rightRotate(current);
    if (Is_right_right == true) return leftRotate(current);
    
    if (Is_Left_Right == true) {
        current->left = leftRotate(current->left);
        return rightRotate(current);
    } 
    if (Is_Right_Left == true) { 
        current->right = rightRotate(current->right);
        return leftRotate(current);
    }
    // no rotation (balance subtree) 
    return current;
}

template<typename T>
void AVL<T>::remove(const T&item) {
    this->root = remove(this->root , item);
}

template<typename T>
TreeNode<T>* AVL<T>::remove(TreeNode<T>*current,const T&item) {
    if (current == nullptr)
        return current;
    
    if (current->data < item)
        current->right = remove(current->right,item);
    else if (current->data > item)
        current->left = remove(current->left,item);
    else {
        // we found the item will be deleted

        bool hasLeftChild = (current->right == nullptr);
        bool hasRightChild = (current->left == nullptr);

        if (hasLeftChild == true) { 
            TreeNode<T>* ret = current->left;
            delete current;
            current = nullptr;

            return ret;
        }
        else if (hasRightChild == true) { 
            TreeNode<T>* ret = current->right;
            delete current;
            current = nullptr;

            return ret;
        }
        else {
            TreeNode<T>* mxCh = this->getMax(current->left);
            current->data = mxCh->data;

            current->left = remove(current->left , current->data);
        }
    }


    --(this->number_of_nodes);

    int bf = getBalanceFactor(current);

    bool isLeftHeavy = (bf == 2) , isRightHeavy = (bf == -2);
    if (isLeftHeavy == true) { 

        if (getBalanceFactor(current->left) >= 0) // is left left
            return rightRotate(current);
        else // is left right
            current->left = leftRotate(current->left);

        return rightRotate(current);

    }
    else if (isRightHeavy == true) {

        if (getBalanceFactor(current) <= 0)
            return leftRotate(current);
        else 
            current->right = rightRotate(current->right);

        return leftRotate(current);
    }
    else return current;

}
// ================== AVL Tree End ====================