#ifndef TRIE_INCLUDED_HEADER
#define TRIE_INCLUDED_HEADER


#include<iostream>
#include<string>
#include<map>

using namespace std;

class TrieNode {
public:
   map<char,TrieNode*>children;
   bool isLeaf;
   int prefixes,wordCounter;

   TrieNode();
};

class Trie {
   TrieNode* root;
public:
   Trie();
   void insert(const string&);
   bool search(const string&);
   bool isPrefix(const string&);
   int count_prefix(const string&);
   int count_word(const string&);
};

#endif //TRIE_INCLUDED_HEADER