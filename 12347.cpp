#include<iostream>
using namespace std;
struct node
{
 int index;
 node* left;
 node* right;
};
class Tree
{
    public:
    Tree();
    ~Tree();
    void add(int n);
    node* root;
};
Tree::Tree()
   {
       root=NULL;
   }
Tree::~Tree()
   {
       delete root;
   }
    void Tree::add(int n)
    {
        node* store=root;
        if(root==NULL)
        {
            root=new node;
         root->index=n;
          root->left=NULL;
           root->right=NULL;
            return;
        }
        else
        {
            while(1)
            {
                if(store->index>n)
                {
                    if(store->left==NULL)
                    {
                        store->left=new node;
                        store=store->left;
                        store->index=n;
                        store->left=NULL;
                        store->right=NULL;
                        return;
                    }
                    else
                    store=store->left;
                }
                else if(store->index<n)
                {
                    if(store->right==NULL)
                    {
                        store->right=new node;
                        store=store->right;
                        store->index=n;
                        store->left=NULL;
                        store->right=NULL;
                        return;
                    }
                    else
                   store=store->right;
                }
            }
        }
    }
void ans(node* aa)
{
    if(aa->left!=NULL)
        ans(aa->left);
    if(aa->right!=NULL)
        ans(aa->right);
    cout<<aa->index<<endl;
}
int main()
{
    int n,count=0;
    Tree T;
    while(cin>>n)
        T.add(n);
    ans(T.root);

    return 0;
}
