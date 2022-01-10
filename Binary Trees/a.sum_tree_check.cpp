bool ans=true;
    public:
    int fun(Node*root){
       
        int x=0,y=0;
        if(root->left ==NULL and root->right==NULL)
            return root->data;
        if(root->left) 
            x=fun(root->left);
        if(root->right) 
            y=fun(root->right);
       
        if(x+y==root->data)
            root->data+=x+y;
        else 
            ans=false;
        return 
            root->data;
       
   }
   bool isSumTree(Node* root)
   {
        int x= fun(root);
        return ans;
   }
