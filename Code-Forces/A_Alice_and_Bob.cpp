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
        long long n, a;
        cin >> n >> a;
        vector<long long> v(n);
        for (long long &x : v)
            cin >> x;

        // Step 1: find closest value to a
        long long left = 0, right = 0;

        for (int i = 0; i < n; i++)
        {
            if (v[i] < a)
                left++;
            else
                right++;
        }

        if (left < right)
            cout << a + 1 << endl;
        else
            cout << a - 1 << endl;
    }

    return 0;
}
