// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include<iostream>
#include<vector>
#include<string>
#include "TRIE_HEADER_FILE.H"
using namespace std;

int main() {

   vector<string> wordList = {"cat","car","cam","camera","camera","camera","yo","you","youtube"};

   Trie tr;
   for(auto&word:wordList)
      tr.insert(word);

   cout << "Searchin about some words in a trie.\n";
   cout << tr.search("yo") << "\n";
   cout << tr.search("yoy") << "\n";
   cout << tr.search("cat") << "\n";
   cout << tr.search("you") << "\n";

   cout << "Cheacking about some prefixes are found or not ?\n";
   cout << tr.isPrefix("car") << "\n";
   cout << tr.isPrefix("ca") << "\n";
   cout << tr.isPrefix("yo") << "\n";
   cout << tr.isPrefix("you") << "\n";

   cout << "Counting some prefixes.\n";
   cout << tr.count_prefix("car") << "\n";
   cout << tr.count_prefix("ca") << "\n";
   cout << tr.count_prefix("yo") << "\n";
   cout << tr.count_prefix("you") << "\n";

   cout << "Counting frquancy of some words.\n";
   cout << tr.count_word("ca") << "\n";
   cout << tr.count_word("you") << "\n";
   cout << tr.count_word("youtube") << "\n";
   cout << tr.count_word("camera") << "\n";

   return 0;
}