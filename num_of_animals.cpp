#include <iostream>
using namespace std;

int main()
{
    int l, n, a1, a2;
    cout << "L = ";
    cin >> l;

    cout << "N = ";
    cin >> n;

    a2 = (l / 2) - n;
    a1 = n - a2;

    cout << "A1 = " << a1 << endl;
    cout << "A2 = " << a2 << endl;
    return 0;
}