#include <iostream>
#include <utility>
#include <string>
using namespace std;

pair<string, string> find_roots_quad(int a, int b, int c)
{
    int d = ((b * b) - 4 * a * c);
    double d_sqrt = sqrt(abs(d));

    if (d > 0)
    {
        double r1 = (-b + d_sqrt) / (2 * a);
        double r2 = (-b - d_sqrt) / (2 * a);

        return make_pair(to_string(r1), to_string(r2));
    }
    else if (d < 0)
    {
        string r = to_string(-(double)b / (2 * a));
        return make_pair(r + " + i " + to_string(d_sqrt), r + " - i " + to_string(d_sqrt));
    }
    else if (d == 0)
    {
        return make_pair(to_string(-b / (2 * a)), "");
    }

    return make_pair("", "");
}

int main()
{
    pair<string, string> roots = find_roots_quad(1, -3, -10);
    cout << "Roots = " << roots.first << " & " << roots.second << endl;

    roots = find_roots_quad(1, 1, 1);
    cout << "Roots = " << roots.first << " & " << roots.second << endl;
    return 0;
}