 bool ans=true;
    
    int findSum(Node *root)
    {
        
        if(root==nullptr)
        {
            return 0;
        }
        
        int leftSum=0,rightSum=0;
        
        if(root->left)
        {
            leftSum=root->left->data+findSum(root->left);
        }
        
        if(root->right)
        {
            rightSum=root->right->data+findSum(root->right);
        }
        if(leftSum+rightSum==0)
        {
            return 0;
            
        }
        ans=ans&((rightSum+leftSum)==root->data);
        return leftSum+rightSum;
    }
    bool isSumTree(Node* root)
    {
        ans=true;
        if(root==nullptr)
        {
            return true;
        }
        findSum(root);
        return ans;

    }