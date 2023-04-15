// I intend to live life, not just exist.
// Aeron
#include <bits/stdc++.h>
#define siz 1000000
using namespace std;

int getMax(vector<int> &arr)
{
    int maxi = arr[0];
    for (auto i : arr)
    {
        maxi = max(maxi, i);
    }
    return maxi;
}

// count sort start
void countSort(vector<int> &arr, int n)
{
    int k = getMax(arr);
    cout << k << endl;
    vector<int> count(k + 1, 0);
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= k; i++)
        count[i] = count[i - 1] + count[i];

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // for (int i = 0; i < k + 1; i++)
    // {
    //     cout << output[i] << " ";
    // }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// count sort end

// bucket sort

void bucketSort(vector<int> &arr, int n, int k)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
        max_val = max(max_val, arr[i]);

    max_val++;
    vector<int> b[k];

    for (int i = 0; i < n; i++)
    {
        int bi = (k * arr[i]) / max_val;
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < k; i++)
        sort(b[i].begin(), b[i].end());

    int in = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[in++] = b[i][j];
}
// bucket sort end

// radix sort start
void countingSort(vector<int> &arr, int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(vector<int> &arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// radix sort end

int main()
{
    vector<int> arr;
    for (int i = 0; i < siz; i++)
    {
        int num = rand() % siz + 1;
        arr.push_back(num);
    }
    int n = siz;

    bool flag = true;

    while (flag)
    {
        cout << endl
             << "1.Count Sort" << endl;
        cout << "2.Bucket Sort" << endl;
        cout << "3.Radix Sort" << endl;
        cout << "4.EXIT" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            clock_t startTime = clock();
            countSort(arr, n);
            clock_t endTime = clock();
            cout << fixed;
            cout << setprecision(11);
            cout << endl
                 << "Using Count Sort function, it took " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        }
        case 2:
        {
            clock_t startTime = clock();
            bucketSort(arr, n,100);
            clock_t endTime = clock();
            cout << fixed;
            cout << setprecision(11);
            cout << endl
                 << "Using Bucket Sort function, it took " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        }
        case 3:
        {
            clock_t startTime = clock();
            radixsort(arr, n);
            clock_t endTime = clock();
            cout << fixed;
            cout << setprecision(11);
            cout << endl
                 << "Using Radix Sort function, it took " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
            break;
        }
        case 4:
            flag = false;
            break;

        default:
            cout << "INVALID INPUT" << endl;
            break;
        }
    }

    return 0;
}