#include <iostream>
#include <vector>

class MaxBipartiteMatch {
private:
    std::vector<std::vector<bool>> graph;
    int leftSetSize;
    int rightSetSize;

public:
    MaxBipartiteMatch(int n, int m) : leftSetSize(n), rightSetSize(m) {
        graph.assign(m, std::vector<bool>(n, false));
    }

    void addEdge(int u, int v) {
        graph[u][v] = true;
    }

    bool dfs(int u, std::vector<bool>& visited, std::vector<int>& match) {
        for (int v = 0; v < leftSetSize; v++) {
            if (!visited[v] && graph[u][v]) {
                visited[v] = true;
                if (match[v] == -1 || dfs(match[v], visited, match)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<int> findMaxMatching() {
        std::vector<bool> visited(leftSetSize, false);
        std::vector<int> match(leftSetSize, -1);

        for (int u = 0; u < rightSetSize; u++) {
            visited.assign(leftSetSize, false);
            dfs(u, visited, match);
        }

        return match;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    MaxBipartiteMatch matching(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int value;
            std::cin >> value;

            if (value == 1) {
                matching.addEdge(j, i);
            }
        }
    }

    std::vector<int> result = matching.findMaxMatching();

    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            std::cout << result[i] + 1 << " ";
        } else {
            std::cout << "-1 ";
        }
    }
    std::cout << std::endl;

    return 0;
}

