// https://leetcode.com/problems/shortest-palindrome/

#define ll long long
const unsigned PRIME_BASE = 257;
const unsigned PRIME_MOD = 1000000007;

// 快速幂
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % PRIME_MOD;
        a = a * a % PRIME_MOD;
        b >>= 1;
    }
    return res;
}

unsigned hash(const string& s)
{
    long long ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret = ret*PRIME_BASE + s[i];
        ret %= PRIME_MOD;
    }
    return ret;
}

string shortestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;

    string revStr = s;
    reverse(revStr.begin(), revStr.end());

    long long hash1 = hash(s);
    long long hash2 = hash(revStr);

    ll ppow = qpow(PRIME_BASE, n - 1);

    if (hash1 == hash2) return s;

    bool same = false; int tn = n;
    while (!same && tn > 0) {
        // remove s last letter
        hash1 -= s[tn - 1] * qpow(PRIME_BASE, n - tn) % PRIME_MOD; 
        hash1 %= PRIME_MOD;
        if (hash1 < 0) hash1 += PRIME_MOD;

        // remove rs first letter;
        hash2 -= s[tn - 1] * ppow % PRIME_MOD; 
        if (hash2 < 0) hash2 += PRIME_MOD;
        hash2 *= PRIME_BASE; hash2 %= PRIME_MOD;

        if (hash1 == hash2) {
            same = true; break;
        }
        // cout << hash1 << ":" << hash2 << endl;
        tn--;
    }

    string res = "";

    if (!same) {
        res += s.substr(1);
        reverse(res.begin(), res.end());
        res += s;
    }
    else {
        res += s.substr(tn - 1);
        reverse(res.begin(), res.end());
        res += s;
    }

    return res;
}
