vector<int> sortArray(vector<int>& nums) {
    // QuickSort(nums, 0, nums.size() - 1);
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

void mergeSort(vector<int>& B, int f, int l) {
    if (f == l) return;

    int mid = (f + l) / 2;

    mergeSort(B, f, mid);
    mergeSort(B, mid + 1, l);

    vector<int> temp(l - f + 1);

    int lpos = f, rpos = mid + 1;
    for (int i = 0; i < l - f + 1; i++) {
        if (lpos <= mid && rpos <= l) {
            if (B[lpos] <= B[rpos]) {temp[i] = B[lpos]; lpos++;}
            else {temp[i] = B[rpos]; rpos++;}
        }
        else if (lpos <= mid) {temp[i] = B[lpos]; lpos++;}
        else {temp[i] = B[rpos]; rpos++;}
    }

    for (int i = 0; i < l - f + 1; i++) B[f + i] = temp[i];
}
