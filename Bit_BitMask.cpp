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