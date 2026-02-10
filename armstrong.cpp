#include <iostream>
using namespace std;

bool check_armstrong(int n)
{
    if (n < 0)
        return false;

    if (n == 0)
        return true;

    int power = 0, i = n, ld, sum = 0;
    while (i > 0)
    {
        ld = n % 10;
        power++;
        i /= 10;
    }

    i = n;

    while (i > 0)
    {
        ld = i % 10;
        sum += pow(ld, power);
        i /= 10;
    }

    return sum == n;
}

int main()
{
    bool is_arm = check_armstrong(153);
    cout << "Armstrong : " << (is_arm ? "Yes" : "No") << endl;
    return 0;
}