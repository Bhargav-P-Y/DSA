class Solution {
public:
    int find(int x, vector<int>& parent)
    {
        // If the node is equal to its own parent
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }
    bool merge(int u, int v, vector<int>& parent, vector<int>& rank)
    {
        int rootU = find(u, parent);
        int rootV = find(v, parent);

        // If both nodes point to the same parent
        // It means they belong to the same component
        if(rootU == rootV)
            return false;
        
        // Otherwise merge the smaller one into the bigger
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
        // A merge happened
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // Assume the graph as n componenets
        // If we can merge subtract
        // return remaining
        vector<int> parent(n, 0), rank(n, 1);

        // Initialize every node to be its own parent
        for(int i = 0;i<n;i++)
            parent[i] = i;
        
        int comp = n;
        
        // Iterate through every edge
        // If there is a merge subtract the no. of comps

        for(auto& edge: edges)
        {
            int u = edge[0], v = edge[1];

            if(merge(u, v, parent, rank))
                comp -=1;
        }

        // Number of connected components
        return comp;

    }
};
