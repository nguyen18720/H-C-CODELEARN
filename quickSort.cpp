#include <iostream>

using namespace std;

void quickSort(int a[], int l, int r)
{
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j)// dieu kien thuc hien vong lap
    {
        while (a[i] < p)//tim phan tu nho hon hoac bang p
        {
            i++;// tang den khi tim thay
        }
        while (a[j] > p)// tim phan tu lon hhon hoac bang p
        {
            j--;// tang den khi tim duoc
        }
        if ( i <= j)// de hoan doi vi tri 
        {
            int temp = a[i];//hoan doi
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        if (i < r)// thuc hien de quy
        {
            quickSort(a,i,r);
        }
        if (j > l)
        {
            quickSort(a,l,j);
        }
    }

};
void PrintArray(int a[],int n )
{
    for ( int i = 0 ; i < n ; i++)
    {
        cout << a[i] <<" ";
    }
};
int solve(int a[],int n)
{
    quickSort(a,0,n-1);
    if (a[0] > 0) return 0;// neu phan tu dau mang lon hon khong thi phan tu nho nhat thieu la 0
    for (int i = 1 ; i < n ; i++)
    {
        if(a[i] - a[i-1] > 1) 
        {
            return a[i-1] + 1;
        }
    }
    return a[n-1] + 1;
};
int main ()
{
    int n;
    int a[20001];
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
   quickSort(a,0,n-1);
   int counter = 1;
    for (int i = 1 ; i < n ; i++)
    {
        if (a[i] == a[i-1])
        {
            counter ++;
        }
        else
        {
            cout << a[i-1] <<" "<<counter << ";";
            counter =1;
        }
    }
    cout << a[n-1] <<" "<< counter <<";";
}