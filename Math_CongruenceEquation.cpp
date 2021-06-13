#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define ll long long

using namespace std;

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

int t;
ll k = 360 * 12 * 1e10;
ll r;

ll couI(ll i11, ll i719) {
    ll i51 = i11 * 70 % k - i719 % k;
    ll i4 = i11 * 5 % k - i51 % k;

    ll ind = i4 * 3 % k - i11 % k;
    if (ind < 0) ind += k;

    return ind % k;
}
bool ifHour(ll h, ll m, ll s) {
    ll i11 = (h * 12 - m) % k; if (i11 < 0) i11 += k;

    ll i719 = (qmul(h, 720, k) - s) % k; if (i719 < 0) i719 += k;
    //cout << "i11 = " << i11 << ", i719 = " << i719 << endl;

    ll i11_719 = (i11 * 719) % k, i719_11 = (i719 * 11) % k;
    //cout << "i11_719 = " << i11_719 << ", i719_11 = " << i719_11 << endl;
    if (i11_719 == i719_11) {
        r = couI(i11, i719);
        return true;
    }
    return false;
}

int main() {
    ll t2d = 12 * 1e10;

    cin >> t;
    int caseNum = 1;

    while (t) {
        t--;
        ll a, b, c;
        cin >> a; cin >> b; cin >> c;

        int ai = a / t2d, bi = b / t2d, ci = c / t2d;

        ll h = 0, m = 0, s = 0;

        if (ifHour(c, b, a)) {
            h = c; m = b; s = a;
            h = (h - r) % k; m = (m - r) % k; s = (s - r) % k;
        }
        else if (ifHour(c, a, b)) {
            h = c; m = a; s = b;
            h = (h - r) % k; m = (m - r) % k; s = (s - r) % k;
        }
        else if (ifHour(a, b, c)) {
            h = a; m = b; s = c;
            h = (h - r) % k; m = (m - r) % k; s = (s - r) % k;
        }
        else if (ifHour(a, c, b)) {
            h = a; m = c; s = b;
            h = (h - r) % k; m = (m - r) % k; s = (s - r) % k;
        }
        else if (ifHour(b, a, c)) {
            h = b; m = a; s = c;
            h = (h - r) % k; m = (m - r) % k; s = (s - r) % k;
        }
        else if (ifHour(b, c, a)) {
            h = b; m = c; s = a;
            h = (h - r) % k; m = (m - r) % k; s = (s - r) % k;
        }

        if (h < 0) h += k; int hi = h / t2d / 30;
        if (m < 0) m += k; int mi = m / t2d / 6;
        if (s < 0) s += k; int si = s / t2d / 6;

        ll hs = h, hsUB = 1e9;
        hs = hs % hsUB;

        cout << "Case #" << caseNum++ << ": " << hi << " " << mi << " " << si << " " << hs << endl;
    }

    return 0;

}