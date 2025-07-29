class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int totalnodes = graph.size();
    vector<int> color(totalnodes, -1);  // -1 means uncolored

    for (int i = 0; i < totalnodes; i++) {
        if (color[i] == -1) {  // not yet visited
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = !color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

};