
vector<int>InorderTraverse;
void inorder(vector<int>&arr,int index,int sz)
{   
    if((2*index+1)<=sz)
    {
        inorder(arr,2*index+1,sz);
    }
    InorderTraverse.push_back(arr[index]);
 
    if((2*index+2)<=sz)
    {
        inorder(arr,2*index+2,sz);    
	}
 
}

int minimumSwaps(vector<int>&arr, int n) {
	// Write your code here.
     InorderTraverse.clear();
    inorder(arr,0,n-1);

    vector<pair<int,int>>findVal;   
    for(int i=0;i<n;i++)
    {
        findVal.push_back({InorderTraverse[i],i});
    }
    int ans=0;
    sort(findVal.begin(),findVal.end());
   
    for(int i=0;i<n;i++)
    {
		if(i==findVal[i].second)
        {
            continue;
        }
        else
        {
			swap(findVal[i].first,findVal[findVal[i].second].first);
            swap(findVal[i].second,findVal[findVal[i].second].second);         
        }
        
        if(i!=findVal[i].second)i--;
        ans++;
    }
    
    return ans;
 
}