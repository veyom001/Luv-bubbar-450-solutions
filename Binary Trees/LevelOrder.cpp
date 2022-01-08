#include<bits/stdc++.h>
using namespace std;


struct TreeNode {


	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int data)
	{
		this->val=data;
		left=NULL;
		right=NULL;
		

	}

};


//Iterative
vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        if(!root)
        return vector;
        stack<TreeNode *> stack;
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode *pNode = stack.top();
            if(pNode->left)
            {
                stack.push(pNode->left);
                pNode->left = NULL;
            }
            else
            {
                vector.push_back(pNode->val);
                stack.pop();
                if(pNode->right)
                stack.push(pNode->right);
            }
        }
        return vector;
    }



///To Check if both tree's are mirror of one another or not 

      bool findAns(TreeNode *current1,TreeNode *current2)
    {
        if(!current1&&!current2)return true;
        
        if(!current1||!current2)return false;
        
        if(current1->val!=current2->val)return false;
        
        return findAns(current1->left,current2->right)&&findAns(current1->right,current2->left);
 
    }
    
    
    bool isSymmetric(TreeNode* root) {
      
        bool ans=findAns(root->left,root->right);
       return ans;
  
    }



    // To convert a array into BST 

        TreeNode* sortedArrayToBST(vector<int>& nums) {
     
        if(nums.size()==0)return nullptr;
        
        if(nums.size()==1)
        {
            return new TreeNode(nums[0]);    
        }
        
        int middle=(nums.size())/2;
        
        TreeNode *root=new TreeNode(nums[middle]);
        
        vector<int>leftAns(nums.begin(),nums.begin()+middle);
        vector<int>rightAns(nums.begin()+middle+1,nums.end());
        
        root->left=sortedArrayToBST(leftAns);
        root->right=sortedArrayToBST(rightAns);
        
        return root;
        
        
    }

    // Minimum depth of the binary tree 
    // DIstance from root to node with minimum distance 

     int minDepth(TreeNode* root) {
        
        queue<TreeNode *>helper;
        if(!root)return 0;
        
        helper.push(root);
        
        int ans=1;
        
        while(helper.size()>0)
        {
            
            auto sz=helper.size();
        
            for(int i=0;i<sz;i++)
            {
         
            auto it=helper.front();
           helper.pop();
                if(!it->left&&!it->right)return ans;
                
                if(it->left){helper.push(it->left);}
         
            if(it->right){helper.push(it->right);}
        
            }
  
            ans++;
      
        }
        return ans;
volatile =1;

    }