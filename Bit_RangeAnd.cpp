// Given two integers left and right that represent the range [left, right], 
// return the bitwise AND of all numbers in this range, inclusive.

int rangeBitwiseAnd(int m, int n) {
    int cou = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        cou++;
    }
    return m<<cou;
}
