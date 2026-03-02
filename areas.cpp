#include <iostream>
using namespace std;

double circle(int r)
{
    return (22.0 / 7.0) * (double)(r * r);
}

double rectangle(int l, int b)
{
    return l * b;
}

int main()
{
    cout << "Area of circle = " << circle(5) << endl;
    cout << "Area of rectangle = " << rectangle(5, 10) << endl;
    return 0;
}