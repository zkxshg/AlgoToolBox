The algorithm in `Math_Combination.cpp` is designed to compute the factorial, combination, and permutation of given numbers. 

**Goal of the Algorithm:**
The main goal of this algorithm is to calculate factorials, combinations, and permutations using long long integers, taking modulus with a large number `ub` to prevent overflow.

**Input:**
The functions `factorial`, `combo`, and `permutation` take a long long integer `n` (and an additional `m` for `combo` and `permutation`).

**Output:**
Each function returns the factorial, combination, or permutation of the input numbers.

**Algorithm Steps:**

1. The `qmul` function performs multiplication of large numbers under modulus `ub`.

2. The `qpow` function calculates the power of a number under modulus `ub`.

3. The `factorial` function calculates the factorial of a number using `qmul`.

4. The `combo` function calculates the combination of `n` and `m` using factorials and `qmul`.

5. The `permutation` function calculates the permutation of `n` and `m` using factorials.

**Time Complexity:**
The time complexity of the algorithm is O(N) for factorial calculation and O(1) for combination and permutation calculations, where `N` is the input number.

**Space Complexity:**
The space complexity of the algorithm is O(1), as it uses a fixed amount of space and does not depend on the input size.

For example, if `n` is `5` and `m` is `3`, the output of `factorial(n)` will be `120`, the output of `combo(n, m)` will be `10`, and the output of `permutation(n, m)` will be `60`. These are the factorial, combination, and permutation of `5` and `3` respectively.
