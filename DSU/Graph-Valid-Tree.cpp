class Solution {
public:
    int find(int x, vector<int>& parent)
    {
        // This finds the parent of a node
        // Uses path compression to flatten the tree
        // It makes future find calls, quicker

        // If the node is its own parent
        // return it
        if(x == parent[x])
            return x;
        // Recursively finds the parent[x] and stores it 
        // To make further searches quicker!
        return parent[x] = find(parent[x], parent);
    }
    bool merge(int x, int y, vector<int>& rank, vector<int>& parent)
    {
        // Get the parents of the 2 nodes
        int r1 = find(x, parent);
        int r2 = find(y, parent);

        // If they both point to the same parent
        // return false, as a merge couldn't be done
        if(r1 == r2) return false;

        // Otherwise merge it to the larger parent
        if(rank[r1] <= rank[r2])
        {
            rank[r2] += rank[r1];
            parent[r1] = r2;
        }
        else
        {
            rank[r1] += rank[r2];
            parent[r2] = r1;
        }
        // A merge was done
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // Connected acyclic graph is a tree
        // M1: Perform cycle detection using BFS
        // M2: Perform DSU

        // Edges must be n-1!
        if(edges.size() != n-1) return false;
        // if it's more it's a cyle
        // if it's less the grpah is disconnected


        // Disjoint Set Union has two functions
        // find
        // union
        // Must use a parent & rank arrays

        vector<int> parent(n, 0), rank(n, 1);

        //Initially all nodes are their own parents
        for(int i = 0;i<n;i++)
            parent[i] = i;
        
        // Assume the graph is disconnected and has n components
        
        // Iterate through every edge & if there'a a merge
        // reduce the no. of components
        int comp = n;

        for(auto& e: edges)
        {
            if(!merge(e[0], e[1], rank, parent))
                return false;
        }

        // A tree must have 1 connected componenet
        return true;
    }
};
