   bool ContainCycle(int current,vector<bool>&visited,vector<bool>&recStack,vector<int>adj[])
    {
        if(visited[current]==false)
        {
            visited[current]=true;
            recStack[current]=true;
            
            for(auto it:adj[current])
            {
                if(!visited[it]&&ContainCycle(it,visited,recStack,adj))
                {
                    return true;
                }
                else if(recStack[it])
                {
                    return true;
                }
            }
            
            recStack[current]=false;
            return false;
            
        }
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       
     vector<bool>visited(V+1,false);
     vector<bool>recStack(V+1,false);
     
    for(int i=0;i<V;i++)
    {
        if(!visited[i]&&ContainCycle(i,visited,recStack,adj))
        {
            return true;
        }
    }
        
        return false;
        
    }