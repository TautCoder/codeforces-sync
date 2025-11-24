#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        unsigned int n;
        cin >> n;

        if (n == 0)
        {
            cout << "YES\n";
            continue;
        }

        // Convert n to binary without leading zeros
        string b = bitset<32>(n).to_string();
        b = b.substr(b.find('1'));

        // Count trailing zeros in n
        int tz = __builtin_ctz(n);

        // Add tz leading zeros to match required palindrome length
        string padded = string(tz, '0') + b;

        // Check palindrome
        if (!isPalindrome(padded))
        {
            cout << "NO\n";
            continue;
        }

        // If palindrome length is odd, middle must be 0
        if (padded.size() % 2 == 1)
        {
            int mid = padded.size() / 2;
            if (padded[mid] == '1')
            {
                cout << "NO\n";
                continue;
            }
        }

        cout << "YES\n";
    }

    return 0;
}
