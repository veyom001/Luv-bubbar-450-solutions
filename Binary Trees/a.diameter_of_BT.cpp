int height(struct Node* root){
    if(!root)
        return 0;

    else
        return (1+max(height(root->left),height(root->right)));
}
int diameter(struct Node* root) {
    // code here
    if(!root)
        return 0;
    int left_height=height(root->left);
    int right_height=height(root->right);

    int left_diameter=diameter(root->left);
    int right_diameter=diameter(root->right);
    
    return (max((left_height+right_height+1),max(left_diameter,right_diameter)));
}
