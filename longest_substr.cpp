#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longest_substr_len(string s)
{
    int n = s.size();
    int res = 0;
    vector<char> last_i(26, -1);
    int start = 0;

    for (int end = 0; end < n; end++)
    {
        start = max(start, last_i[s[end] - 'a'] + 1);

        res = max(res, end - start + 1);

        last_i[s[end] - 'a'] = end;
    }

    return res;
}

int main()
{
    cout << longest_substr_len("abcabcbb") << endl;
    return 0;
}