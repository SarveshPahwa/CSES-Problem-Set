#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, std::vector<int>& distance, std::vector<std::vector<int>>& graph) {
    for (int i : graph[node]) {
        if (i != parent) {
            distance[i] = distance[node] + 1;
            dfs(i, node, distance, graph);
        }
    }
}

std::vector<int> treeDistances(int n, std::vector<std::vector<int>> edges) {
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> distance(n + 1, 0);
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    dfs(1, 0, distance, graph);
    int node1, node2;
    int maxi = INT_MIN;
    for (int i = 1; i <= n; i++) {
        // std::cout << distance[i] << std::endl;
        if (distance[i] > maxi) {
            maxi = distance[i];
            node1 = i;
        }
    }
    distance.assign(n + 1, 0);
    dfs(node1, 0, distance, graph);
    maxi = INT_MIN;
    for (int i = 1; i <= n; i++) {
        // std::cout << distance[i] << std::endl;
        if (distance[i] > maxi) {
            maxi = distance[i];
            node2 = i;
        }
    }
    std::vector<int> distance2(n + 1, 0);
    dfs(node2, 0, distance2, graph);
    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
        // std::cout << distance2[i] << std::endl;
        ans.push_back(std::max(distance2[i], distance[i]));
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        edges[i] = {u, v};
    }

    std::vector<int> distances = treeDistances(n, edges);
    for (int i = 0; i < distances.size(); i++) {
        std::cout << distances[i] <<" ";
    }

    return 0;
}
