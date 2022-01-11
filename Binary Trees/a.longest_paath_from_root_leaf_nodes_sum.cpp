void solve(Node* root,int h,int &mxh,int currSum,int &ans){
        if(!root){
            if(h >= mxh){
                ans = max(ans,currSum);
                mxh = h;
            }
            return;
        }
        solve(root->left,h+1,mxh,currSum + root->data,ans);
        solve(root->right,h+1,mxh,currSum + root->data,ans);
    }
    
    int sumOfLongRootToLeafPath(Node *root){
        int ans = 0;
        int mxh = 0,currSum = 0;
        solve(root,1,mxh,currSum,ans);
        return ans;
    }
