// I intend to live life, not just exist.
// Aeron
#include <bits/stdc++.h>
#define size 6
using namespace std;

void heapify(int arr[], int n, int i)
{

    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[large])
    {
        large = left;
    }

    if (right < n && arr[right] < arr[large])
    {
        large = right;
    }

    if (large != i)
    {
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{

    int arr[size];
    cout << "enter keys" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);
    for (int j = n - 1; j >= 0; j--)
    {
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}