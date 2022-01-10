int height(Node *root){
       return (root==NULL)?0:(1+max(height(root->left),height(root->right)));
   }
    bool check(Node *root)
    {
        //Your code here
         if(root==NULL){
           return true;
       }
       
     int LH=height(root->left);
     int RH=height(root->right);

     if(LH && RH && LH!=RH)
         return false;
     
     else
         return (check(root->left)&&check(root->right));
        
    }
