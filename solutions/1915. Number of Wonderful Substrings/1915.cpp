class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    long long ans = 0;
    int prefix = 0;           // binary prefix
    vector<int> count(1024);  // binary prefix count
    count[0] = 1;             // empty string ""

    for (const char c : word) {
      prefix ^= 1 << (c - 'a');
      ans += count[prefix];         // all chars occur even times
      for (int i = 0; i < 10; ++i)  // ('a' + i) occurs odd times
        ans += count[prefix ^ (1 << i)];
      ++count[prefix];
    }

    return ans;
  }
};
