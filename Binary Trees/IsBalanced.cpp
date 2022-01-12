   bool ans=true;
    
    int maximumHeight(TreeNode* root)
    {
        if(!root)return 0;   
        int ans1=1+maximumHeight(root->left);
        int ans2=1+maximumHeight(root->right);
        if(abs(ans1-ans2)>=2){
            ans=false;   
        }   
        return max(ans1,ans2);
    }
    
    bool isBalanced(TreeNode* root) {
        maximumHeight(root);
        return ans;    
    }