vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      if(node==NULL) 
        return ans;
      queue<Node*> q;
      q.push(node);
      
      while(!q.empty()) {
          Node* front = q.front();
          q.pop();
          ans.push_back(front->data);
          if(front->left) 
            q.push(front->left);
          if(front->right) 
            q.push(front->right);
      }
      return ans;
      
    }

Hint: use queue to push tree parent and print its data and then push left node and then right node in eacj iteration to the queue.
