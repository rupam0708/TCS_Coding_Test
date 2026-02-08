#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double sumOfEle(vector<int> v)
{
    double sum = 0;
    for (int val : v)
        sum += (double)val;

    return sum;
}

double getMedian(vector<int> v, int n)
{
    sort(v.begin(), v.end());
    if (n % 2 != 0)
    {
        return (double)v[n / 2];
    }
    else
    {
        int mid = n / 2;
        return (double)(((double)v[mid - 1] + (double)v[mid]) / 2);
    }
}

int main()
{
    vector<int> v = {1, 2, 1, 1, 5, 1};
    double sum = sumOfEle(v);

    double avg = sum / v.size();

    cout << "Avg = " << avg << endl;

    v = {2, 5, 1, 7};

    double median = getMedian(v, v.size());

    cout << "Median = " << median << endl;

    return 0;
}