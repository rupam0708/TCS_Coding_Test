#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bubble(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}

vector<int> selection(vector<int> arr)
{
    int n = arr.size(), minI;
    for (int i = 0; i < n - 1; i++)
    {
        minI = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minI])
                minI = j;
        }

        swap(arr[minI], arr[i]);
    }
    return arr;
}

vector<int> insertion(vector<int> arr)
{
    int n = arr.size(), key, j;
    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
    return arr;
}

int partition_arr(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[++i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition_arr(arr, low, high);
        quick(arr, low, pivot - 1);
        quick(arr, pivot + 1, high);
    }
}



int main()
{
    vector<int> input = {4, 6, 2, 5, 7, 9, 1, 3};
    vector<int> b_s = bubble(input);

    for (int val : b_s)
        cout << val << " ";
    cout << endl;

    vector<int> s_s = selection(input);

    for (int val : s_s)
        cout << val << " ";
    cout << endl;

    vector<int> i_s = insertion(input);

    for (int val : i_s)
        cout << val << " ";
    cout << endl;

    quick(input, 0, input.size() - 1);

    for (int val : input)
        cout << val << " ";
    cout << endl;

    return 0;
}