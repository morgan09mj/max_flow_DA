using System;
using System.Collections.Generic;
using System.Linq;

class EdmondsKarp
{
    private int[,] graph;
    private int[] parent;
    private int verticesCount;

    public EdmondsKarp(int[,] capacity, int verticesCount)
    {
        this.graph = capacity;
        this.verticesCount = verticesCount;
    }

    private bool BFS(int[,] residualGraph, int source, int sink)
    {
        bool[] visited = new bool[verticesCount];
        parent = new int[verticesCount];
        for (int i = 0; i < verticesCount; i++)
            visited[i] = false;

        Queue<int> queue = new Queue<int>();
        queue.Enqueue(source);
        visited[source] = true;
        parent[source] = -1;

        while (queue.Count > 0)
        {
            int u = queue.Dequeue();

            for (int v = 0; v < verticesCount; v++)
            {
                if (visited[v] == false && residualGraph[u, v] > 0)
                {
                    queue.Enqueue(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }

        return visited[sink];
    }

    public int FindMaxFlow(int source, int sink)
    {
        int[,] residualGraph = new int[verticesCount, verticesCount];

        for (int i = 0; i < verticesCount; i++)
        {
            for (int j = 0; j < verticesCount; j++)
            {
                residualGraph[i, j] = graph[i, j];
            }
        }

        int maxFlow = 0;

        while (BFS(residualGraph, source, sink))
        {
            int pathFlow = int.MaxValue;

            for (int v = sink; v != source; v = parent[v])
            {
                int u = parent[v];
                pathFlow = Math.Min(pathFlow, residualGraph[u, v]);
            }

            for (int v = sink; v != source; v = parent[v])
            {
                int u = parent[v];
                residualGraph[u, v] -= pathFlow;
                residualGraph[v, u] += pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }
}

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int verticesCount = int.Parse(input[0]);
        int edgesCount = int.Parse(input[1]);

        int[,] capacity = new int[2 * verticesCount, 2 * verticesCount];

        for (int i = 0; i < edgesCount; i++)
        {
            string[] edge = Console.ReadLine().Split(' ');
            int u = int.Parse(edge[0]) - 1;
            int v = int.Parse(edge[1]) - 1;
            int c = int.Parse(edge[2]);
            capacity[2 * u + 1, 2 * v] = c;
        }

        string[] flowCapacities = Console.ReadLine().Split(' ');
        for (int i = 0; i < verticesCount; i++)
        {
            int node = i + 1;
            int c = int.Parse(flowCapacities[i]);
            capacity[2 * (node - 1), 2 * (node - 1) + 1] = c;
        }

        string[] sourceSink = Console.ReadLine().Split(' ');
        int source = int.Parse(sourceSink[0]) - 1;
        int sink = int.Parse(sourceSink[1]) - 1;

        EdmondsKarp ek = new EdmondsKarp(capacity, verticesCount * 2);
        int maxFlow = ek.FindMaxFlow(2 * source, 2 * sink + 1);

        Console.WriteLine(maxFlow);
    }
}
