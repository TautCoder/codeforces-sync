#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int T, n, k, x;
    cin >> T;
    while (T--)
    {
        map<int, int> mp;
        map<int, int> cnt;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            mp[x]++;
        }
        for (int i = 1; i <= n * 4; i++)
            cnt[i] = cnt[i - 1] + mp[i];
        for (int i = n; i >= 1; i--)
        {
            if (cnt[i * 4 - 1] - mp[i] - mp[i * 2] - mp[i * 3] <= k)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}