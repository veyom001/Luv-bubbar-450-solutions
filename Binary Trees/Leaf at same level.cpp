    bool check(Node *root)
    {
        queue<Node*>helper;
        
        helper.push(root);
        
        bool ans=true;
        bool found=false;
        int level=0;
        int foundLevel=0;
        while(helper.size()!=0)
        {
            int sz=helper.size();
            
            
            for(int i=0;i<sz;i++)
            {
                auto frontEle=helper.front();
                helper.pop();
                if(frontEle->left==nullptr&&frontEle->right==nullptr)
                {
                    if(found)
                    {
                        if(level!=foundLevel)
                        {
                            return false;
                        }
                  
                    }
                    else
                    {
                        foundLevel=level;
                        
                        found=true;
                        
                    }
                   
                }
                
                if(frontEle->left)
                {
                    helper.push(frontEle->left);
                }
                
                if(frontEle->right)
                {
                    helper.push(frontEle->right);
                    
                }
     
            }
            level++;
        }
        return true;
    }