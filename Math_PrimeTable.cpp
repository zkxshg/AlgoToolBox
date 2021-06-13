// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// Build prime filter to count the primes

deque<bool> BuildPrimeTable(int n) {
    deque<bool> isPri(n + 1, true);
    isPri[0] = false; isPri[1] = false;
    int ub = sqrt(n);
    for (int i = 2; i <= ub; i++) {
        if (isPri[i]) {
            int st = i * i;
            while (st <= n) {
                isPri[st] = false;
                st += i;
            }
        }
    }
    return isPri;
}

int countPrime(int n) {
    deque<bool> primT = BuildPrimeTable(n);
    int cou = 0;
    for (bool b : primT) if (b) cou++;
    return cou;
}
