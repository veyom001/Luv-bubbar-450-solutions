 int search(int *in,int x,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==x) return i;
        }
        return -1;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        if(n==0) return nullptr;
        int root=search(in,pre[0],n);
        Node *temp=new Node(pre[0]);
        temp->left=buildTree(in,pre+1,root);
        temp->right=buildTree(in+root+1,pre+root+1,n-root-1);
        return temp;
    }
