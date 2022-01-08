vector<int> reverseLevelOrder(Node *node)
{
    // code here
    vector<int> ans;
      if(node==NULL) 
        return ans;
      queue<Node*> q;
      q.push(node);
      
      while(!q.empty()) {
          Node* front = q.front();
          q.pop();
          ans.push_back(front->data);
          if(front->right) 
            q.push(front->right);
          if(front->left) 
            q.push(front->left);
      }
      reverse(ans.begin(), ans.end());
      return ans;
}

hint: just insert right node first to queue and then left, at last return reverse of ans vector.
