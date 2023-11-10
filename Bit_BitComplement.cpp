// Return bitwise complement of N

// The algorithm's purpose is to return the bitwise complement of a given integer N. 
// In the bitwise complement, all the 1 bits of N are flipped to 0 and all the 0 bits are flipped to 1.

// Input: The algorithm takes an integer N as an input.

// Output: The algorithm returns an integer which is the bitwise complement of N.

// Time complexity: O(1). Space complexity: O(1).

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

// For example, given N = 5 (which is 101 in binary), the output would be 2,
// because the bitwise complement of 5 is 010 in binary, which is 2 in decimal.
