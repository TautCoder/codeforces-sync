#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        int c1 = 0, c2 = 0, c3 = 0;
        for (char ch : s)
        {
            if (ch == '<')
                c1++;
            else if (ch == '*')
                c2++;
            else
                c3++;
        }

        string dup = string(c1, '<') + string(c2, '*') + string(c3, '>');
        if (c2 > 1 || s != dup)
            cout << -1 << "\n";
        else
            cout << max(c1 + c2, c2 + c3) << "\n";
    }

    return 0;
}
