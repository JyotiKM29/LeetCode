class Solution:
  def minAreaFreeRect(self, points: List[List[int]]) -> float:
    ans = inf
    # for each A, B pair points, {hash(A, B): (ax, ay, bx, by)}
    centerToPoints = defaultdict(list)

    for ax, ay in points:
      for bx, by in points:
        center = ((ax + bx) / 2, (ay + by) / 2)
        centerToPoints[center].append((ax, ay, bx, by))

    def dist(px: int, py: int, qx: int, qy: int) -> float:
      return (px - qx)**2 + (py - qy)**2

    # for all pair points "that share the same center"
    for points in centerToPoints.values():
      for ax, ay, _, _ in points:
        for cx, cy, dx, dy in points:
          # AC is perpendicular to AD
          # AC dot AD = (cx - ax, cy - ay) dot (dx - ax, dy - ay) == 0
          if (cx - ax) * (dx - ax) + (cy - ay) * (dy - ay) == 0:
            squaredArea = dist(ax, ay, cx, cy) * dist(ax, ay, dx, dy)
            if squaredArea > 0:
              ans = min(ans, squaredArea)

    return 0 if ans == inf else sqrt(ans)
