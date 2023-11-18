class SegmentTree {
public:
    int tree[800001]; // Increase the size to accommodate intervals
    
    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
            return;
        }
        
        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid);
        buildTree(2 * node + 1, mid + 1, end);
        
        tree[node] = 0;
    }
    
    void update(int node, int start, int end, int left, int right) {
        if (left > end || right < start)
            return;
        
        if (left <= start && end <= right) {
            tree[node]++;
            return;
        }
        
        int mid = (start + end) / 2;
        update(2 * node, start, mid, left, right);
        update(2 * node + 1, mid + 1, end, left, right);
    }
    
    int query(int node, int start, int end, int left, int right) {
        if (left > end || right < start)
            return 0;
        
        if (left <= start && end <= right)
            return tree[node];
        
        int mid = (start + end) / 2;
        int leftCount = query(2 * node, start, mid, left, right);
        int rightCount = query(2 * node + 1, mid + 1, end, left, right);
        
        return leftCount + rightCount;
    }
    
    void createSegmentTree(const vector<pair<int, int>>& intervals) {
        int maxEnd = 0;
        for (auto& interval : intervals) {
            maxEnd = max(maxEnd, interval.second);
        }
        
        buildTree(1, 0, maxEnd);
        
        for (auto& interval : intervals) {
            int left = interval.first;
            int right = interval.second;
            update(1, 0, maxEnd, left, right);
        }
    }
    
    int* getSegmentTree() {
        return tree;
    }
};
