#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// handy macros
#define YES std::cout << "YES" << std::endl;
#define NO std::cout << "NO" << std::endl;
#define all(x) x.begin(), x.end()
#define vecin(name, len)  \
    vector<ll> name(len); \
    for (auto &_ : name)  \
        cin >> _;
#define vecout(v)         \
    for (auto _ : v)      \
        cout << _ << " "; \
    cout << endl;

// ---------------- PREFIX & SUFFIX UTILITIES ----------------
// Build prefix sum array
template <class T>
vector<T> buildPrefixSum(const vector<T> &v)
{
    int n = v.size();
    vector<T> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + v[i];
    }
    return pref;
}

// Build suffix sum array
template <class T>
vector<T> buildSuffixSum(const vector<T> &v)
{
    int n = v.size();
    vector<T> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + v[i];
    }
    return suf;
}

// Build prefix max array
template <class T>
vector<T> buildPrefixMax(const vector<T> &v)
{
    int n = v.size();
    vector<T> prefMax(n);
    prefMax[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        prefMax[i] = max(prefMax[i - 1], v[i]);
    }
    return prefMax;
}

// Build suffix max array
template <class T>
vector<T> buildSuffixMax(const vector<T> &v)
{
    int n = v.size();
    vector<T> sufMax(n);
    sufMax[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sufMax[i] = max(sufMax[i + 1], v[i]);
    }
    return sufMax;
}

// ---------------- SOLVER ----------------
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 2; i <= n - 1; i += 2)
    {
        if (v[i] != v[i + 1])
        {
            return void(cout << "NO" << endl);
        }
    }
    return void(cout << "YES" << endl);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
// checked for n==1 ?
// all variables initialized correctly
// applied 'mod' correctly ? like (x + mod) % mod;
// does the question have multiple tc's or only 1
// used INT_MAX instead of LLONG_MAX or 32 instead 64!
// thought all : brute-force, greedy, binary-search, graph, dp etc.
// use DP only when GREEDY fails! Or too many cases to handle!
// checked for overflow or not ? may use __int128_t
// use binary expo. instead of pow. Use sqrtl() instead sqrt()!
// perform PRECOMPUTATIONS! if possible... solve by sub-tasks :D