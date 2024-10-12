
#include"TRIE_HEADER_FILE.H"

TrieNode::TrieNode () {
   isLeaf = false;
   prefixes = 0;
   wordCounter = 0;
}

Trie::Trie() {
   root = new TrieNode();
}

void Trie::insert(const string&word) {

   TrieNode* current = root;

   for (auto&ch : word) {
      TrieNode* node = current->children[ch];
      
      if (node == nullptr) {
         node = new TrieNode();
         current->children[ch] = node;
      }

      current = node;
      current->prefixes += 1;
   }
   current->wordCounter += 1;
   current->isLeaf = true;
}

bool Trie::search(const string&word) {
   TrieNode* current = root;

   for (auto&ch : word) {
      TrieNode* node = current->children[ch];
      
      if (node == nullptr)
         return false;

      current = node;
   }
   return current->isLeaf;
}

bool Trie::isPrefix(const string&word){
   TrieNode* current = root;

   for (auto&ch : word) {
      TrieNode* node = current->children[ch];
      
      if (node == nullptr)
         return 0;

      current = node;
   }
   return true;
}

int Trie::count_prefix(const string&word) {

   TrieNode* current = root;

   for (auto&ch : word) {
      TrieNode* node = current->children[ch];
      
      if (node == nullptr)
         return 0;

      current = node;
   }
   return current->prefixes;
}

int Trie::count_word(const string&word) {
   TrieNode* current = root;
   for (auto& ch : word) { 
      TrieNode* node = current->children[ch];

      if (node == nullptr)
         return 0;

      current = node;
   }

   return current->isLeaf ? current->wordCounter : 0;
}
