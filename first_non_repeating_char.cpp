#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> get_freq_chars(string s)
{
    unordered_map<char, int> mp;

    for (char ch : s)
        if (isalpha(ch))
            mp[ch]++;

    return mp;
}

char first_non_repeating_char(string s)
{
    unordered_map<char, int> mp = get_freq_chars(s);
    for (char ch : s)
    {
        // Check if this character was non-repeating
        if (isalpha(ch) && mp[ch] == 1)
        {
            return ch; // Returns 'a' for "abcd"
        }
    }

    return '/';
}

int main()
{
    cout << first_non_repeating_char("abcd") << endl;
    cout << first_non_repeating_char("abcda") << endl;

    return 0;
}