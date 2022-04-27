// https://leetcode.com/problems/smallest-string-with-swaps/
// Union-Find + Sorting

class Solution {
public:
    unordered_map<int, int> U;
    
    int find(int a) {
        if (!U.count(a)) return U[a] = a;
        if (U[a] == a) return a;
        return U[a] = find(U[a]);
    }
    
    string UnionFind(string s, vector<vector<int>>& pairs) {
        U.clear();
        
        int n = s.size();
        
        for (int i = 0; i < n; i++) U[i] = i;
        
        for (auto& p : pairs) {
            int ua = find(p[0]);
            int ub = find(p[1]);
            
            if (ua != ub) U[ub] = ua;
        }
        
        unordered_map<int, vector<int>> uni;
        
        for (int i = 0; i < n; i++) uni[find(i)].push_back(i);
        
        string res = s;
        
        for (auto& G : uni) {
            vector<char> tem;
            
            vector<int>& v = G.second;
            
            for (int ind : v) tem.push_back(s[ind]);
            
            sort(tem.begin(), tem.end());
            
            int cou = 0;
            for (int ind : v) res[ind] = tem[cou++];
        }
        
        return res;
    }
};

// https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86

unordered_map<int, int> p;

int find(int a) {
    if (!p.count(a)) return p[a] = a;
    if (p[a] == a) return a;
    return p[a] = find(p[a]);
}

int largestComponentSize(vector<int>& A) {
    int n = A.size();
    for (int a : A)
        p[a] = a;
    for (int a : A)
        for (int i = 2; i <= sqrt(a); ++i)
            if (a % i == 0) {
                p[find(a)] = p[find(i)];
                p[find(a)] = p[find(a / i)];
            }
    unordered_map<int, int> cnt;
    int res = 1;
    for (int a : A)
        res = max(res, ++cnt[find(a)]);
    return res;
}
