// Perform Union-Find 
// If nodes of an edge point to the same parent
// THen it is a redundant connection
// Because adding an edge to an already connected component
// forms a cycle

class Solution {
public:
    int find(int x, vector<int>& parent)
    {
        if(x != parent[x])
            parent[x] = find(parent[x], parent);
        return parent[x];
    }
    void merge(int u, int v, vector<int>& parent, vector<int>& rank)
    {
        int rootU = find(u, parent);
        int rootV = find(v, parent);

        if(rank[rootU] <= rank[rootV])
        {
            parent[rootU] = rootV;
            rank[rootV] += rank[rootU];
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU] += rank[rootV];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       

        vector<int> extra;
        int n = edges.size();
        vector<int> parent(n+1, 0), rank(n+1, 1);

        for(int i = 0;i<=n;i++)
            parent[i] = i;

        for(auto& edge: edges)
        {
            int u = edge[0], v = edge[1];
            if(find(u, parent) == find(v, parent))
                extra = {u, v};
            else
                merge(u, v, parent, rank);
        }
        return extra;
        
    }
};
