class Solution {
 public:
  int stoneGameVIII(vector<int>& stones) {
    const int n = stones.size();

    vector<int> prefix(stones);
    // dp[i] := max score diff the current player can get when the game starts
    // at i, i.e., stones[0..i] are merged whose value is prefix[i]
    vector<int> dp(n, INT_MIN);

    for (int i = 1; i < prefix.size(); ++i)
      prefix[i] += prefix[i - 1];

    // must take all when there're only two stones left
    dp[n - 2] = prefix.back();

    for (int i = n - 3; i >= 0; --i)
      dp[i] = max(dp[i + 1], prefix[i + 1] - dp[i + 1]);

    return dp[0];
  }
};
