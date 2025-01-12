/* =================================================================================================================== */
/* 
    Question  : Islands

                    An island is a small piece of land surrounded by water. 
                    A group of islands is said to be connected if we can reach 
                    from any given island to any other island in the same group. 
                    Given V islands (numbered from 0 to V-1) and E connections or 
                    edges between islands. Can you count the number of connected 
                    groups of islands.

                Input format : 
                        The first line of input contains two integers, that denote the 
                        value of V and E.

                        Each of the following E lines contains two integers, that denote 
                        that there exists an edge between vertex a and b. 

                Output Format : 
                        Print the count the number of connected groups of islands

                Constraints :  
                        0 <= V <= 1000
                        0 <= E <= (V * (V-1)) / 2
                        0 <= a <= V - 1
                        0 <= b <= V - 1

                        Time Limit: 1 sec

                Sample Input 1 :    
                        5 8
                        0 1
                        0 4
                        1 2
                        2 0
                        2 4
                        3 0
                        3 2
                        4 3
                                          
                Sample Output 1 :   
                        1

*/

// First Approach

#include <iostream>
#include <queue>
using namespace std;

void visitFiller(bool **edges, long long v, long long sv, bool *visited) {
    queue<long long> pendingVertices;
    pendingVertices.push(sv);

    visited[sv] = true;
    
    while (!pendingVertices.empty()) {
        for (long long i = 0; i < v; i++) {
            if (i == pendingVertices.front())
                continue;

            if (visited[i])
                continue;
            
            if (edges[pendingVertices.front()][i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }

        pendingVertices.pop();
    }
}

int main() {
    long long v, e;
    cin >> v >> e;
    
    bool **edges = new bool *[v];
    
    for (long long i = 0; i < v; i++) {
        edges[i] = new bool[v];

        for (long long j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }

    for (long long i = 0; i < e; i++) {
        long long start, end;
        cin >> start >> end;

        edges[start][end] = true;
        edges[end][start] = true;
    }

    bool *visited = new bool[v];
    
    for (long long i = 0; i < v; i++) {
        visited[i] = false;
    }

    int count = 0;
    
    for (long long i = 0; i < v; i++) {
        if (!visited[i]) {
            count++;
            visitFiller(edges, v, i, visited);
        }
    }

    cout << count;
    
    return 0;
}


// Optimized Approach [ C++ ( g++ 11 ) ]

/*
    Time complexity: O(V + E)
    Space complexity: O(V^2)
    
    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/

#include <iostream>
using namespace std;

void DFS(bool** graph, int v, bool* visited, int currentVertex) {
    visited[currentVertex] = true;
    
    for (int i = 0; i < v; ++i) {
        if (graph[currentVertex][i] && !visited[i]) {
            DFS(graph, v, visited, i);
        }
    }
}

int getIslandGroups(bool** graph, int v) {
    bool* visited = new bool[v]();
    int groupCount = 0;
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            DFS(graph, v, visited, i);
            ++groupCount;
        }
    }
    
    return groupCount;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    bool** graph = new bool*[v];
    
    for (int i = 0; i < v; ++i) {
        graph[i] = new bool[v]();
    }
    
    for (int i = 0, a, b; i < e; ++i) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    cout << getIslandGroups(graph, v);
    
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    
    delete[] graph;
}


// Optimized Approach [ C++ ( g++ 5.4 ) ]

/*
    Time complexity: O(V + E)
    Space complexity: O(V^2)
    
    where V is the number of vertices in the input graph and
    E is the number of edges in the input graph
*/

#include <iostream>
using namespace std;

void DFS(bool** graph, int v, bool* visited, int currentVertex) {
    visited[currentVertex] = true;
    
    for (int i = 0; i < v; ++i) {
        if (graph[currentVertex][i] && !visited[i]) {
            DFS(graph, v, visited, i);
        }
    }
}

int getIslandGroups(bool** graph, int v) {
    bool* visited = new bool[v]();
    int groupCount = 0;
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            DFS(graph, v, visited, i);
            ++groupCount;
        }
    }
    
    return groupCount;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    bool** graph = new bool*[v];
    
    for (int i = 0; i < v; ++i) {
        graph[i] = new bool[v]();
    }
    
    for (int i = 0, a, b; i < e; ++i) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    cout << getIslandGroups(graph, v);
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    
    delete[] graph;
}