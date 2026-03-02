#include <iostream>
#include <string>
using namespace std;

string separate_words(string s)
{
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z'))
        {
            if (i != 0)
                res += ' ';
            res += tolower(s[i]);
        }
        else
            res += s[i];
    }
    return res;
}

int main()
{

    cout << separate_words("ThisIsAnAutomationEra") << endl;
    return 0;
}