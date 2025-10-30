

class Solution {
public:
    // A map to keep track of original & cloned nodes
    // Helps prevent infinite recursion in case cycles are found
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        // Handle edge case
        if(!node) return node;

        //If a node is already cloned, return it
        if(mp.count(node)) return mp[node];

        // If it hasn't been cloned
        // Clone it & add it to the map
        Node* clone = new Node(node->val);

        //Add the cloned node to the map
        mp[node] = clone;

        //Recursively clone the neighbors
        for(Node* neighbor: node->neighbors)
            mp[node]->neighbors.push_back(cloneGraph(neighbor));
        
        // Return the cloned node
        return mp[node];

        
    }
};
