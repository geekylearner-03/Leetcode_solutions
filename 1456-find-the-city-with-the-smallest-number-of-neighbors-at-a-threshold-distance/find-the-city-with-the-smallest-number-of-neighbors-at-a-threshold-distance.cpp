class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;  // distance to itself is 0
        }

        // The distance between nodes which are connected temporary distance between them
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], dist = edge[2];
            distance[node1][node2] = dist;
            distance[node2][node1] = dist;
        }

        for (int midle = 0; midle < n; ++midle) {
            for (int source = 0; source < n; ++source) {
                for (int destination = 0; destination < n; ++destination) {
                    if (distance[source][midle] < INT_MAX && distance[midle][destination] < INT_MAX) {
                        distance[source][destination] = min(
                            distance[source][destination], distance[source][midle] + distance[midle][destination]
                        );  // the minimum distance is either current value or new value with path that goes through midle
                    }
                }
            }
        }

        int minimum_number = n;
        int res = -1;

        for (int source = 0; source < n; ++source) {
            int source_count = 0;
            for (int destination = 0; destination < n; ++destination) {
                if (distance[source][destination] <= distanceThreshold) {
                    ++source_count;
                }
            }

            if (source_count <= minimum_number) {  // as in dijkstra when number equal we choose greater node
                minimum_number = source_count;
                res = source;
            }
        }

        return res;
    }
};