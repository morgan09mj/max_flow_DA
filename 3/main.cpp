#include <iostream>
#include <queue>
using namespace std;

class NetworkFlow {
private:
    int **graph;
    int *parent;
    int verticesCount;
    
public:
    NetworkFlow(int **capacity, int verticesCount) {
        this->graph = capacity; 
        this->verticesCount = verticesCount;
    }
    
    bool BFS(int **residualGraph, int source, int sink) {
        bool *visited = new bool[verticesCount];
        parent = new int[verticesCount];
        for (int i = 0; i < verticesCount; i++) 
            visited[i] = false;
            
        queue<int> q;  
        q.push(source); 
        visited[source] = true;
        parent[source] = -1;
            
        while(!q.empty()) {
            int u = q.front(); q.pop();
            
            for (int v=0; v<verticesCount; v++) {
                if (visited[v] == false && residualGraph[u][v] > 0) {
                    q.push(v);
                    visited[v] = true;  
                    parent[v] = u;
                }
            }
        }
        
        return visited[sink]; 
    } 
    
    int FindMaxFlow(int source, int sink) {
        // Same implementation as before
    }  
};

int main() { 
    int verticesCount, edgesCount;
    // Read verticesCount and edgesCount from input
    
    int **capacity = new int*[2 * verticesCount]; 
    // Initialize capacity matrix
    
    int source, sink;
    // Read source and sink from input
    
    NetworkFlow graph(capacity, verticesCount);   
    int maxFlow = graph.FindMaxFlow(source, sink);
    
    cout << maxFlow;
    
    delete[] capacity;
}
