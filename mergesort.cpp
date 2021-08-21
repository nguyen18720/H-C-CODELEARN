#include <iostream>

using namespace std;

void merge(int a[],int l, int r, int m)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int r1[n1],r2[n2];
    for (int i = 0 ; i < n1; i++)
    {
        r1[i] = a[l+i];
    }
    for (int i = 0 ; i < n2; i++)
    {
        r2[i] = a[m+i+1];
    }
    i = 0;
    j = 0;
    k = 0;
    while ( i < n1 && j < n2)
    {
        if (r1[i] < r2[j])
        {
            a[k] = r1[i];
            i++;
            k++;
        }
        else
        {
            a[k] = r2[j];
            j++;
            k++;
        }
    }
    while ( i < n1)
    {
        a[k] = r1[i];
        i++;
        k++;
    }
    while ( j < n2)
    {
        a[k] = r2[j];
        j++;
        k++;
    }
};
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,r,m);
    }
};
void Print(int a[],int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n,l,r;
    cin >> n;
    int a[200];
    for (int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }
    l = 0;
    r = n-1;
    mergeSort(a,l,r);
    Print(a,n);
}