#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool is_palindrome(int num)
{
    int temp = num, ld, rev;
    while (num > 0)
    {
        ld = num % 10;
        rev = rev * 10 + ld;
        num /= 10;
    }

    return rev == num;
}

bool is_div_7(int num)
{
    return ((num % 7 == 0) && (num % 5 != 0));
}

bool has_repeat_digits(int num)
{
    unordered_map<int, int> mp;
    int ld;
    while (num > 0)
    {
        ld = num % 10;
        if (mp.find(ld) != mp.end())
            return true;
        else
            mp[ld]++;

        num /= 10;
    }
    return false;
}

bool has_repeat_digits2(int num)
{
    bool seen[10] = {false};
    int ld;
    while (num > 0)
    {
        ld = num % 10;
        if (seen[ld])
            return true;
        else
            seen[ld] = true;

        num /= 10;
    }
    return false;
}

bool is_criptic(int num)
{
    return !is_palindrome(num) && is_div_7(num) && !has_repeat_digits(num);
}

vector<int> all_criptic_nums(int start, int end)
{
    vector<int> res;
    for (int i = start; i <= end; i++)
    {
        if (is_criptic(i))
            res.push_back(i);
    }

    return res;
}

int main()
{
    int start, end;
    cin >> start >> end;

    // if ((start >= 0 && start <= 9) || (end >= 0 && end <= 9))
    if (start < 10 || end < 10 || start > end)
    {
        cout << "Invalid Input" << endl;
        return -1;
    }
    else
    {
        vector<int> res = all_criptic_nums(start, end);
        if (res.size() == 0)
        {
            cout << "No cryptic numbers found" << endl;
            return -1;
        }

        for (int i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}