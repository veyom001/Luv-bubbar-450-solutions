vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> pre;
    vector<int>in;
    vector<int>post;
    
    stack<pair<BinaryTreeNode<int> *,int> > s;
    s.push({root,1});
    
    if(root==NULL)
        return ans;
    while(!s.empty()){
        pair<BinaryTreeNode<int> *,int> temp=s.top();
        s.pop();
        
        if(temp.second==1){
            pre.push_back(temp.first->data);
            temp.second++;
            s.push(temp);
            
            if(temp.first->left!=NULL){
                s.push({temp.first->left,1});
            }
        }
        else if(temp.second==2){
            in.push_back(temp.first->data);
            temp.second++;
            s.push(temp);
            
            if(temp.first->right!=NULL){
                s.push({temp.first->right,1});
            }
        }
        else{
            post.push_back(temp.first->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    
    
    return ans;
}
