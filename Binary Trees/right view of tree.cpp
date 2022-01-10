vector<int> ans;
    void dfs(Node *root,int level,int *maxLevel)
    {
        if(level>*maxLevel)
        {
          *maxLevel=level;
          
            ans.push_back(root->data);
        }
        
        if(root->right)
        {
            dfs(root->right,level+1,maxLevel);
        }
        
        if(root->left)
        {
            dfs(root->left,level+1,maxLevel);
            
        }
      
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        if(root==nullptr)return {};
        int maxLevel=-1;
       
        ans.clear();
        dfs(root,0,&maxLevel);
      
       return ans;
       
    }