#include <iostream>
using namespace std;

bool is_leap_year(int year)
{
    if (year % 100 == 0)
    {
        if (year % 4 == 0)
            return true;
        else
            return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }

    return false;
}

int main()
{
    int year = 1995;
    cout << year << " is " << (is_leap_year(year) ? "" : "not ") << "leap year" << endl;
    return 0;
}