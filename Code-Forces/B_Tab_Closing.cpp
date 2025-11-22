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
        long long a, b, n;
        cin >> a >> b >> n;

                // if (b * n <= a)
        // {
        //     cout << 1 << "\n";
        //     continue;
        // }
        if (a > b)
        {
            cout << 2 << "\n";
            continue;
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}
