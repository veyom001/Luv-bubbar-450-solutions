vector<int> bfsOfGraph(int V, vector<int> adj[]) {
     
        vector<int>ans;
        vector<bool>visited(V+1,false);
        
        queue<int>q;
        q.push(0);
        ans.push_back(0);
        
        while(q.size()>0)
        {
            int frnt=q.front();
            q.pop();
        
            for(auto child:adj[frnt])
            {
                if(!visited[child])
                {
                    q.push(child);
                    ans.push_back(child);
                    visited[child]=true;
                }
            }
        }
        return ans;
 
    }