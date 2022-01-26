 

  bool isSafe(int row,int column,vector<vector<int>>m,int n,bool visited[][maxn])
    {
        if(row==-1||column==-1||row==n||column==n||visited[row][column]||m[row][column]==0)
        {
            return false;
        }
        return true;
        
    }
    vector<pair<int,int>>moves={{0,1},{0,-1},{1,0},{-1,0}};
    
    
    void printPathUtil(int row,int column,vector<vector<int>>m,int n,string &pathStore,vector<string>&FinalAns,bool visited[][maxn])
    {
        if(!isSafe(row,column,m,n,visited))
        {
            return ;
        }
        
        if(row==n-1&&column==n-1)
        {
            FinalAns.push_back(pathStore);
            return ;
        }
        
        visited[row][column]=true;
        
        
        for(auto it:moves)
        {
            int currRow=row+it.first;
            int currColumn=column+it.second;
            
            if(isSafe(currRow,currColumn,m,n,visited))
            {
                if(it.first==1)
                {
                    pathStore+='D';
                }
                else if(it.first==-1)
                {
                    pathStore+='U';
                    
                }
                else if(it.second==1)
                {
                    pathStore+='R';
                }
                else
                {
                    pathStore+='L';
                }
                
                printPathUtil(currRow,currColumn,m,n,pathStore,FinalAns,visited);
                pathStore.pop_back();
                
            }
            
        }

        visited[row][column]=false;
  
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>FinalAns;
        string pathStore;
        bool visited[n][maxn];
        
        memset(visited,false,sizeof(visited));
        
        printPathUtil(0,0,m,n,pathStore,FinalAns,visited);
        
        return FinalAns;
        
        
    }