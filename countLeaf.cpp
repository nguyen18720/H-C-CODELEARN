#include <iostream>

using namespace std;

struct node 
{
    int data;
    node* left;
    node* right;
};
bool isLeaf(node* p)
{
    return (p->left == NULL && p->right == NULL);
};
int countLeaf(node* t)
{
    if (t == NULL) return 0;
    if (isLeaf(t)) return 1;
   return countLeaf(t->left)+ countLeaf(t->right);
};
node* insert(node* t,int x)
{
    if ( t == NULL)
    {
        node* temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    {
        if ( x < t->data)
        {
            t->left = insert(t->left,x);
        }
        else
        {
            t->right = insert(t->right,x); 
        }
        return t;
    }
};
void printTree(node* t )
{
    if ( t != NULL)
    {
        printTree(t->left);
        cout << t->data <<" ";
        printTree(t->right);
    }
};

int main ()
{
    int n,x;
    node* t = NULL;
    cin >> n;
    for ( int i = 0 ; i < n ; i++)
    {
        cin >> x;
        t = insert(t, x);
    }
    cout << countLeaf(t);
    printTree(t);
}

