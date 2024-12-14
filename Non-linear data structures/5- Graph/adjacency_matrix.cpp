// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;

class AdjacencyMatrix
{
public:
    ~AdjacencyMatrix()
    {
        for (int i = 0; i < N; ++i)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
    int N, M;
    int **adjMatrix;
    void ReadInptus()
    {
        // Enter Number Of Nodes and Edges (In Oreder)
        cin >> N >> M;

        // creat 2d array
        adjMatrix = new int *[N];
        for (int i = 0; i < N; ++i) {
            adjMatrix[i] = new int[N];
        }

        // memset for 2D array
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                adjMatrix[i][j] = 0;

        // Enter Relations BTW Nodes.
        for (int i = 0; i < M; ++i)
        {
            int U, V;
            cin >> U >> V;
            adjMatrix[U][V] = adjMatrix[V][U] = 1;
        } // end loop edges
    } // end read function

    void PrintGraph() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << adjMatrix[i][j] << ' ';
            cout << "\n";
        }
    }

    void printNeighbours(int node) {
        for (int i = 0; i < N; ++i) {
            if (adjMatrix[node][i])
                cout << i << " ";
        }
        cout << "\n";
    }

    bool connected(int u, int v) {
        return adjMatrix[u][v] == 1;
    }
};
int main() {

    AdjacencyMatrix ob;
    ob.ReadInptus();
    ob.PrintGraph();
    
    return 0;
}