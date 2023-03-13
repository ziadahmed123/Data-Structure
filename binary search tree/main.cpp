#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//////////////////////problem 4

class Node{
    public:
      int data;
      Node* left;
      Node* right;
      Node(int d)
      {
          data=d;
          left=right=NULL;
      }
};

class BinarySearchTree {

    public:
    Node *root;
    BinarySearchTree()
    {
        root = NULL;
    }

    void inordertraverse(Node* node)
    {
        if (node == NULL)
            return;

        inordertraverse(node->left);
        cout << node->data << endl;
        inordertraverse(node->right);
    }
    void inorder()
    {
        inordertraverse(this->root);
    }
    Node* insertnode(Node* root, int data)
    {

        // If the tree is empty, return a new node
        if (root == NULL) {
            root = new Node(data);
            return root;
        }
        if (data < root->data)
            root->left = insertnode(root->left, data);
        else if (data > root->data)
            root->right = insertnode(root->right, data);
        return root;
    }
    void insert(int key)
    {
        root = insertnode(root, key);
    }


    // add value into two vectors
    vector<int> addinorder(Node* node, vector<int>& v)
    {
        if (node == NULL)
            return v;
        addinorder(node->left, v);
        v.push_back(node->data);
        addinorder(node->right, v);
        return v;
    }

//////////////// to find the pair and sum of them
    bool PaiIsFound(Node* node, int sumofpair)
    {
        vector<int> a1;
        vector<int> a2 = addinorder(node, a1);
        int first = 0;
        int last = (int)a2.size() - 1;
        while (first < last) {
            if (a2[first] + a2[last] == sumofpair)
            {
                cout << "Pair are found: " << a2[first] << " and " << a2[last];
                return true;
            }

             if (a2[first] + a2[last]  > sumofpair)
            {
                last--;
            }

            if (a2[first] + a2[last]  < sumofpair)
            {
                first++;
            }
        }
        cout << "No sum of pair founded";
        return false;
    }
};

int main()
{
    BinarySearchTree *tree = new BinarySearchTree();
    tree->insert(15);
    tree->insert(10);
    tree->insert(20);
    tree->insert(8);
    tree->insert(12);
    tree->insert(16);
    tree->insert(25);
    tree->PaiIsFound(tree->root, 28);
}
