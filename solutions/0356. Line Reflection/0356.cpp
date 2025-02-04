class Solution {
 public:
  bool isReflected(vector<vector<int>>& points) {
    int minX = INT_MAX;
    int maxX = INT_MIN;
    unordered_set<pair<int, int>, pairHash> seen;

    for (const auto& p : points) {
      minX = min(minX, p[0]);
      maxX = max(maxX, p[0]);
      seen.insert({p[0], p[1]});
    }

    const int sum = minX + maxX;
    // (leftX + rightX) / 2 = (minX + maxX) / 2
    //  leftX = minX + maxX - rightX
    // rightX = minX + maxX - leftX

    for (const auto& p : points)
      if (!seen.count({sum - p[0], p[1]}))
        return false;

    return true;
  }

 private:
  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};
