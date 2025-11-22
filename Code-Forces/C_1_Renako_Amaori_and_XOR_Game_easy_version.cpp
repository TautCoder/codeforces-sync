#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int xorA = 0, xorB = 0;
    int odd_diff = 0, even_diff = 0;

    for (int i = 0; i < n; i++)
    {
        xorA ^= a[i];
        xorB ^= b[i];
        if (a[i] != b[i])
        {
            int idx = i + 1;
            if (idx & 1)
                odd_diff++;
            else
                even_diff++;
        }
    }

    string ans;

    // Case 1: XOR tie already
    if (xorA == xorB)
    {
        ans = "Tie";
    }
    // Case 2: Ajisai initially winning (xorA = 1)
    else if (xorA == 1)
    {
        if (odd_diff > even_diff)
            ans = "Ajisai";
        else if (even_diff > odd_diff)
            ans = "Mai";
        else
            ans = "Tie";
    }
    // Case 3: Mai initially winning (xorB = 1)
    else
    { // xorB == 1
        if (even_diff > odd_diff)
            ans = "Mai";
        else if (odd_diff > even_diff)
            ans = "Ajisai";
        else
            ans = "Tie";
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
