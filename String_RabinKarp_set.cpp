#define ll long long
const unsigned PRIME_BASE = 257;
const unsigned PRIME_MOD = 1000000007;

// Quick power
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % PRIME_MOD;
        a = a * a % PRIME_MOD;
        b >>= 1;
    }
    return res;
}

unsigned hash(const string& s)
{
    long long ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret = ret*PRIME_BASE + s[i];
        ret %= PRIME_MOD;
    }
    return ret;
}

vector<int> RabinKarp(string s, vector<string>& wordDict) {
    int sLen = s.size();
    vector<int> result;

    unordered_map<string, ll> dict;
    ll maxLen = 0;
    for (string& word : wordDict) {
        dict[word] = hash(word);
        if (word.size() > maxLen)
            maxLen = word.size();
    }
    
    ll power = qpow(PRIME_BASE, maxLen - 1);
    vector<ll> hashes(sLen + 1, 0);
    for (int i = 0; i < sLen; i++) {
        hashes[i+1] = (hashes[i]*PRIME_BASE + s[i]) % PRIME_MOD;
    }

    for (int i = 0; i < sLen; i++) {
        for (const auto& [word, target_hash] : dict) {
            int wordLen = word.size();
            if (i + wordLen <= sLen) {
                ll subStr_hash = (hashes[i+wordLen] + PRIME_MOD - (hashes[i]*qpow(PRIME_BASE, wordLen))%PRIME_MOD) % PRIME_MOD;
                if (target_hash == subStr_hash && word == s.substr(i, wordLen)) {
                    result.push_back(i);
                }
            }
        }
    }

    return result;
}
