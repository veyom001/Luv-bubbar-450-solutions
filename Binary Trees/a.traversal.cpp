
#Here are 3 types of traversals in BT

1>  INORDER

i)recursive

void inorder(node* root){
  if(!root)
    return;
  inorder(root->left);
  cout << root->data;
  inorder(root->right);
}


ii)iterative

void inorder(node* root){
    stack<node*> s;
 
    // start from the root node (set current node to the root node)
    Node* front = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!s.empty() || front != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (front != nullptr)
        {
            s.push(front);
            front = front->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            front = s.top();
            s.pop();
            cout << front->data << " ";
            front = front->right;
        }
    }
    
}


2>  PREORDER

i)recursive

void inorder(node* root){
  if(!root)
    return;
  cout << root->data;
  preorder(root->left); 
  preorder(root->right);
}

ii)iterative

void preorder(node* root){
    stack<node*> s;
 
    // start from the root node (set current node to the root node)
    s.push(root);
    
 
    // if the current node is null and the stack is also empty, we are done
    while (!s.empty())
    {
       // pop a node from the stack and print it
            node* front = s.top();
            s.pop();
            cout << front->data << " ";
        
            // push the right child of the popped node into the stack
            if (front->right) {
              s.push(front->right);
            }
 
            // push the left child of the popped node into the stack
            if (front->left) {
              s.push(front->left);
      }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
 
    }
}


2>  POSTORDER

i)recursive

void postorder(node* root){
  if(!root)
    return;
  postorder(root->left); 
  postorder(root->right);
  cout << root->data;
}

ii)iterative

void postorder(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* front = s.top();
        s.pop();
 
        cout<<front->data<< " ";
 
        // push the left and right child of the popped node into the stack
        if (front->left) {
            s.push(front->left);
        }
 
        if (front->right) {
            s.push(front->right);
        }
    }
}

