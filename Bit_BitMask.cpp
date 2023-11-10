// Using bit mask to generate all subsequences of string

// Goal of Algorithm:
The algorithm's purpose is to generate all subsequences of a given string characters of a specific length combinationLength.

// Input: a string characters and an integer combinationLength as inputs.
// Output: a vector of strings, which are all the subsequences of characters of length combinationLength.
    
// Time complexity: O(2^n * n). Space complexity: O(2^n * n).
    
vector<string> generAll(string characters, int combinationLength) {
    int len = characters.size();
    int maskLen = 1 << len;
    vector<string> result;

    for (int i = 0; i < maskLen; i++) {
        string str = "";

        bitset<32> bits(i);
        for (int j = 0; j < len; j++) {
            if (bits[j]) str += characters[j];
        }

        if (str.size() == combinationLength) result.push_back(str);
    }
    return result;
}
