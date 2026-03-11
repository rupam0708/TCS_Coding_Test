#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sub_sum(vector<int> sub_marks, int n)
{
    int sum = 0;
    for (int i : sub_marks)
    {
        sum += i;
    }
    return sum;
}

double sub_avg(vector<int> sub_marks, int n)
{
    return (double)sub_sum(sub_marks, n) / (double)n;
}

int count_selected_stds(vector<vector<int>> marks, int s, int n)
{
    int count = 0;
    double avg = 0.0;
    unordered_map<int, int> mp;

    for (int i = 0; i < s; i++)
    {
        avg = sub_avg(marks[i], n);
        for (int j = 0; j < n; j++)
        {
            if ((double)marks[i][j] >= avg)
                mp[j]++;
        }
    }

    return mp.size();
}

int main()
{
    int s; // number of total subjects
    int n; // number of total students

    cout << "Enter the total number of subjects and students" << endl;
    cin >> s >> n;

    vector<vector<int>> marks(s, vector<int>(n));

    cout << "Enter marks obtained" << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> marks[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Total selected students = " << count_selected_stds(marks, s, n) << endl;

    return 0;
}