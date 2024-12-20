// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000000;

static int speedUp=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
   #endif
return 0;
}();

vector<int> graph[1000];
int dis[1000+10];
const int INF = 0x3f3f3f3f;
int main () {

   int N,M;
   cin >> N >> M; // number of nodes and number of edges

   // Read Input
   for (int i = 0 ; i < M ; ++i) { 
      int from,to,weight;
      cin >> from >> to >> weight;
      from--;
      to--;
      graph[i].push_back(from);
      graph[i].push_back(to);
      graph[i].push_back(weight);
   }

   // Step 1: Initialize distances
   memset(dis,INF,sizeof(dis));
   int start = 0;
   dis[start] = 0;

   // Step 2: Relax all edges |V| - 1 times
   for (int i = 0; i < N - 1; ++i) {
      int j = 0;
      while (graph[j].size()) {
         int from = graph[j][0];
         int to = graph[j][1];
         int weight = graph[j][2];

         if (dis[from] + weight < dis[to])
            dis[to] = dis[from] + weight;
         ++j;
      }
   }

   // Step 3: Check for negative weight cycles
   for (int j = 0; j < M; j++) {
         int from = graph[j][0];
         int to = graph[j][1];
         int weight = graph[j][2];

      if (dis[from] != INF && dis[from] + weight < dis[to]) {
         cout << "Graph contains a negative weight cycle\n";
         return 0;
      }
   }

   // Print shortest distances
   for (int i = 0 ; i < N ; ++i)
      cout << i << " " << dis[i] << endl;

   return 0;
}