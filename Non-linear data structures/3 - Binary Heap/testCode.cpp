// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <stack>
#include "binaryHeap.h"

using namespace std;
using i64 = long long ;

int main() {
   // Here 
   vector<string> names = {"koko" , "temon" , "bomba" , "skar"};
   Heap<string>* h = new MaxHeap<string>(names);
   while (h->empty() == false) { 
      cout << h->top () << " - " << h->size() << "\n";
      h->pop();
   }

   cout << "======================\n\n";
   int ar[5] = {80,10,4,6,5000};
   MaxHeap<int> mxHeap(ar,5);

   while (mxHeap.size()) {
      cout << mxHeap.top() << endl;
      mxHeap.pop();
   }

   cout << "======================\n\n";
   
   vector<vector<string>> v = {
      {"Koko","Tom","Yasmeen"} ,
      {"temon","Ahmed"} ,
      {"bomba","CD"} ,
      {"skar","AB"}
   };

   // here is a comples structre
   Heap<vector<string>>* hp = new MaxHeap<vector<string>>(v);
   while (hp->size()) { 
      for (auto& vx : hp->top())
         cout << vx << " ";
      cout << endl;
      hp->pop();
   }

   cout << "\n============================\n\n";
   Heap<vector<string>>* hp_min = new MinHeap<vector<string>>(v);
   while (hp_min->size()) { 
      for (auto& vx : hp_min->top())
         cout << vx << " ";
      cout << endl;
      hp_min->pop();
   }
   cout << "\n============================\n\n";


   auto print = [](Heap<int>*heap)->void {
      while (heap->size()) {
         cout << heap->top() << " ";
         heap->pop();
      }
   };

   vector<int>nums = {55,99,6,-1,0,7,8,5};
   MinPriorityQueue<int> mn_pq(nums);
   print(&mn_pq);

   cout << "\n\n";
   MaxHeap<int>* mx_pq = new MaxPriorityQueue<int>(nums);
   print(mx_pq);
   cout << "\n\nThe End\n";
}