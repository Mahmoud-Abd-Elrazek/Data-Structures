// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

void heapfiy (vector<int>&heap , int pos , int heapSize) { // log(N)

   int lfCh = (pos << 1) + 1;
   int riCh = (pos << 1) + 2;

   int largChild = pos;

   if (lfCh < heapSize && heap[lfCh] > heap[largChild])
      largChild = lfCh;

   if (riCh < heapSize && heap[riCh] > heap[largChild])
      largChild = riCh;

   if (largChild != pos) { // this mean the parent is larger than ch1 and ch2
      int curr = heap[pos];
      heap[pos] = heap[largChild];
      heap[largChild] = curr;

      heapfiy(heap,largChild,heapSize);
   }
}

void HeapSort (vector<int>&ar) {
   int heapSize = ar.size();
   int start = (heapSize >> 1) - 1 ;

   // traverse all internal nodes to build heap
   for (int i = start ; i >= 0 ; --i) // O(N)
      heapfiy(ar,i,heapSize);

   vector<int>& heap = ar; // another name after buliding heap

   int N = ar.size();
   for (int i = N - 1 ; i >= 1 ; --i) { // N*log(N);
      int curr = heap[i];
      heap[i] = heap[0];
      heap[0] = curr;

      heapfiy(heap,0,i);
   }
}

int main() {

   vector<int> heap = {5,6,2,30,1,6,0};
   HeapSort(heap);
   for (auto&i : heap) { 
      cout << i << " " ; 
   }

}