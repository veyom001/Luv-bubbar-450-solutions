 void dfs(int currCom,vector<int>connect[],vector<bool>&visited)
    {
        
        if(visited[currCom])return;
        
        visited[currCom]=true;
        
        
        for(auto child:connect[currCom])
        {
            if(!visited[child])
            {
                dfs(child,connect,visited);
                
            }
            
        }
    
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        vector<int>connect[n];
        
        for(int i=0;i<connections.size();i++)
        {
            int f1=connections[i][0];
            int f2=connections[i][1];
            connect[f1].push_back(f2);
            connect[f2].push_back(f1);
        }
        
        
        
        if(connections.size()<n-1)
        {
            return -1;
            
        }
        else
        {
            vector<bool>visited(n,false);
            int countTot=0;
            
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    dfs(i,connect,visited);
                    
                    countTot++;
                    
                }
                    
            }
            
            return countTot-1;
            
        }
    }