vector<int>ans;

void leftBoundary(Node *root)
{
    if(root==nullptr)
    return ;
    
    if(root->left)
    {
        ans.push_back(root->data);
        leftBoundary(root->left);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        leftBoundary(root->right);
    }
   
    
    
    
    
}
void leavesEnter(Node *root)
{
   
    if(root==nullptr)
    {
        return ;
    }
   
        leavesEnter(root->left);
    
     if(!(root->left)&&!(root->right))
    {
        ans.push_back(root->data);
       
    }
   
   
        leavesEnter(root->right);
        
    
    
    
}
void rightBoundary(Node *root)
{
    if(root==nullptr)
    {
        return ;
    }
    
    if(root->right)
    {
        rightBoundary(root->right);
        ans.push_back(root->data);
        
    }
    else if(root->left)
    {
        rightBoundary(root->left);
        ans.push_back(root->data);
        
    }
    return ;
    
    
}
    vector <int> boundary(Node *root)
    {
        if(root==nullptr)
        {
            return {};
        }
        //Clearing previous ans
        ans.clear();


        ans.push_back(root->data);
        
        //During left traversal we have to enter the value first in our traversal of left or right
        leftBoundary(root->left);
        //Check whether it have child or not 
        leavesEnter(root->left);
        leavesEnter(root->right);

        //During right traversal , we go in recursion again then enter the value .
        rightBoundary(root->right);
        
        return ans;
        
        
    }