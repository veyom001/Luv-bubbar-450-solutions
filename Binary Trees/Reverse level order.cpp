vector<int> reverseLevelOrder(Node *root)
{
    vector<vector<int>>helper;

//Initialising queue 
    queue<Node *>keeper;
    keeper.push(root);
    vector<int>curr;
    

//Applying level order BFS
    while(keeper.size())
    {
        
        int sz=keeper.size();
        vector<int>curr1;
        
        //Adding all elements of current level 
        for(int i=0;i<sz;i++)
        {
            auto it=keeper.front();
            keeper.pop();
            
            if(it->left)keeper.push(it->left);
            if(it->right)keeper.push(it->right);
            
            curr1.push_back(it->data);
            
        }
        helper.push_back(curr1);
        
    }
    
    //Storing ans and traversing from last inorder to reverse
    vector<int>ans;
    for(int i=helper.size()-1;i>=0;i--)
    {
        for(auto it:helper[i])
        {
            ans.push_back(it);
            
        }
    }
    return ans;
    
    
    // code here
}