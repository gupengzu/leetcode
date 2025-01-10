#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int edit_distance_main(string s1, string s2, vector<vector<int>> &distance_now)
{
    if (s1.empty() && s2.empty())
    {
        return 0;
    }
    else if (s1.empty() && !s2.empty())
    {
        return s2.size();
    }
    else if (!s1.empty() && s2.empty())
    {
        return s1.size();
    }
    else if (distance_now[s1.size()][s2.size()] != INT_MAX)
    {
        return distance_now[s1.size()][s2.size()];
    }
    else
    {
        if (s1[0] == s2[0])
        {
            distance_now[s1.size()][s2.size()] = edit_distance_main(s1.substr(1), s2.substr(1), distance_now);
            return distance_now[s1.size()][s2.size()];
        }
        else
        {
            // add a letter to s1
            int distance_add = edit_distance_main(s1, s2.substr(1), distance_now) + 1;
            // delete a letter fron s1
            int distance_delete = edit_distance_main(s1.substr(1), s2, distance_now) + 1;
            // replace a letter from s1
            int distance_replace = edit_distance_main(s1.substr(1), s2.substr(1), distance_now) + 1;
            distance_now[s1.size()][s2.size()] = min(min(distance_add, distance_delete), distance_replace);
            return distance_now[s1.size()][s2.size()];
        }
    }
}

int edit_distance(string s1, string s2)
{
    vector<vector<int>> distance_now(s1.size() + 1, vector<int>(s2.size() + 1, INT_MAX));
    return edit_distance_main(s1, s2, distance_now);
}

int main()
{
    string s1 = "cat";
    string s2 = "dog";
    int distance = edit_distance(s1, s2);
    cout << distance << endl;
    return 0;
}