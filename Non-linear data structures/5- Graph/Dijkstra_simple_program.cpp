#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    static vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        
        const int N = adj.size();
        vector<int> distance(N + 1 , INF);
        
        bool visited[N+1];
        memset(visited,false,sizeof(visited));

        using minHeap = priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >;

        minHeap pq;
        pq.push({0,src});

        while (pq.empty() == false) 
        {
            pair<int,int> top = pq.top();
            pq.pop();

            int node = top.second , cost = top.first;
            
            if (visited[node] == true) 
                continue;
            
            visited[node] = true;
            distance[node] = cost;

            vector< pair<int,int> > children = adj[node];
            for (auto& ch : children) 
            {
                int v = ch.first , c = ch.second;
                if (visited[v] == false)
                    pq.push({cost + c , v});   
            }
        }

        return distance;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    cout << "Enter number of nodes and edges (in order): ";
    int N , M;
    cin >> N >> M;

    using edge = pair<int,int>; // (cost,node)
    vector<vector<pair<int, int>>> graph(N + 1);

    cout << "\nEnter weighted edges. as (from,to,cost)\n";

    int from,to,cost;
    for (int i = 1 ; i <= M ; ++i) { 
        cin >> from >> to >> cost;
        graph[from].push_back({to,cost});  
    }
    cout << "Compleated..\n\n";

    for (int node = 1; node <= N; ++node) {
        cout << "[ " << node << " ] -> { ";
        vector<edge> children = graph[node];
        for (auto& ch : children)
            cout << "(" << ch.first << "," << ch.second << ") "; 
        cout << "}\n";
    }

    cout << "\nLet go to apply Dijskra's algorithm\n\n";

    auto distance = Solution::dijkstra(graph , 1);

    for (int node = 1 ; node <= N ; ++node)
        if (distance[node] == INF)  
            cout << node << ": INF\n";
        else cout << node << ": " << distance[node] << '\n'; 

    return 0;
}
