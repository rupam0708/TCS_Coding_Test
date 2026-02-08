#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 0};
    int res = v[0], maxProd = v[0], minProd = v[0], curr;

    for (int i = 0; i < v.size(); i++)
    {
        curr = v[i];

        if (curr < 0)
            swap(maxProd, minProd);

        maxProd = max(curr, maxProd * curr);
        minProd = max(curr, minProd * curr);

        res = max(res, maxProd);
    }

    cout << "max product = " << res << endl;

    return 0;
}