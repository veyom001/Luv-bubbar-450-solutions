int height(Node* root){
        // code here 
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(rh-lh)>1||lh==-1||rh==-1)
            return -1;
        return 1+max(lh,rh);
        
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int h = height(root);
        return h!=-1?true:false;
        
    }
