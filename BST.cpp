#include <iostream>
using namespace std;
struct BSTNode
{
    int value;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int v)
    {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};
class BST
{
    BSTNode *head = nullptr;
    BSTNode *deletehelper(BSTNode *h, int x)
    {
        if (h == nullptr)
            return nullptr;

        if (x < h->value)
        {
            h->left = deletehelper(h->left, x);
        }
        else if (x > h->value)
        {
            h->right = deletehelper(h->right, x);
        }
        else
        {
            if (h->left == nullptr)
            {
                BSTNode *temp = h->right;
                delete h;
                return temp;
            }
            else if (h->right == nullptr)
            {
                BSTNode *temp = h->left;
                delete h;
                return temp;
            }

            h->value = findsuccessor(h->right);
            h->right = deletehelper(h->right, h->value);
        }
        return h;
    }
    int findsuccessor(BSTNode *h)
    {
        while (h->left != nullptr)
        {
            h = h->left;
        }
        return h->value;
    }
    void Inorderhelper(BSTNode *h)
    {
        if (h == nullptr)
            return;
        Inorderhelper(h->left);
        cout << h->value << " ";
        Inorderhelper(h->right);
    }
    void Preorderhelper(BSTNode *h)
    {
        if (h == nullptr)
            return;
        cout << h->value << " ";
        Preorderhelper(h->left);
        Preorderhelper(h->right);
    }
    void Postorderhelper(BSTNode *h)
    {
        if (h == nullptr)
            return;
        Postorderhelper(h->left);
        Postorderhelper(h->right);
        cout << h->value << " ";
    }
    void printhelper(BSTNode *h)
    {
        if (h == nullptr)
        {
            return;
        }
        cout << h->value;
        if (h->left != nullptr || h->right != nullptr)
        {
            cout << "(";
            printhelper(h->left);
            cout << ",";
            printhelper(h->right);
            cout << ")";
        }
    }

public:
    void Insert(int x)
    {
        if (head == nullptr)
        {
            head = new BSTNode(x);
            return;
        }

        BSTNode *tem = head;
        BSTNode *prev = head;
        while (tem != nullptr)
        {
            if (tem->value > x)
            {
                prev = tem;
                tem = tem->left;
            }
            else if (tem->value < x)
            {
                prev = tem;
                tem = tem->right;
            }
        }
        if (prev->value > x)
        {
            prev->left = new BSTNode(x);
        }
        else
        {
            prev->right = new BSTNode(x);
        }
    }
    void Delete(int x)
    {
        if (head == nullptr)
            return;
        head = deletehelper(head, x);
    }
    bool Find(int x)
    {
        BSTNode *tem = head;
        while (tem != nullptr)
        {
            if (tem->value == x)
                return true;
            else if (tem->value > x)
            {
                tem = tem->left;
            }
            else if (tem->value < x)
            {
                tem = tem->right;
            }
        }
        return false;
    }
    void Inorder()
    {
        Inorderhelper(head);
        cout << endl;
    }
    void Preorder()
    {
        Preorderhelper(head);
        cout << endl;
    }
    void Postorder()
    {
        Postorderhelper(head);
        cout << endl;
    }
    void print()
    {
        cout<<"(";
        printhelper(head);
        cout<<")";
        cout << endl;
    }
    
};