Node *constructTree(int *pre,int preStart,int preEnd,int *in,int inStart,int inEnd)
    {
        //Means ELement Finished . No more Available to Enter .
        if(preStart>preEnd||inStart>inEnd)
        {
            return NULL;   
        }
        
        //Creating current Node 
        int CurrentEle=pre[preStart];
        Node *root=new Node(CurrentEle);

        //Now we want to find its left and right child 
        
        int pos=preStart;
        //Let's find position of preStart element in the inorder.
        for(int i=inStart;i<=inEnd;i++)
        {
            if(CurrentEle==in[i])
            {
                pos=i;
                break;
            }
        }

        //So we have found the position .
        //Important thing to observe is that . Assume we have found the element at the distance k from inStart .
        //We have to see that first K elements in the preStart will be reserved for the left child and res for right Child.
        
        
        root->left=constructTree(pre,preStart+1,preStart+(pos-inStart),in,inStart,pos-1);
        root->right=constructTree(pre,preStart+(pos-inStart)+1,preEnd,in,pos+1,inEnd);
        return root;

    }
    Node* buildTree(int in[],int pre[], int n)
    {
    //We need InStart,Inend,preStart,preEnd in order to construct the tree .
       return constructTree(pre,0,n-1,in,0,n-1);
 
    }