// Multiply of two large number

# define ll long long

ll qmul(ll x, ll y, ll mod) 
{
    ll ret = 0;
    while (y) {
        if (y & 1)
            ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
}
