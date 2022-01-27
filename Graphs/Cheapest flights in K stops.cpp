 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

         vector<int>graph1[n+1];
 
        map<pair<int,int>,int>values;
        for(int i=0;i<flights.size();i++)graph1[flights[i][0]].push_back(flights[i][1]),values[{flights[i][0],flights[i][1]}]=flights[i][2];
        int used=k;
        
        dist[src]=0;
        
        queue<pair<int,int >>keeper;
        keeper.push({0,src});
        int ans=INT_MAX;
        
            
        while(used>=0&&keeper.size()>0)
        {
            int sz=keeper.size();
            
            for(int i=0;i<sz;i++)
            {   
                auto it=keeper.front();
                keeper.pop();
                
                
                for(auto it2:graph1[it.second])
                {
                    if(ans<(it.first+values[{it.second,it2}]))continue;
                    
                    keeper.push({it.first+values[{it.second,it2}],it2});
                    
                    if(dst==(it2))
                        ans=min(ans,it.first+values[{it.second,it2}]);
                    
                }
            }
            used--;
            
        }
        return ans==INT_MAX?-1:ans;
    }