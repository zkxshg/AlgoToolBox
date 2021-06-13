// Return bitwise complement of N

int bitwiseComplement(int N) {
    if (N == 0 || N == 1) return 1 - N;
    int spos = 31;
    while (spos > 0) {
        if (N & (1 << spos)) break;
        spos--;
    }
    for (int i = 0; i < spos + 1; i++) N ^= (1 << i);
    return N;
}
