#include <iostream>

using namespace std;

void insertionSort(int a[], int n)
{
    int index, value;
    for (int i = 1; i < n ; i++)
    {
        index = i;
        value = a[i];
        while (index > 0 && a[index-1] > value)
        {
            a[index] = a[index-1];
            index--;
        }
        a[index] = value;
    }

};
void Print(int a[], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " ";
    }
}
int main ()
{
    int n ;
    int a[200];
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    insertionSort(a,n);
    Print(a, n);
    return 0;

}