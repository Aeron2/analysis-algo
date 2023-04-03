// I intend to live life, not just exist.
// Aeron
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
const int mod = 1'000'000'007;

int linearSearch(int arr[], int n, int key)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


int main()
{
    int n = 10;
    int arr[n];
    // Random number insertion

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }

    cout << "Enter the key to be found" << endl;
    int key;
    cin >> key;

    int choose;
    cout << "Choose which search to be performed\n1. Linear Search\n2. Binary Search\n3. Direct Search" << endl;
    cin >> choose;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    auto begin = std::chrono::high_resolution_clock::now();

    switch (choose)
    {
    case 1:
        cout << linearSearch(arr, n, key) << endl;
       
        break;
    case 2:
        sort(arr, arr + n);
       cout<< binarySearch(arr, n, key)<<endl;
        break;

    default:
        cout << "Invalid input" << endl;
        break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.30f seconds.\n", elapsed.count() * 1e-9);
    return 0;
}