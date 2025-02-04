class UglyNum {
  public int prime;
  public int index; // point to the next index of uglyNums
  public int value; // prime * uglyNums[index]
  public UglyNum(int prime, int index, int value) {
    this.prime = prime;
    this.index = index;
    this.value = value;
  }
}

class Solution {
  public int nthSuperUglyNumber(int n, int[] primes) {
    PriorityQueue<UglyNum> pq = new PriorityQueue<>((a, b) -> a.value - b.value);
    int[] uglyNums = new int[n];
    uglyNums[0] = 1;

    for (final int prime : primes)
      pq.offer(new UglyNum(prime, 1, prime * uglyNums[0]));

    for (int i = 1; i < n; ++i) {
      uglyNums[i] = pq.peek().value;
      while (pq.peek().value == uglyNums[i]) {
        final UglyNum u = pq.poll();
        pq.offer(new UglyNum(u.prime, u.index + 1, u.prime * uglyNums[u.index]));
      }
    }

    return uglyNums[n - 1];
  }
}
