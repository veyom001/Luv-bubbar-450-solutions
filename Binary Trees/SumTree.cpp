 int SumTree(Node *node)
  {
      if(node==nullptr)
      {
          return 0;
      }
      
      int leftSum=0;
      int rightSum=0;
      
      if(node->left)
      {
          leftSum=node->left->data+SumTree(node->left);
          
      }
      
      if(node->right)
      {
          rightSum=node->right->data+SumTree(node->right);
      }
      
      node->data=leftSum+rightSum;
      
      return leftSum+rightSum;
      
  }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        
        if(node==nullptr)
        {
          
            return ;
        }
        
        int rootSum=SumTree(node);

        // Your code here
    }