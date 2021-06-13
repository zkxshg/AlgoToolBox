// Return Greatest Common Divisor by Euclidean algorithm

#define ll long long

using namespace std;

ll gcd(ll m, ll n) {
    ll t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}
