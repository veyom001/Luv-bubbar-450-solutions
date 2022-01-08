    

    int height(struct Node* node){

        //Checking if we are leave or not 
         if(node==NULL)return 0;
    
    //Level is atleast 1 if we aren't leave
    int ans1=1,ans2=1;
    
    //Finding max height of left child
    if(node->left)
    {
        ans1=1+height(node->left);
    }
    //Finding max height of right child
    if(node->right)
    {
        ans2=1+height(node->right);
        
    }
    
    //Return max height of from left or right child 
    return max(ans1,ans2);
        // code here 
    }