void mirrorBinaryTree(Node* root) {
    if(!root)
    	return;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    swap(root->right,root->left);
}
