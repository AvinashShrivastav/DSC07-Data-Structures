#include <iostream>
using namespace std;

class Node
{
private:
    int val;
    Node *left;
    Node *right;

public:
    Node(int num)
    {
        val = num;
        left = NULL;
        right = NULL;
    }
    friend class BinTree;
};

class BinTree
{
private:
    Node *root;

public:
    BinTree() { root = NULL; }
    BinTree(int num)
    {
        root = new Node(num);
    }

    void insert(int num)
    {
        root = insertRecursive(root, num);
    }

    void remove(int num)
    {
        root = deleteNode(root, num);
    }

    bool search(int num)
    {
        return searchRecursive(root, num);
    }

    void displayPreorder()
    {
        cout << "Preorder: ";
        displayPreorderRecursive(root);
        cout << endl;
    }

    void displayInorder()
    {
        cout << "Inorder: ";
        displayInorderRecursive(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "Postorder: ";
        displayPostorderRecursive(root);
        cout << endl;
    }

private:
    Node *insertRecursive(Node *current, int num)
    {
        if (current == NULL)
        {
            return new Node(num);
        }

        if (num < current->val)
        {
            current->left = insertRecursive(current->left, num);
        }
        else if (num > current->val)
        {
            current->right = insertRecursive(current->right, num);
        }

        return current;
    }

    Node *deleteNode(Node *current, int num)
    {
        if (current == NULL)
        {
            return current;
        }

        if (num < current->val)
        {
            current->left = deleteNode(current->left, num);
        }
        else if (num > current->val)
        {
            current->right = deleteNode(current->right, num);
        }
        else
        {
            if (current->left == NULL)
            {
                Node *temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == NULL)
            {
                Node *temp = current->left;
                delete current;
                return temp;
            }

            Node *temp = findMin(current->right);
            current->val = temp->val;
            current->right = deleteNode(current->right, temp->val);
        }

        return current;
    }

    bool searchRecursive(Node *current, int num)
    {
        if (current == NULL)
        {
            return false;
        }

        if (num == current->val)
        {
            return true;
        }
        else if (num < current->val)
        {
            return searchRecursive(current->left, num);
        }
        else
        {
            return searchRecursive(current->right, num);
        }
    }

    void displayPreorderRecursive(Node *current)
    {
        if (current != NULL)
        {
            cout << current->val << " ";
            displayPreorderRecursive(current->left);
            displayPreorderRecursive(current->right);
        }
    }

    void displayInorderRecursive(Node *current)
    {
        if (current != NULL)
        {
            displayInorderRecursive(current->left);
            cout << current->val << " ";
            displayInorderRecursive(current->right);
        }
    }

    void displayPostorderRecursive(Node *current)
    {
        if (current != NULL)
        {
            displayPostorderRecursive(current->left);
            displayPostorderRecursive(current->right);
            cout << current->val << " ";
        }
    }

    Node *findMin(Node *current)
    {
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
};


int main()
{
    BinTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);

    cout << "Search for 5: " << (tree.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search for 8: " << (tree.search(8) ? "Found" : "Not Found") << endl;

    tree.displayPreorder();
    tree.displayInorder();
    tree.displayPostorder();

    return 0;
}
