vector <int> zigZagTraversal(Node* root){
    	// Code here
       vector<int>ans;
       queue<Node*>q;
       if(!root)
        return ans;
       q.push(root);
       int level=0;
       while(!q.empty())
       {
           int n=q.size();
           vector<int>k;
           while(n--)
           {
               Node *t=q.front();
               q.pop();
               k.push_back(t->data);
               if(t->left)
               q.push(t->left);
               if(t->right)
               q.push(t->right);
           }
           if(level%2!=0)
           reverse(k.begin(),k.end());
           for(int i=0;i<k.size();i++)
           {
               ans.push_back(k[i]);
           }
           level++;
       }
       return ans;
   }
