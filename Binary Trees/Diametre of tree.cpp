class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(struct Node *root)
{
    if(!root)return 0;
    int ans1=0,ans2=0;



    if(root->left)ans1=height(root->left);
    
    if(root->right)ans2=height(root->right);
    return max(ans1,ans2);
    
}
    int diameter(Node* root) {
        // Your code here
        
        if(!root)return 0;

        //Finding heights. i.e left children and right children 
        int lheight=height(root->left);
        int rheight=height(root->right);

        //Finding diametre of left child and right child .
        int ldiameter=diameter(root->left);
        int rdiameter=diameter(root->right);
        
    
        return max(lheight+rheight+1,max(ldiameter,rdiameter));
        
    }
};
