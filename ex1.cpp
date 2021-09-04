#include<iostream>
#include <math.h>

using namespace std;

void quicklySort(int a[], int l, int r)
{
    int p = a[(l+r)/2];
    int i , j;
    i = l;
    j = r;
    while ( i < j )
    {
        while (a[i] < p)// tim phan tu lon hon p
        {
            i++;
        }
        while (a[j] > p)// duyet den khi tim duoc phan tu nho hon p
        {
            j--;
        }
        if ( i <= j)// hoan doi a[i], a[j]
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if ( i < r)
    {
        quicklySort(a,i,r);
    }
    if (j > l)
    {
        quicklySort(a,l,j);
    }
};
void PrintArray(int a[],int n)
{
    if ( n == 0 ) cout << "NULL";
    else
    {
        cout << a[0] << " ";
        for (int i = 1 ; i < n ; i++)
        {
            if (a[i] != a[i-1])
                cout <<a[i]<<" ";
        }
    }
};
bool check(int a)
{
    int k = (int) sqrt(a);
    return k*k == a;
};
int main ()
{
    int n, count, k;
    int a[100001];
    int b[100001];
    cin >> n;
    k = 0;
    for (int i = 0 ; i < n; i++)
    {
        cin >> a[i];
        if (check(a[i]))
        {
            b[k] = a[i];
            k++;
        }
    }
    quicklySort(b,0,k-1);
    PrintArray(b,k);
    
}