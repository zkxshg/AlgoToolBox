// Rabin–Karp string-searching algorithm with Rolling Hash
// https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm

#define ll long long
const unsigned PRIME_BASE = 257;
const unsigned PRIME_MOD = 1000000007;

// Fast exponentiation
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % PRIME_MOD;
        a = a * a % PRIME_MOD;
        b >>= 1;
    }
    return res;
}

unsigned rollingHash(const string& s, int start, int len) {
    long long ret = 0;
    for (int i = start; i < start + len; i++) {
        ret = ret * PRIME_BASE + s[i];
        ret %= PRIME_MOD;
    }
    return ret;
}

int findSubstringPos(const string& s, const string& w) {
    int slen = s.size(), wlen = w.size();
    if (slen == 0 || wlen == 0 || wlen > slen) return -1;

    ll ppow = qpow(PRIME_BASE, wlen - 1);

    unsigned hashW = rollingHash(w, 0, wlen);
    unsigned hashS = rollingHash(s, 0, wlen);

    for (int i = 0; i <= slen - wlen; i++) {
        if (hashS == hashW && s.substr(i, wlen) == w) {
            return i;
        }

        if (i < slen - wlen) {
            hashS -= s[i] * ppow % PRIME_MOD;
            if (hashS < 0) hashS += PRIME_MOD;
            hashS *= PRIME_BASE;
            hashS += s[i + wlen];
            hashS %= PRIME_MOD;
        }
    }

    return -1;
}
