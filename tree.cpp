#include <iostream>

using namespace std;

struct node 
{
    int data;
    node* left;
    node* right;
};
node* Create_node(int x)
{
    node* p = new node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
};
node* insert(node* t, int x)
{
    if ( t == NULL)
    {
        node* p = new node;
        p ->data = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    else
    {
        if ( x < t->data)
        {
            t ->left = insert(t->left,x);
        }
        else
        {
            t->right = insert(t->right,x);
        }
        return t;
    }
};
void printTree(node* t)
{
    if ( t != NULL)
    {
        printTree(t->left);
        cout << t->data << " ";
        printTree(t->right);
    }
};
int main ()
{
    int n,x;
    node* t = NULL;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> x;
       t = insert(t,x);
    }
    printTree(t);
    return 0;
}