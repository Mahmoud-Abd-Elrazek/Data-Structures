// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <queue>
using namespace std;

class TreeNode { 
public:
    int val;
    TreeNode* left;
    TreeNode*right;
    TreeNode (int val) : val(val), left(nullptr), right(nullptr) {};
};
class AVL { 
    TreeNode* root;

    int height (TreeNode*root) { 
        if (root == nullptr)
            return 0;
        return 1 + max ( height (root->left) , height(root->right) );
    }

    int getBalnaceFactor (TreeNode*root) {
        if (root == nullptr)
            return 0;
        return height(root->left) - height(root->right);
    }

    TreeNode* rightRotate(TreeNode* root) { 

        TreeNode* newRoot = root->left;
        TreeNode* rightSubTree = newRoot->right;
        
        // perform rotation
        newRoot->right = root;
        root->left = rightSubTree;

        return newRoot;
    }

    TreeNode* leftRotate(TreeNode* root) { 
        TreeNode* newRoot = root->right;
        TreeNode* leftSubTree = newRoot->left;

        // perform rotation
        newRoot->left = root;
        root->right = leftSubTree;
        return newRoot;
    }

    TreeNode* insert (TreeNode* current , int item)  {
        if (current == nullptr) 
            return new  TreeNode(item);
        if (item > current->val)
            current->right = insert(current->right,item);
        else if (item < current->val)
            current->left = insert(current->left,item);
        else return current; // No duplication..


        int bf = getBalnaceFactor(current);

        if (bf > 1 && item < current->left->val) 
                return rightRotate(current);
        
        if (bf < -1 && item > current->right->val)
            return leftRotate(current);

        if (bf > 1 && item > current->left->val) {
            current->left = leftRotate(current->left);
            return rightRotate (current);
        }
            
        if (bf < -1 && item < current->right->val) { 
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }

        return current;
    }

    TreeNode* getMax (TreeNode* root) { 
        if (root->right == nullptr)
            return root;
        return getMax(root->right);
    }

    TreeNode* remove (TreeNode* current , int item) { 

        if (current == nullptr)
            return current; 

        if (item > current->val)
            current->right = remove(current->right , item);
        else if (item < current->val)
            current->left = remove(current->left , item);
        else 
        {
            if (current->right == nullptr) {
                TreeNode* ret = current->left;
                delete current;
                current = nullptr;
                return ret;
            }
            else if (current->left == nullptr) { 
                TreeNode* ret = current->right;
                delete current;
                current = nullptr;
                return ret;
            }
            else { 

                TreeNode* mxNode = getMax(current->left);
                current->val = mxNode->val;
                current->left = remove(current->left , item);
            }
        }
        
        int bf = getBalnaceFactor(current);
        
        // left left 
        if (bf > 1 && getBalnaceFactor(current->left) >= 0)
            return rightRotate(current);
             
        // left right
        if (bf > 1 && getBalnaceFactor(current->left) < 0)
        {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }

        // right right 
        if (bf < -1 && getBalnaceFactor(current->right) <= 0)
            return leftRotate(current);

        // right left 
        if (bf < -1 && getBalnaceFactor(current->right) > 0 )
        {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }

        return current;
    }

    bool search (TreeNode*current , int item) {
        if (current == nullptr)
            return false;

        if (item == current->val)
            return true;

        if (item <= current->val)
            return search(current->left , item);
        
        return search(current->right , item);
    }

    void dfs (TreeNode* current) { 
        if (current == nullptr) 
            return;

        cout << current->val << " ";
        dfs(current->left);
        dfs(current->right);
    } 
    void bfs (TreeNode*root) { 
        if (root == nullptr)
            return;

        queue<TreeNode*> qu;
        qu.push(root);

        while (qu.empty () == false) 
        {

            int level = qu.size();
            while (level--)  
            {
                TreeNode* front = qu.front();
                qu.pop();

                cout << front->val << " " ;
                if (front->left != nullptr)
                    qu.push(front->left);
                if (front->right != nullptr)
                    qu.push(front->right);
            } // end level

            cout << endl;
        } // end bfs
    }
public:
    AVL () : root(nullptr) {} ;
    
    void insert (int item) { root = insert(root , item);}

    void remove (int item)  {root = remove(root,item);}
    bool search (int item) { return search(root,item);}
    int height () { return height(root);}


    void dfs () { dfs(root);}

    void bfs () { bfs(root);}

};
int main () {

    int items [] = {10,5,12,6};

    AVL tree;

    for ( int  i = 0 ; i < sizeof(items) / sizeof(items[0]) ; i++) { 
        tree.insert(items[i]);
    }

    cout << tree.search(12) << endl;
    tree.remove(12);
    // tree.bfs();
    cout << "12 removed...\n";


    cout << tree.search(12) << endl;
    
    cout << "\n\nHegiht : " << tree.height() << endl;
    return 0;
}