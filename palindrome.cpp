#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rev_num(int n)
{
    int rev = 0, ld;

    while (n > 0)
    {
        ld = n % 10;
        rev = (rev * 10) + ld;
        n /= 10;
    }

    return rev;
}

bool isPalindrome(int number)
{
    int dup = number, ld;

    // while (number > 0)
    // {
    //     ld = number % 10;
    //     rev = (rev * 10) + ld;
    //     number = number / 10;
    // }

    int rev = rev_num(number);

    return rev == dup;
}

vector<int> findAllPals(int start, int end)
{
    bool isPal = false;
    vector<int> res;
    for (int i = start; i <= end; i++)
    {
        isPal = isPalindrome(i);
        if (isPal)
        {
            res.push_back(i);
        }
    }

    return res;
}

pair<int, int> get_max_min_digit(int n)
{
    int maxd = INT_MIN, mind = INT_MAX, ld;
    while (n > 0)
    {
        ld = n % 10;
        maxd = max(maxd, ld);
        mind = min(mind, ld);
        n /= 10;
    }
    return {maxd, mind};
}

int main()
{
    // int number;
    // cin >> number;
    // bool isPal = isPalindrome(number);
    // cout << (isPal ? "Palindrome" : "Not Palindrome") << endl;

    // int start, end;
    // cin >> start >> end;
    // vector<int> res = findAllPals(start, end);
    // for (int val : res)
    //     cout << val << " ";
    // cout << endl;

    int n;
    cin >> n;
    auto info = get_max_min_digit(n);

    cout << "Max digit = " << info.first << " Min digit = " << info.second << endl;

    return 0;
}