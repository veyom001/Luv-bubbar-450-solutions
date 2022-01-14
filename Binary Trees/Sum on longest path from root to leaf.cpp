int sumOfLongRootToLeafPath(Node *root)
    {
     
        queue<pair<Node*,int>>helper;
        helper.push({root,root->data});
        int ans=0;
      while(helper.size()>0)
        {
            int sz=helper.size();
            
            int currLevelAns=0;
            
            for(int i=0;i<sz;i++)
            {
             auto it=helper.front();
             helper.pop();
             
             int currVal=it.second;
             currLevelAns=max(currLevelAns,currVal);
       
             if(it.first->left)
             {
                 helper.push({it.first->left,currVal+it.first->left->data});
             }
             
             if(it.first->right)
             {
                 helper.push({it.first->right,currVal+it.first->right->data});
                 
             }
     
            }
            ans=currLevelAns;
          
        }
        return ans;
        
    }