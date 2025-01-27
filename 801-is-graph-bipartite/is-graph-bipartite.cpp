class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col; // Assign color to the current node
        for (auto it : graph[node]) { // Traverse adjacent nodes
            if (color[it] == -1) { // If not colored
                if (!dfs(it, !col, color, graph)) return false; // Try coloring with the opposite color
            } else if (color[it] == col) { // If same color as current
                return false; // Graph is not bipartite
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1); // Initialize all nodes as uncolored (-1)
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) { // If the node is not yet visited
                if (!dfs(i, 0, color, graph)) return false; // Start DFS with color 0
            }
        }
        return true; // If no conflicts, the graph is bipartite
    }
};
