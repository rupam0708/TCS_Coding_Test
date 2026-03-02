#include <iostream>
#include <string>
using namespace std;

int reverse(int n)
{
    int rev = 0, ld;
    while (n > 0)
    {
        ld = n % 10;
        rev = rev * 10 + ld;
        n /= 10;
    }
    return rev;
}

int decimal_binary(int n)
{
    int res = 0, ld;

    while (n > 0)
    {
        ld = n % 2;
        res = res * 10 + ld;
        n /= 2;
    }

    return reverse(res);
}

int binary_decimal(string n)
{
    int sum = 0, len = n.length(), bit;
    for (int i = 0; i < len; i++)
    {
        bit = n[len - 1 - i] - '0';

        if (bit == 1)
            sum += pow(2, i);
    }

    return sum;
}

int binary_decimal2(string n)
{
    return stoi(n, 0, 2);
}

int decimal_octal(int n)
{
    int res = 0, ld;

    while (n > 0)
    {
        ld = n % 8;
        res = res * 10 + ld;
        n /= 8;
    }

    return reverse(res);
}

int octal_decimal(string n)
{
    int sum = 0, len = n.length(), bit;
    for (int i = 0; i < len; i++)
    {
        bit = n[len - 1 - i] - '0';

        sum += bit * pow(8, i);
    }

    return sum;
}

string digit_num(string n)
{
    string singledigit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string twodigits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tensmultiple[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (n == "0")
        return singledigit[0];

    string res = "";
    int len = n.length();

    for (int i = 0; i < n.length(); i++)
    {
        int digit = n[i] - '0';

        if (len == 3)
        { // Hundreds place
            if (digit != 0)
            {
                res += singledigit[digit] + " hundred ";
            }
            len--;
        }
        else if (len == 2)
        { // Tens place
            if (digit == 1)
            { // 10-19 case
                res += twodigits[n[i + 1] - '0'];
                return res; // We processed both digits, so we are done
            }
            else if (digit > 1)
            {
                res += tensmultiple[digit] + " ";
            }
            len--;
        }
        else if (len == 1)
        { // Units place
            if (digit != 0)
            {
                res += singledigit[digit];
            }
        }
    }
    return res;
}

int main()
{
    cout << binary_decimal("1011") << endl;
    cout << decimal_binary(11) << endl;

    int dec = binary_decimal("1100110");
    cout << decimal_octal(dec) << endl;

    dec = binary_decimal("11111");
    cout << decimal_octal(dec) << endl;

    cout << octal_decimal("345") << endl;

    dec = octal_decimal("345");
    cout << decimal_binary(dec) << endl;

    cout << digit_num("7824") << endl;

    return 0;
}