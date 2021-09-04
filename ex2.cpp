#include <iostream>

using namespace std;

void quickSort(int a[], int l, int r)
{
    int p = a[(l+r)/2];
    int i, j;
    i = l;
    j = r;
    while ( i < j)
    {
        while ( a[i] < p)// find variable greater or equal than p
        {
            i++;
        }
        while (a[j] > p)// find variable less or equal than p
        {
            j--;
        }
        if( i <= j)// revert 2 variable
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp ;
            i++;
            j--;
        }
    }
    if (i < r)
        {
            quickSort(a, i,r);
        }
        if (j > l)
        {
            quickSort(a,l,j);
        }
};

void PrintArray(int a[], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " ";
    }
};
int main()
{
    int a[2000];
    int b[2000];
    int n;
    int k =0;
    cin >> n;
    for ( int i = 0 ; i < n ; i++)// input array a and creat array b include elements not zero
    {
        cin >> a[i];
        if (a[i] != 0 )
        {
            b[k] = a[i];
            k++;
        }
    }
    quickSort(b,0,k-1);// sort array b raise
    k = 0;
    for ( int i = n-1; i >=0 ; i--)
    {
        if (a[i] < 0)
        {
            a[i] = b[k];
            k++;
        }
    }
    for ( int i = 0 ; i < n ; i++)
    {
        if (a[i] > 0)
        {
            a[i] = b[k];
            k++;
        }
    }
    PrintArray(a,n);
}