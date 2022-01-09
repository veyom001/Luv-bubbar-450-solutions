    vector<int> postorderTraversal(TreeNode* root) {
        
        //Storing root
        if(root==nullptr)
        {
            return {};
        }
        stack<TreeNode*>keeper;
        
        //Storing postorder traversal
        stack<int>out;
        //To store ans
        vector<int>ans;
        
        keeper.push(root);
        
        while(keeper.size()!=0)
        {
            auto curr=keeper.top();
            keeper.pop();
            out.push(curr->val);
            
            if(curr->left)
            {
                keeper.push(curr->left);
            }
            
            if(curr->right)
            {
                keeper.push(curr->right);
            }
       
        }
        
        while(out.size()>0)
        {
            ans.push_back(out.top());
            out.pop();
        }
        
        return ans;

    }