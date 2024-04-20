#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* Insert(Node* r, int item) {
        if (r == NULL) {
            Node* newnode = new Node(item);
            r = newnode;
        }
        else if (item < r->data) {
            r->left = Insert(r->left, item);
        }
        else {
            r->right = Insert(r->right, item);
        }
        return r;
    }

    void insert(int item) {
        root = Insert(root, item);
    }

    // PreOrder
    void preOrder(Node *r) { // root left right
        if (r == NULL) {
            return;
        }
        cout << r->data << "\t";
        preOrder(r->left);
        preOrder(r->right);
    }

    // InOrder
    void InOrder(Node* r) {  // left -> root -> right
        if (r == NULL) {
            return;
        }
        InOrder(r->left);
        cout << r->data << "\t";
        InOrder(r->right);
    }

    // PostOrder
    void PostOrder(Node* r) {  // left -> right -> root
        if (r == NULL) {
            return;
        }
        PostOrder(r->left);
        PostOrder(r->right);
        cout << r->data << "\t";   
    }

    // Search
    Node* Search(Node* r, int key) {
        if (r == NULL)
            return NULL;
        else if (r->data == key)
            return r;
        else if (key < r->data)
            return Search(r->left, key);
        else
            return Search(r->right, key);
    }

    // Search
    bool Search(int key) {
        Node* result = Search(root, key);
        if (result == NULL)
            return false;
        else
            return true;
    }

    // Minmum
    Node* Min(Node*r) {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
            return Min(r->left);

    }

    // Maxmum
    Node* Max(Node* r) {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            return Max(r->right);
    }

    // Delete
    Node* Delete(Node* r,int key) {
        if (r == NULL)
            return NULL;
        else if (key < r->data)
            r->left = Delete(r->left,key);
        else if (key > r->data)
            r->right = Delete(r->right, key);
        else {
            // leaf node.
            if (r->left == NULL && r->right == NULL)
                r = NULL;

            // node has one child.
            else if (r->left != NULL && r->right == NULL) { // one child on the left
                r->data = r->left->data;
                delete r->left;
                r->left = NULL;
            }
            else if (r->right != NULL && r->left == NULL) { // one child on the right
                r->data = r->right->data;
                delete r->right;
                r->right = NULL;
            }
            // node has two childs.
            else {
                Node* max = Max(r->left);
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }

        }
        return r;
    }
};


int main()
{
    // 45 15 79 90 10 55 12 20 50
    BST btree;
    btree.insert(45);
    btree.insert(15);
    btree.insert(79);
    btree.insert(90);
    btree.insert(10);
    btree.insert(55);
    btree.insert(12);
    btree.insert(20);
    btree.insert(50);

    cout << "Display the tree content: \n";
    btree.preOrder(btree.root);
    cout << "\n.........................................................\n";
    btree.InOrder(btree.root);
    cout << "\n.........................................................\n";
    btree.PostOrder(btree.root);
    cout << "\n.........................................................\n";
    
    // Search
    /*int key;
    cout << "Enter item to search for:\n";
    cin >> key;
    cout << (btree.Search(key) ? "Founded" : "Not Founded");*/

    // Min & Max
    /*cout << "Find minmum: \n";
    Node* min = btree.Min(btree.root);
    if (min == 0)
        cout << "No items exits\n";
    else
        cout << "Minmum is: " << min->data << endl;

    cout << "Find maxmum: \n";
    Node* max = btree.Max(btree.root);
    if (max == 0)
        cout << "No items exits\n";
    else
        cout << "Maxmum is: " << max->data << endl;*/

    // Delete
    cout << "\nDelete items:\n";
    Node* result = btree.Delete(btree.root,12);
    cout << "preorder After Delete 12\n";
    
    result = btree.Delete(btree.root, 15);
    cout << "preorder After Delete 15\n";
    btree.preOrder(result);
    
    return 0;
}
