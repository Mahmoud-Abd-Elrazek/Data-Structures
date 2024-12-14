// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;

void PrintNeghbours (pair<int,int>edgeList[],int M,int node) { // print children O(M) time
    for (int i = 0 ; i < M ; ++i) {
        if (edgeList[i].first == node)
        cout << edgeList[i].second << " ";
        if (edgeList[i].second == node)
        cout << edgeList[i].first << " ";
    }
}
bool connected (pair<int,int>edgeList[],int M,int u , int v) { // check connectivity O(M) time
    for (int i = 0 ; i < M ; ++i) {
        if (edgeList[i].first == u && edgeList[i].second == v)
        return true;
        if (edgeList[i].first == v && edgeList[i].second == u)
        return true;
    }
    return false;
}
int main () {
    int N , M;
    cin >> N >> M ; // Read Number of nodes and number of edges

    pair<int,int>edgeList[M]; // O(M) space
    // Enter Number Of Nodes and Edges (In Oreder)

    // Enter Relations BTW Nodes.
    for (int i = 0 ; i < M ; ++i) {
        int U , V;
        cin >> U >> V;
        edgeList[i] = {U,V};
    } // end loop edges


    for (int i = 0 ; i < M ; ++i) { 
        cout << edgeList[i].first << " " << edgeList[i].second << "\n";
    }


    return 0;
}