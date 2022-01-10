vector<bool>visited(103,false);
vector<int>ans;
void dfs(Node *root,int level)
{
    if(!visited[level])
    {
        visited[level]=true;
        ans.push_back(root->data);
    }
    
    if(root->left)
    {
        dfs(root->left,level+1);
    }
    
    if(root->right)
    {
        dfs(root->right,level+1);
        
    }
  
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    for(int i=0;i<100;i++)
    visited[i]=false;
    
    ans.clear();

if(root==nullptr)
{
    return {};
    
}

   dfs(root,0);
   return ans;
}