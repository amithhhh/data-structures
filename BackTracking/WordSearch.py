directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]

def wordSearch(board, word):
    rows = len(board)
    col = len(board[0])

    def is_safe(x, y):
        return 0 <= x < rows and 0 <= y < col
    
    def backtrack(x, y, index):
        if index == len(word):
            return True
        
        if not is_safe(x, y) or board[x][y] != word[index]:
            return False
        
        temp = board[x][y]
        board[x][y] = '#'

        for dx, dy in directions:
            if backtrack(x + dx, y + dy, index + 1):
                return True
            
        board[x][y] = temp
        return False
    
    for i in range(rows):
        for j in range(col):
            if board[i][j] == word[0]:
                if backtrack(i, j, 0):
                    print("Matching Found")
                    return True

    print("No Match Found")
    return False


board = [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ASA"

wordSearch(board, word)