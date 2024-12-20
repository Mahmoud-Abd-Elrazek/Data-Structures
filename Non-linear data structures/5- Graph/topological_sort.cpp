// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

void topoliogical_sort (vector<int> graph[],int source,vector<bool>&visited,stack<int>&sorting) {
    
    visited[source] = true;
    auto children = graph[source];
    for (auto&ch : children) 
        if (visited[ch] != true)
            topoliogical_sort(graph,ch,visited,sorting);
    
    sorting.push(source);
}

int main () {
    int N , M;
    cin >> N >> M;

    vector<int> graph[N];
    for (int i = 0 ; i < M ; ++i) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(N);
    for (int node = 0 ; node < N ;++node) 
        if (visited[node] == false)
            topoliogical_sort(graph,node,visited,st);
    
    cout << "\ntopoliogical sort: ";
    while (st.empty() == false) {
        cout << (char)(st.top() + 'A') << ' ';
        st.pop();
    }

    return 0;
}