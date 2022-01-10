void helper(Node *root, Node* &head, Node* &tail) {
        if(!root) return;
        
        helper(root->left,head,tail);
        
        if(!head) {
            head = root;
            tail = root;
            tail->left = NULL;
        }
        
        else {
            // Node *temp = tail;
            tail->right = root;
            root->left = tail;
            tail = root;
        }
        helper(root->right,head,tail);
    }
    
    Node * bToDLL(Node *root)
    {
        // your code here
        Node *head = NULL;
        Node *tail = NULL;
        
        helper(root,head,tail);
        
        return head;
    }
