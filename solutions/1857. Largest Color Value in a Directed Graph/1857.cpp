class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int n = colors.length();

    int ans = 0;
    int processed = 0;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n);
    queue<int> q;
    vector<vector<int>> count(n, vector<int>(26));

    // build graph
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      ++inDegree[edge[1]];
    }

    // topology
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int out = q.front();
      q.pop();
      ++processed;
      ans = max(ans, ++count[out][colors[out] - 'a']);
      for (const int in : graph[out]) {
        for (int i = 0; i < 26; ++i)
          count[in][i] = max(count[in][i], count[out][i]);
        if (--inDegree[in] == 0)
          q.push(in);
      }
    }

    return processed == n ? ans : -1;
  }
};
