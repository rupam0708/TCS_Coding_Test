#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <unordered_map>
using namespace std;

bool is_vowel(char ch)
{
    char val = tolower(ch);
    return (val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u');
}

int count_vowel(string s)
{
    int count = 0;

    for (char val : s)
    {
        if (is_vowel(val))
            count++;
    }

    return count;
}

int count_consonant(string s)
{
    int count = 0;

    for (int val : s)
    {
        if (isalpha(val) && !is_vowel(val))
            count++;
    }

    return count;
}

int count_spaces(string s)
{
    int count = 0;

    for (int val : s)
    {
        if (val == ' ')
            count++;
    }

    return count;
}

int ascii_val(char ch) { return int(ch); }

string remove_vowel(string s)
{
    string res;
    for (char ch : s)
    {
        if (!is_vowel(ch))
            res += ch;
    }

    return res;
}

string remove_spaces(string s)
{
    string res;
    for (char ch : s)
    {
        if (ch != ' ')
            res += ch;
    }

    return res;
}

string remove_chars(string s)
{
    string res;
    for (char ch : s)
    {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            res += ch;
    }
    return res;
}

string reverse_str(string s)
{
    string res;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        res += s[i];
    }
    return res;
}

string remove_brackets(string s)
{
    string res;
    for (char ch : s)
    {
        if (ch != '(' && ch != ')' && ch != '{' && ch != '}' && ch != '[' && ch != ']')
            res += ch;
    }

    return res;
}

int sum_nums_1(string s)
{
    int sum = 0;
    for (char ch : s)
    {
        if (isdigit(ch))
            sum += (ch - '0');
    }
    return sum;
}

int sum_nums_2(string s)
{
    int sum = 0;
    string temp;
    for (char ch : s)
    {
        if (isdigit(ch))
            temp += ch;
        else
        {
            if (!temp.empty())
            {
                sum += stoi(temp);
                temp = "";
            }
        }
    }

    if (!temp.empty())
        sum += stoi(temp);

    return sum;
}

void word_first_last_caps(string &s)
{
    int n = s.size();

    s[0] = toupper(s[0]);
    s[n - 1] = toupper(s[n - 1]);

    for (int i = 1; i < n - 2; i++)
    {
        if (s[i - 1] == ' ' || s[i + 1] == ' ')
            s[i] = toupper(s[i]);
    }
}

map<char, int> freq_chars(string s)
{
    map<char, int> mp;
    for (char ch : s)
    {
        if (isalpha(ch))
            mp[ch]++;
    }

    return mp;
}

vector<char> non_repeating_chars(string s)
{
    map<char, int> mp = freq_chars(s);
    vector<char> v;

    for (auto val : mp)
        if (val.second == 1)
            v.push_back(val.first);

    return v;
}

vector<char> repeating_chars(string s)
{
    map<char, int> mp = freq_chars(s);
    vector<char> v;

    for (auto val : mp)
        if (val.second > 1)
            v.push_back(val.first);

    return v;
}

vector<char> max_occur_chars(string s)
{
    map<char, int> mp = freq_chars(s);
    vector<char> v;

    int max_occur = 0;
    for (auto val : mp)
        max_occur = max(max_occur, val.second);

    for (auto val : mp)
        if (val.second == max_occur)
            v.push_back(val.first);

    return v;
}

string remove_dups_chars(string s)
{
    bool seen[26] = {false};
    string res = "";

    for (char ch : s)
    {
        if (!seen[ch - 'a'])
        {
            seen[ch - 'a'] = true;
            res += ch;
        }
    }

    return res;
}

string remove_from_1(string s1, string s2)
{
    string res;

    unordered_map<char, bool> mp;

    for (char ch : s2)
        mp[ch] = true;

    for (char ch : s1)
        if (!mp[ch])
            res += ch;

    return res;
}

