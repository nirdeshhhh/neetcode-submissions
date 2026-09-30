class Solution {
public:

    void dfs(int node, vector<vector<int>>&adj, vector<int> &visited){
        visited[node] = 1;

        for(int i=0; i<adj[node].size(); i++){
            int neighbour = adj[node][i];

            if(visited[neighbour] == 0){
                dfs(neighbour, adj, visited);
            }
        }

    }


    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int> visited(n, 0);
        int count = 0;

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};
