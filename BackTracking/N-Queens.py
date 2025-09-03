def solveNQueens(N):
    def is_safe(board, row, col):
        for i in range(row):
            if board[i][col] == 'Q':
                return False
            #checking for upper-left diagonal

            i, j = row - 1, col - 1
            while i >= 0 and j >= 0:
                if board[i][j] == 'Q':
                    return False
                j -= 1
                i -= 1
            
            #checks for upper-right diagonal
            i, j = row - 1, col + 1
            while i >= 0 and j < N:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j += 1

        return True
    
    def backtrack(board, row):
        if row == N:
            solutions.append([''.join(r) for r in board])
            return
        
        for col in range(N):
            if is_safe(board, row, col):
                board[row][col] = 'Q'
                backtrack(board, row + 1)
                board[row][col] = '.'
    board = [['.' for _ in range(N)] for _ in range(N)]
    solutions = []
    backtrack(board, 0)
    return solutions
    
N = 10
solutions = solveNQueens(N)

print(solutions)

for solution in solutions:
    for key in solution:
        print(key)
    print()
        
