// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

vector<int> Dijkstra(vector<pair<int, int>> adj[], int s, int sz) {

    vector<int> dis(sz, INT_MAX);
    dis[s] = 0;

    priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    pq.push({0 , s});


    while (pq.empty() == false) {

        pair<int,int> top = pq.top();
        pq.pop();

        int from = top.second , cost = top.first;    
        
        if (dis[from] != cost)
            continue;

        for (auto to : adj[from])
        {
            int weight = to.second;
            if (dis[from] + weight < dis[to.first]) {
                dis[to.first] = dis[from] + weight;
                pq.push({dis[to.first] , to.first});
            }
        }
    }

    return dis;
}

int main() {

    int N , M;
    cin >> N >> M;
    vector<pair<int, int>> adj[N];
    
    int u, v, wt;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> wt;
        addEdge(adj, u, v, wt);
    }
    
    auto printGraph = [&] () -> void {
        
        for (int node = 0 ; node < N ; ++node) {
            cout << node << " { ";
        
            auto children = adj[node];
            for(auto& ch : children)
                cout << "(" << ch.first << " " << ch.second << ") ";
            
            cout << "}\n";
        }
        
    };
    cout << "============\n";

    auto dis = Dijkstra(adj , 0 , N);
    cout << "Output\n";
    for (int i = 0; i < N; i++)
        cout << i << ' ' << dis[i] << endl;

    return 0;
}