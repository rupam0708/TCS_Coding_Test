#include <iostream>
using namespace std;

bool is_harshad(int n)
{
    int sum = 0, ld, temp = n;

    while (n > 0)
    {
        ld = n % 10;
        sum += ld;
        n /= 10;
    }

    return temp % sum == 0;
}

int main()
{

    cout << is_harshad(378) << endl;
    cout << is_harshad(379) << endl;
    return 0;
}