#include "BSTOnlineB.cpp"
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
        else if (choice == 'C')
        {
            int n;
            cin >>n;
            queue<int> a;
            for(int i=0;i<n;i++)
            {
                int d;
                cin>>d;
                a.push(d);
            }
            int s=bst.check(a);
            if(s==1)
            {
                cout<<"sublist"<<endl;
            }
            else if(s==2)
            {
                cout<<"subsequence"<<endl;
            }
            else
                cout<<"none"<<endl;
        }
    }
    return 0;
}