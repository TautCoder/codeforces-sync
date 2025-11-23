#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500000;

int i, j, k, n, m, t, a[N + 50], f[N + 50], res[N + 50];
basic_string<int> v[N + 50];

int main()
{

    cin >> n >> m >> t;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        cin >> j >> k;
        v[j] += k;
        v[k] += j;
    }
    memset(f, -1, sizeof(f));
    queue<int> q;
    f[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        for (auto i : v[k])
            if (f[i] == -1)
            {
                f[i] = f[k] + 1;
                q.push(i);
            }
    }
    for (i = 1; i <= n; i++)
        res[a[i]] = max(res[a[i]], f[i]);
    for (i = 1; i <= t; i++)
        cout << res[i] << ' ';
}