#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> get_2_ele(vector<int> v, int target)
{
    int n = v.size();
    int i = 0, j = n - 1;
    int sum;

    while (i < j)
    {
        sum = (v[i] + v[j]);
        if (sum == target)
            return make_pair(v[i], v[j]);
        else if (sum > target)
            j--;
        else if (sum < target)
            i++;
    }

    return make_pair(-1, -1);
}

int main()
{
    auto it = get_2_ele({1, 4, 5, 7, 9}, 20);
    cout << "First = " << it.first << endl;
    cout << "Second =  " << it.second << endl;
    return 0;
}