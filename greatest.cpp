#include <iostream>
using namespace std;

double greatest_of_two(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

double greatest_of_three(double a, double b, double c)
{
    if (a > b)
    {
        if (a > c)
            return a;
        else
            return c;
    }
    else
    {
        if (b > c)
            return b;
        else
            return c;
    }
}

int main()
{

    double a = 1, b = 3, c = 5;
    cout << "Greatest of " << a << " & " << b << " = " << greatest_of_two(a, b) << endl;
    cout << "Greatest of " << a << ", " << b << " & " << c << " = " << greatest_of_three(a, b, c) << endl;

    a = 1.123, b = 1.124, c = 1.125;
    cout << "Greatest of " << a << " & " << b << " = " << greatest_of_two(a, b) << endl;
    cout << "Greatest of " << a << ", " << b << " & " << c << " = " << greatest_of_three(a, b, c) << endl;
    return 0;
}