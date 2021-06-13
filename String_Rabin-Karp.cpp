bool RabinKarp(string s, vector<string>& wordDict) {
    int slen = s.size(), wlen = wordDict.size();
    if (slen == 0) return true;
    if (wlen == 0) return false;

    if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) return true;

    map<string, bool> dict;
    for (string str : wordDict) dict[str] = true;

    deque<bool> dij(slen + 1, false); dij[0] = true;
    for (int i = 1; i <= slen; i++) {
        for (int j = 0; j < i; j++) {
            if (dij[j]) {
                if (dict[s.substr(j, i - j)]) {
                    dij[i] = true; break;
                };
            }
        }
    }

    return dij[slen];
}