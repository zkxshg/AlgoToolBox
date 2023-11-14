The algorithm implemented in `String_SufTrie.cpp` is designed to solve the problem of finding all concatenated words in a given list of words. Here, a concatenated word is defined as a word that is made up of the full length of other words in the list.

The algorithm uses a Trie (also known as a Prefix Tree or Suffix Tree) data structure, which is particularly efficient for solving problems related to strings.

**Goal of Algorithm:**
The main goal of this algorithm is to find all the concatenated words in a given list of words.

**Input:**
The function `findAllConcatenatedWordsInADict` takes a vector of strings `words` as input.

**Output:**
The function returns a vector of strings that contains all the concatenated words in `words`.

**Algorithm Steps:**

1. **Trie Initialization:** The algorithm starts by constructing an empty Trie with a root node.

2. **Word Sorting:** The words in the input list are sorted in ascending order by their lengths.

3. **Word Addition and Search:** The algorithm iterates over each word in `words`. For each word, it first checks if the word can be formed by concatenating other words that have been added to the Trie (using the `search` method). If the word is a concatenated word, it is added to the result list. Regardless of whether it is a concatenated word or not, the word is added to the Trie (using the `add` method).

The `search` method is a recursive function that tries to match the input string with the paths in the Trie. It considers the current word as a concatenated word if it can find a previously added word in the Trie that is a prefix of the current word, and the remaining part of the current word is also a concatenated word.

The `add` method is a function that adds a string to the Trie. It creates a path in the Trie that corresponds to the string, and marks the end node of the path as an end of a word.

**Time Complexity:**
The time complexity of the algorithm is O(n*m^2), where n is the number of words and m is the average length of the words. This is because, for each word, the algorithm could potentially need to traverse its length twice (once for the `add` method and once for the `search` method), and it does this for all words.

**Space Complexity:**
The space complexity of the algorithm is O(n*m), which is the space required for the Trie.

For example, given the input `words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatsdogcat"}`, the `findAllConcatenatedWordsInADict` function will return `{"catsdogcats","dogcatsdog","ratcatsdogcat"}` as these words can be formed by concatenating other words in the list.
