#include <iostream>
using namespace std;

bool check_prime2(int n)
{
    if (n <= 1)
        return false;

    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

bool check_prime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> get_all_primes(int start, int end)
{
    vector<int> res;
    for (int i = start; i <= end; i++)
    {
        if (check_prime2(i))
            res.push_back(i);
    }

    return res;
}

bool can_sum_2_primes(int n)
{
    // We only need to go up to n/2 to avoid checking the same pair twice
    for (int i = 2; i <= n / 2; i++)
    {
        if (check_prime2(i) && check_prime2(n - i))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    bool is_prime = check_prime(1);
    cout << "Prime : " << (is_prime ? "Yes" : "No") << endl;

    is_prime = check_prime2(10);
    cout << "Prime : " << (is_prime ? "Yes" : "No") << endl;

    // int start, end;
    // cin >> start >> end;
    // vector<int> res = get_all_primes(start, end);
    // for (int val : res)
    //     cout << val << " ";
    // cout << endl;

    cout << can_sum_2_primes(74) << endl;

    return 0;
}