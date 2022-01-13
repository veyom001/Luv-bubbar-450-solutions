map<string,int>checker;
    string solve(Node *root)
    {
        if(root==nullptr)
        {
            return "$";
        }
        
        string s="";
        
        if(root->left==nullptr&&root->right==nullptr)
        {
            s=to_string(root->data);
            
            return s;
            
        }
        
        s+=to_string(root->data);
        s+=solve(root->left);
        s+=solve(root->right);
        
        checker[s]++;
        return s;
    }
    
    int dupSub(Node *root) {
    
    checker.clear();
    solve(root);
    
    for(auto it:checker)
    {
        if(it.second>=2)return true;
    }
    return false;
    }