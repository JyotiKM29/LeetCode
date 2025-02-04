class Solution:
  def maxProductDifference(self, nums: List[int]) -> int:
    max1 = -inf
    max2 = -inf
    min1 = inf
    min2 = inf

    for num in nums:
      if num > max1:
        max2 = max1
        max1 = num
      elif num > max2:
        max2 = num
      if num < min1:
        min2 = min1
        min1 = num
      elif num < min2:
        min2 = num

    return max1 * max2 - min1 * min2