string next_char(string s)
{
    int ascii;
    string res = "";
    for (char ch : s)
    {
        ascii = int(ch);

        // 'z' = 122
        // 'a' = 97
        // 'Z' = 90
        // 'A' = 65

        if (ascii == 122)
            res += char(97);
        else if (ascii == 90)
            res += char(65);
        else
            res += char(ascii + 1);
    }
    return res;
}

string longest_word(string s)
{
    string temp = "", longest = "";
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i]; // Build the current word
        }

        // If we hit a space OR the end of the string
        if (s[i] == ' ' || i == n - 1)
        {
            if (temp.length() > longest.length())
            {
                longest = temp;
            }
            temp = ""; // Reset for next word
        }
    }
    return longest;
}

int number_of_word(string s)
{
    string temp = "";
    int n = s.length(), count = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i]; // Build the current word
        }

        // If we hit a space OR the end of the string
        if (s[i] == ' ' || i == n - 1)
        {
            count++;
            temp = ""; // Reset for next word
        }
    }
    return count;
}

int num_of_dups_chars(string w)
{
    map<char, int> mp = freq_chars(w);
    int count = 0;

    for (auto val : mp)
    {
        if (val.second > 1)
            count++;
    }

    return count;
}

string max_repeated_chars_word(string s)
{
    vector<string> words;
    string temp;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
            temp += s[i];

        if (s[i] == ' ' || i == n - 1)
        {
            words.push_back(temp);
            temp = "";
        }
    }

    int max_chars_repeated = 0, index = -1, temp_r;

    for (int i = 0; i < words.size(); i++)
    {
        temp_r = num_of_dups_chars(words[i]);
        if (temp_r > max_chars_repeated)
        {
            max_chars_repeated = temp_r;
            index = i;
        }
    }

    if (index == -1)
        return "-1";

    return words[index];
}

int find_substring(string s1, string s2)
{
    return s1.find(s2);
}

string reverse_words(string s)
{
    vector<string> words;
    string temp;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
            temp += s[i];

        if ((s[i] == ' ' || i == n - 1) && !temp.empty())
        {
            words.push_back(temp);
            temp = "";
        }
    }

    string res;

    for (int i = words.size() - 1; i >= 0; i--)
    {
        res += words[i];
        if (i != 0)
            res += ' ';
    }

    return res;
}

int main()
{

    string s = "Take u forward is Awesome";
    cout << count_vowel(s) << ", " << count_consonant(s) << ", " << count_spaces(s) << endl;

    s = "India won the cricket match";
    cout << count_vowel(s) << ", " << count_consonant(s) << ", " << count_spaces(s) << endl;

    cout << ascii_val('1') << endl;

    cout << remove_vowel("take u forward") << endl;

    cout << remove_spaces("take u forward") << endl;

    cout << remove_chars("take12% *&u ^$#forward") << endl;

    cout << reverse_str("Rupam") << endl;

    cout << remove_brackets("a+((b-c)+d)") << endl;

    cout << sum_nums_1("123xyz") << endl;

    cout << sum_nums_2("1xyz23") << endl;

    string s_2 = "take u forward is awesome";
    word_first_last_caps(s_2);
    cout << s_2 << endl;

    map<char, int> mp = freq_chars("take u forward");
    for (auto val : mp)
        cout << val.first << " -> " << val.second << endl;

    vector<char> v = non_repeating_chars("I am google");
    for (char ch : v)
        cout << ch << " ";
    cout << endl;

    v = max_occur_chars("I am google");
    for (char ch : v)
        cout << ch << " ";
    cout << endl;

    cout << remove_dups_chars("cbacdcbc") << endl;

    v = repeating_chars("I am google");
    for (char ch : v)
        cout << ch << " ";
    cout << endl;

    cout << remove_from_1("abcdef", "cefz") << endl;

    cout << next_char("abcdxyz") << endl;

    cout << longest_word("Microsoft Teams") << endl;

    cout << number_of_word("Microsoft Teams") << endl;

    cout << max_repeated_chars_word("abcdefghij google microsoft") << endl;

    cout << find_substring("takeuforward", "frward") << endl;

    cout << reverse_words("welcome to the jungle") << endl;

    return 0;
}