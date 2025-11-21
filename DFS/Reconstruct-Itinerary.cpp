// Adj: map + min heap
// Push only after exploring all its edges
// Hierholzer's algorithm

class Solution {
public:
    void dfs(string src, vector<string>& itinerary, 
            unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj)
    {
        auto& pq = adj[src];

        while(!pq.empty())
        {
            string dest = pq.top();
            // Consume the edge
            pq.pop();
            
            dfs(dest, itinerary, adj);
        }
        // Push the results after you backtrack
        // Becasue we won't push prematurely if there is a dead end!
        itinerary.push_back(src);
        
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Perform dfs starting from JFK
        
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        for(auto& p: tickets)
            adj[p[0]].push(p[1]);

        
        vector<string> itinerary;
        // Initiate dfs from JFK
        dfs("JFK", itinerary, adj);

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;     
    }
};
