// List all bit sub masks of n

vector<int> subMask(int n) {
  vector<int> subMasks;
  int subs = n;
  while (subs) {
    subMasks.push_back(subs);
    subs = (subs - 1) & n;
  }
  return subMasks;
}
