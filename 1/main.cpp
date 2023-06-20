#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>

using namespace std;

#define MAX_V 1000

int bfs(int rGraph[MAX_V][MAX_V], int s, int t, int parent[])
{
    bool visited[MAX_V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<MAX_V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return (visited[t] == true);
}
void dfs(int rGraph[MAX_V][MAX_V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < MAX_V; i++)
    {
        if (rGraph[s][i] && !visited[i])
        {
            dfs(rGraph, i, visited);
        }
    }
}
void Find_min_Cut_flow_network(int graph[MAX_V][MAX_V], int s, int t, int n)
{
    int u, v;
    int rGraph[MAX_V][MAX_V];
    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }
    int parent[MAX_V];
    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    bool visited[MAX_V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i] && !visited[j] && graph[i][j])
            {
                cout << i << " - " << j << endl;
            }
        }
    }
 
    return;
}
int main()
{
    int n;
    int s;
    int t;
    cin >> n ;
    cin >> s ;
    cin >> t ;
    int graph[MAX_V][MAX_V];
    memset(graph, 0, sizeof(graph));
    while (true)
    {
        int u;
        int v;
        int w;
        cin >> u;
        if (u == -1) 
        {
            break;
        }
        cin >> v;
        cin >> w;
        graph[u][v] = w;
    }
    Find_min_Cut_flow_network(graph, s, t, n);
    return 0;
}

