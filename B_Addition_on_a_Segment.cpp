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
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(b.begin(), b.end());

        // Case: all elements equal
        if (b[0] == b[n - 1])
        {
            cout << 1 << "\n";
            continue;
        }

        // find first non-zero
        int l = -1;
        for (int i = 0; i < n; i++)
        {
            if (b[i] != 0)
            {
                l = i;
                break;
            }
        }

        // if array was all zeros
        if (l == -1)
        {
            cout << 1 << "\n";
            continue;
        }

        int r = n - 1;
        int ans = (l == r ? 1 : r - l + 1);

        cout << ans << "\n";
    }

    return 0;
}
