struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
     Node (int data)
     {
          this->data = data;
          left = right = NULL;
     }
};
void inOrder(struct Node *root)
{
     stack<Node *> s;
     Node *curr = root;

     while (curr != NULL || s.empty() == false)
     {
          while (curr !=  NULL)
          {
               s.push(curr);
               curr = curr->left;
          }
          curr = s.top();
          s.pop();

          cout << curr->data << " ";
          curr = curr->right;

     }
}
void Preorder(node* root)
{
     if (root == NULL)
          return;

     stack<node*> nodeStack;
     nodeStack.push(root);

     while (nodeStack.empty() == false)
     {
          struct node* node = nodeStack.top();
          cout << node->data << " ";
          nodeStack.pop();

          if (node->right)
               nodeStack.push(node->right);
          if (node->left)
               nodeStack.push(node->left);
     }
}
void postOrderIterative(Node* root)
{
     if (root == NULL)
          return;
     stack<Node *> s1, s2;

     s1.push(root);
     Node* node;

     while (!s1.empty()) {

          node = s1.top();
          s1.pop();
          s2.push(node);

          if (node->left)
               s1.push(node->left);
          if (node->right)
               s1.push(node->right);
     }

     while (!s2.empty()) {
          node = s2.top();
          s2.pop();
          cout << node->data << " ";
     }
}
