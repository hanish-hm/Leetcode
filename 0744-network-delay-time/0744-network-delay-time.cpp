class Solution {
private:
    // Dijkstra's algorithm to find the shortest time to reach all nodes
    int dijkstra(vector<vector<pair<int,int>>>& g, int source, int n){
        vector<int> vis(n+1, 0);            // Visited array to track processed nodes
        vector<int> dis(n+1, INT_MAX);      // Distance array, initialized to "infinity"

        set<pair<int, int>> st;             // Priority queue (min-heap), storing pairs (weight, vertex)
        st.insert({0, source});             // Start with the source node with distance 0
        dis[source] = 0;

        while (!st.empty()) {               // Process nodes until all reachable nodes are covered
            auto node = *st.begin();        // Get the node with the smallest distance
            int v = node.second;
            int wt = node.first;
            st.erase(st.begin());           // Remove the processed node

            if (vis[v]) continue;           // Skip if already visited
            vis[v] = 1;                     // Mark the node as visited

            for (auto child : g[v]) {       // Explore neighbors of the current node
                int child_v = child.first;  // Neighbor node
                int child_wt = child.second;// Weight of the edge to the neighbor

                // Relaxation step: Update the distance if a shorter path is found
                if (dis[v] + child_wt < dis[child_v]) {
                    dis[child_v] = dis[v] + child_wt;
                    st.insert({dis[child_v], child_v});  // Insert the updated distance into the set
                }
            }
        }

        int ans = 0;
        // Find the maximum distance from the source to any node
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;  // If any node is unreachable, return -1
            ans = max(ans, dis[i]);            // Track the maximum distance
        }

        return ans;  // The answer is the maximum distance found
    }

public:
    // Main function to calculate network delay time
    int networkDelayTime(vector<vector<int>>& vec, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);  // Graph representation: adjacency list

        // Building the graph from the edge list
        for(auto& temp : vec){
            g[temp[0]].push_back({temp[1], temp[2]});  // Directed edge from temp[0] to temp[1] with weight temp[2]
        }

        int ans = dijkstra(g, k, n);  // Run Dijkstra's algorithm from the source node k
        return ans;
    }
};