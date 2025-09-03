
directions = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (-1, 1), (1, -1)]

def getMaximum(array, n):
    visited = [[False for i in range(n)] for i in range(n)]
    
    def is_safe(x, y):
        return 0 <= x < n and 0 <= y < n and array[x][y] == 1 and not visited[x][y]
    
    def backtrack(x, y):
        visited[x][y] = True
        count = 1
        for i, j in directions:
            newX, newY = i + x, j + y
            if is_safe(newX, newY):
                            count += backtrack(newX, newY)
        return count
    
    max_count = 0
    for i in range(n):
          for j in range(n):
                if is_safe(i, j):
                      max_count = max(max_count, backtrack(i, j))
    return max_count


array = [
      [1, 1, 0],
      [0, 1, 1],
      [1, 0, 1]
]

n = 3

print(getMaximum(array, n))

        


