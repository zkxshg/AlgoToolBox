// https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm

class Solution {
public:
  vector<vector<int>> dis;

  void floyd(vector<vector<int>>& graph) {
    int n = graph.size();

    dis.resize(n, vector<int>(n, 0x3f3f3f3f));

    for (int i = 0; i < n; i++) 
      for (int j : graph[i]) {
        dis[i][j] = 1; dis[j][i] = 1;
      }

    for (int k = 0; k < n; k++) 
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  }      
};
