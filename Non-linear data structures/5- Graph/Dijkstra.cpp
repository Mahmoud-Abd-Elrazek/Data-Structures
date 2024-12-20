// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

static int speedUp=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
   #endif
return 0;
}();

vector<pair<i64,i64>> adjList[N];
bool visited[N];
i64 dis[N];
int n , m;
// Dijkstra algorithm
void Dijkstra(int start) { 

    // cost , node
    priority_queue< pair<i64,i64>, vector<pair<i64,i64>> , greater<pair<i64,i64>> > pq;
    
    pq.push({0,start});

    while (!pq.empty()) { 
        pair<i64,i64> p = pq.top();
        pq.pop();

        i64 node = p.second , cost = p.first;

        if (visited[node] == true) continue;

        visited[node] = true;
        dis[node] = cost;

        for (auto& it : adjList[node]) { 
            i64 a = it.first , b = it.second;
            if (!visited[a]) 
            pq.push({ cost + b , a});
        } // end children
    } // end algorithm

}
int main () {

    cin >> n >> m;
    for (int i = 1 ; i <= m ; ++i) { 
      int u , v , c; // u, v, cost
      cin >> u >> v >> c;

      adjList[u].push_back({v,c});
    }

    int start = 1;
    Dijkstra (start);

    for (int i = 1 ; i <= n;++i) 
        cout << dis[i] << " " ;

    cout << "\n";
   return 0;
}