#include "BSTOnlineC.cpp"
#include<queue>
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    BST bst;
    char choice;
    while (cin >> choice)
    {
        if (choice == 'I')
        {
            int n;
            cin >> n;
            bst.Insert(n);
            bst.print();
        }
        else if (choice == 'T')
        {
            string c;
            cin>>c;
            if (c.compare("Pre")==0)
            {
                bst.Preorder();
            }
            else if (c.compare("Post")==0)
            {
                bst.Postorder();
            }
            else if (c.compare("In")==0)
            {
                bst.Inorder();
            }
        }
        else if (choice == 'D')
        {
            int n;
            cin >> n;
            bst.Delete(n);
            bst.print();
        }
        else if (choice == 'F')
        {
            int n;
            cin >> n;
            if (bst.Find(n))
                cout << "found" << endl;
            else
                cout << "not found" << endl;
        }
        else if (choice == 'P')
        {
            int n;
            cin>>n;
            cout<<bst.depth(n)<<endl;
        }
        else if (choice == 'H')
        {
            cout<<bst.height()<<endl;
        }
    }
    return 0;
}