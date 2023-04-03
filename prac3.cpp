#include <bits/stdc++.h>
using namespace std;
#define size 110000
void print(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void mergearr(vector<int> &arr, int s, int e)
{
    int mid = s + ((e - s) / 2);
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge two sorted array
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void MergeSort(vector<int> &arr, int s, int e)
{
    // solving using recursion
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = s + ((e - s) / 2);
    // left part sort karna hai
    MergeSort(arr, s, mid);
    // right part sort karna hai
    MergeSort(arr, mid + 1, e);

    mergearr(arr, s, e);
}

int partition(vector<int> &arr, int s, int e)
{
    // choosing 1st element as pivot element
    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }

    // the correct place where pivot element should be placed
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    // left and right part sambhal lete hai
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition karhe hai
    int p = partition(arr, s, e);

    // sorting left half
    quickSort(arr, s, p - 1);

    // sorting right half
    quickSort(arr, p + 1, e);
}

// Heap Sort
void heapify(vector<int> &arr, int N, int i)
{
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])

        largest = left;

    if (right < N && arr[right] > arr[largest])

        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void HeapSort(vector<int> &arr, int N)
{
    for (int i = N - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr;
    int k = 10;
    for (int i = 0; i < size; i++)
    {
        int num = rand() % size + 1;
        arr.push_back(num);
    }
    int n = size;

    bool flag = true;

    while (flag)
    {
        cout << endl
             << "1.Merge Sort" << endl;
        cout << "2.Quick Sort" << endl;
        cout << "3.Heap Sort" << endl;
        cout << "4.EXIT" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            clock_t startTime = clock();
            MergeSort(arr, 0, size - 1);
            print(arr, size);
            clock_t endTime = clock();
            cout << fixed;
            cout << setprecision(11);
            cout << endl
                 << "Using Merge Sort function, it took " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        }

        case 2:
        {
            clock_t startTime = clock();
            quickSort(arr, 0, size - 1);
            print(arr, size);
            clock_t endTime = clock();
            cout << fixed;
            cout << setprecision(11);
            cout << endl
                 << "Using Quick Sort function, it took " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        }

        case 3:
        {
            clock_t startTime = clock();
            for (int i = (size / 2) - 1; i >= 0; i--)
            {
                heapify(arr, size, i);
            }
            HeapSort(arr, size);
            print(arr, size);
            clock_t endTime = clock();
            cout << fixed;
            cout << setprecision(11);
            cout << endl
                 << "Using Insertion Sort function, it took " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
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
