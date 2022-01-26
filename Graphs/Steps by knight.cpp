 vector<pair<int,int>>posMoves={{2,1},{2,-1},{1,2},{-1,2},{-2,1},{-2,-1},{1,-2},{-1,-2}};
    
    bool isSafe(int row,int column,bool visited[maxn][maxn],int N)
    {
        if(row<=0||column<=0||row>N||column>N||visited[row][column])
        {
            return false;
        }
        return true;
    }
    
    
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    
	    bool visited[maxn][maxn];
	    memset(visited,false,sizeof(visited));
	    
	    int countSteps=0;
	    
	    queue<pair<int,int>>helper;
	    helper.push({KnightPos[0],KnightPos[1]});
	    
	    bool found=false;
	    
	    
	    while(helper.size()>0)
	    {
	        
	        int totMoves=helper.size();
	        
	        for(int i=0;i<totMoves;i++)
	        {
	            int currRow=helper.front().first;
	            int currColumn=helper.front().second;
	            
	            if(currRow==TargetPos[0]&&currColumn==TargetPos[1])
	            {
	                found=true;
	                
	                break;
	            }
	           helper.pop();

	           if(visited[currRow][currColumn])
	           {
	               continue;
	           }
  
	            for(auto it:posMoves)
	            {
	                int newRow=it.first+currRow;
	                int newColumn=it.second+currColumn;
	                
	                if(isSafe(newRow,newColumn,visited,N))
	                {
	                    helper.push({newRow,newColumn});
	                    
	                    
	                }
	                
	            }
	            visited[currRow][currColumn]=true;
	            
	        }
	        
	        if(found)break;

	        countSteps++;
	        
	    }
	    
	    return countSteps;
   
	}