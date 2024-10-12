// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// #include <bits/stdc++.h>
#include <iostream>
#include "M_WAY.h"
using namespace std;
using i64 = long long;
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

template<class T , int M>
class TreeNode { 
public:
    T values[M - 1];
    TreeNode* children[M];
    int i; 
    TreeNode() { 
        i = 0;

        for (int k = 0; k < M ; ++k)
            children[k] = NULL;
    }
    void add(T val) { 
        int start = i ; 
        for (int j = 0 ; j < i ; ++j) {
            if (val < values[j]) { 
                start = j;
                break;
            }
        }

        int temp = val;
        for (int j = start ; j <= i ; ++j) { 
            int cur = values[j];
            values[j] = temp;
            temp = cur;
        }
        i++;
    }
    bool full() const {return i == M;}
} ; 

template<class T , int M>
class mt { 
public:
    TreeNode<T,M>*root;
    void insert (TreeNode<T,M>*root,int val) {

        if (root->full()) {
  
        } 
        else { 
            
        }
    }
    bool empty () const { return this->root == nullptr;}
};
int main() {
    TreeNode<int,3>*root = new TreeNode<int,3>;
    
}