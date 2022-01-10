int helper(Node* node){
       int x,y,sum=0;
       if(node){
           x=helper(node->left);
           y=helper(node->right);
           sum=node->data+x+y;
           node->data=x+y;
           return sum;
       }
       return 0;
   }
    void toSumTree(Node *node){
       helper(node);
    }
