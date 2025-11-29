#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        unordered_map<int, int> freq;
        for (int i = 0; i < 2 * n; ++i)
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        int odd_count = 0, distinct = freq.size();
        for (auto &[val, count] : freq)
        {
            if (count % 2 == 1)
                odd_count++;
        }

        int ans;
        if (odd_count <= n)
        {
            ans = odd_count + min(n, distinct);
        }
        else
        {
            ans = 2 * n;
        }

        cout << ans << "\n";
    }
}
