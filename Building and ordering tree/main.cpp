#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////problem 1
struct Node {
    int key;
    struct Node *left, *right;
};
// create a new node
Node* newNode(int data)
{
    Node* n = new Node;
    n->key = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/////// insert node
Node* insert(Node* root, int key)
{
    Node* newnode = newNode(key);
    Node* x = root;
    Node* y = NULL;

    while (x != NULL) {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    // If the root is null, the new node is the root
    if (y == NULL)
        y = newnode;
    // If the new key is less than the leaf node , the new node is left child. if not, the new node is right child
    else if (key < y->key)
        y->left = newnode;
    else
        y->right = newnode;
    return y;
}

//delete a node
Node* deleteNode(Node* root, int k)
{
    if (root == NULL)
        return root;
    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
    //// the root is the one is going to be deleted

    if (root->left == NULL) {
        Node* z = root->right;
        delete root;
        return z;
    }
    else if (root->right == NULL) {
        Node* z = root->left;
        delete root;
        return z;
    }
    else {
        Node* sParent = root;

        // Find successor
        Node* s = root->right;
        while (s->left != NULL) {
            sParent = s;
            s = s->left;
        }

        // Delete successor.
        if (sParent != root)
            sParent->left = s->right;

        // put Successor into root
        root->key = s->key;

        // Delete Successor and return root
        delete s; return root;
    }
}

// traversal inorder (left/root/right)
void inorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        inorder(root->left);
        cout << root->key << endl;
        inorder(root->right);
    }
}

// traversal postorder (left/right/root)
void postorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << endl;
    }
}

// traversal preorder (root/left/right)
void preorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        cout << root->key << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    /* lets build that tree
             5
          /     \
        3        7
       /  \     / \
       2   4   6   8  */

///////////////////// insert node
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    ////////////////// display inorder traverse
    cout << "In order traversal of the tree is "<<endl;
    inorder(root);
    //////////////////// display postorder traverse
    cout << " post order traversal of the tree is "<<endl;
    postorder(root);
    ////////////////////// display preorder traverse
    cout << " pre order traversal of the tree is "<<endl;
    preorder(root);

    ///////////////////////delete node using in order traverse
    cout << " In order traversal of the tree is "<<endl;
    inorder(root);

    cout << "  delete 2 from the tree  "<<endl;
    root = deleteNode(root, 2);
    cout << " the updated tree after deleting 2 is "<<endl;
    inorder(root);
    return 0;
}
