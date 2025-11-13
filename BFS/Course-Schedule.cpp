// Start with the basics
// Put 100% effort to the course!

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build the indegree array & adjacency list
        for(auto p: prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]] +=1;
        }
            
        // Completed courses
        int completed = 0;
        
        queue<int> q;

        // Start with the courses that don't have any prerequisites
        for(int i = 0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        // Complete the courses
        // See if completing them unlocked you other courses
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            completed +=1;

            for(int c: adj[course])
            {
                if(--indegree[c] == 0)
                    q.push(c);
            }
        }
        return completed == numCourses;
    }
};
