// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

class AdjacencyList {
public:
   int N , M;
   vector<int>*adjList;
   void ReadInptus () {
      // Enter Number Of Nodes and Edges (In Oreder)
      cin >> N >> M ;
      adjList = new vector<int>[N]; // O(M) space 

      // Enter Relations BTW Nodes.
      for (int i = 0 ; i < M ; ++i) {
         int U , V;
         cin >> U >> V;
         adjList[U].push_back(V);
         adjList[V].push_back(U);
      } // end loop edges
   } // end read function

   void PrintGraph () {
      for (int i = 0 ; i < N; ++i) {
         cout << i << " -> { " ;
         vector<int> neghbours = adjList[i];
         for (int j = 0 ; j < neghbours.size() ; ++j) {
            cout << neghbours[j]<<" ";
         } cout << "}\n";
      }
   }

   void printNeighbours (int node) {  // O(neighbours)
        for (auto& ch : adjList[node])
            cout << ch << " " ;
        cout << endl;
   }
};

int main () {



    return 0;
}