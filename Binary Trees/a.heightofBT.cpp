int height(struct Node* node){
        // code here 
        if(node==NULL)
            return 0;
        else 
            return(1+max(height(node->left),height(node->right)));
        
    }
  hint: using recurssion; ez or wot!!
