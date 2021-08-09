#define MaxValue 9999999
#define ll long long

ll ub = 1e9 + 7;

const int ub = 1e9 + 7;

// 大数相乘
ll qmul(ll x, ll y) {
    ll ret = 0;
    while (y) {
        if (y & 1)
            ret = (ret + x) % ub;
        x = x * 2 % ub;
        y >>= 1;
    }
    return ret;
}

// 快速幂
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % ub;
        a = a * a % ub;
        b >>= 1;
    }
    return res;
}

// 阶乘
ll factorial(ll n) {
    ll fc = 1;
    for (int i = 1; i <= n; ++i) fc = qmul(fc, i, ub);
    return fc;
}

// 组合数
ll combo(ll n, ll m) {
    if (m == 0 || m == n) return 1;
    ll com = factorial(n) / qmul(factorial(m), factorial(n - m), ub);
    return com;
}

// 排列数
ll permutation(ll n, ll m) {
    ll perm = factorial(n) / factorial(n - m);
    return perm;
}
