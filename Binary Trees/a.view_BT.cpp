
1> LEFT VIEW

void recursion(Node* root,vector<int> &ans,int level){
    if(!root)
        return;
    if(ans.size()==level)
        ans.push_back(root->data);
    recursion(root->left,ans,level+1);
    recursion(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> ans;
    recursion(root,ans,0);
    return ans;
   
}

2> RIGHT VIEW

void recursion(Node* root,vector<int> &ans,int level){
    if(!root)
        return;
    if(ans.size()==level)
        ans.push_back(root->data);
    recursion(root->right,ans,level+1);
    recursion(root->left,ans,level+1);
}

vector<int> rightView(Node *root)
{
   // Your code here
    vector<int> ans;
    recursion(root,ans,0);
    return ans;   
}

3> TOP VIEW

vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) 
          return ans; 
        map<int,int> mp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mp.find(line) == mp.end()) mp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

4> BOTTOM VIEW

vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) 
          return ans; 
        map<int,int> mp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
