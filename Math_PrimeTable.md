The algorithm implemented in `Math_PrimeTable.cpp` is the Sieve of Eratosthenes. This algorithm efficiently generates a list of all prime numbers up to a given limit and counts the number of primes.

**Goal of Algorithm:**
The main goal of the algorithm is to generate a boolean array representing prime numbers (true for prime, false for non-prime), up to a given number `n`, and to count the total number of prime numbers up to `n`.

**Input:**
The function `countPrime` takes an integer `n` as an input.

**Output:**
The function returns an integer representing the total count of prime numbers up to `n`.

**Algorithm Steps:**

1. **Initialize the Prime Table:** The algorithm first initializes a boolean deque `isPri` of size `n+1` with all elements set to true, except for the first two elements (0 and 1) which are set to false because 0 and 1 are not prime numbers.

2. **Identify the Primes:** Using a for loop that iterates from 2 to the square root of `n` (inclusive), the algorithm checks each number `i`. If `i` is still marked as a prime (i.e., `isPri[i]` is true), then all multiples of `i` are not prime numbers, so the algorithm sets `isPri[st]` to false for all multiples of `i`, starting from `i*i`.

3. **Count the Primes:** The `countPrime` function calls `BuildPrimeTable` to get the prime table, and then counts and returns the number of true values in the table (i.e., the number of prime numbers).

**Time Complexity:** The time complexity of the `BuildPrimeTable` function is O(n log log n) due to the Sieve of Eratosthenes algorithm. The `countPrime` function has a time complexity of O(n) because it iterates through the prime table once.

**Space Complexity:** The space complexity of the algorithm is O(n) because it uses a deque of size `n+1` to store the prime table.

For example, given the input `n = 10`, the `countPrime` function will return 4, as there are four prime numbers (2, 3, 5, 7) less than or equal to 10.
