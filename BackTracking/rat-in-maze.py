def findPaths(maze, n):
    result = []
    visited = [[False for _ in range(n)] for _ in range(n)]

    def isSafe(x, y):
        return 0 <= x < n and 0 <= y < n and maze[x][y] == 1 and not visited[x][y]
    
    def backtrack(x, y, path):
        if x == n-1 and y == n-1:
            result.append(path[:])
            return
        visited[x][y] = True

        if isSafe(x + 1, y):
            backtrack(x + 1, y, path + 'D')
        if isSafe(x, y - 1):
            backtrack(x, y-1, path + 'L') 
        if isSafe(x - 1, y):
            backtrack(x - 1, y, path + 'U')
        if isSafe(x, y + 1):
            backtrack(x, y + 1, path + 'R')

        visited[x][y] = False

    if maze[0][0] == 1:
        backtrack(0, 0, "")
    return result


maze = [
    [1, 0, 0, 0],
    [1, 1, 0, 1],
    [1, 1, 0, 0],
    [0, 1, 1, 1]
]

print(findPaths(maze, 4))