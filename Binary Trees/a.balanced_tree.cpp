 int height(Node *root){
       return (root==NULL)?0:(1+max(height(root->left),height(root->right)));
   }
   
   bool isBalanced(Node *root)
   {
       if(root==NULL){
           return true;
       }
       
     int LH=height(root->left);
     int RH=height(root->right);

     if(abs(LH-RH)>1)
         return false;
     
     else
         return (isBalanced(root->left)&&isBalanced(root->right));

   }
