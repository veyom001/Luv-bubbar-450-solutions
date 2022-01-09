    vector<int> preorderTraversal(TreeNode* root) {
    
        if(root==nullptr)
        {
            return {};   
        }
        stack<TreeNode *>st;
        st.push(root);
        
        vector<int>ans;
        
        while(st.size()>0)
        {
            auto it=st.top();
            st.pop();
            
            ans.push_back(it->val); 
            if(it->right)
            {
                st.push(it->right);
            }
            
            if(it->left)
            {
                st.push(it->left);
            }
        }
        return ans;

        
    }