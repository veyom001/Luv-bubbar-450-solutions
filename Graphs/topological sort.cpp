	

//Method 1 using stack
	stack<int>ans;
	
	void topo(int curr,vector<bool>&visited,vector<int>adj[])
	{
	    visited[curr]=true;
	    
	    for(auto child:adj[curr])
	    {
	        if(!visited[child])
	        {
	            topo(child,visited,adj);
	            
	        }
	        
	    }

	    ans.push(curr);
  
	    
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    vector<bool>visited(V+1,false);
	    
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            topo(i,visited,adj);
	        }
	        
	    }
	    
	    vector<int>Fans;
	    
	    int sz=ans.size();
	    for(int i=0;i<sz;i++)
	    {
	        auto it=ans.top();
	        ans.pop();
	        Fans.push_back(it);
	    }
	    return Fans;
   
	}


//Using In degrees 

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    vector<int>ans;
	    
	    vector<int>Indegrees(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            Indegrees[adj[i][j]]++;
	            
	        }
	    }
	    queue<int>q;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(Indegrees[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(q.size()>0)
	    {
	        int f1=q.front();
	        q.pop();
	        ans.push_back(f1);
	        
	        for(auto it:adj[f1])
	        {
	            Indegrees[it]--;
	            
	            if(Indegrees[it]==0)
	            {
	               q.push(it);
	                
	            }
	        }
	    }
	    return ans;
	    
	}