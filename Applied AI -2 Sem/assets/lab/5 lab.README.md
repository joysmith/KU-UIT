## Implement backtracking for n-queens

```py
class QueensProblem:
    # This class helps us solve the N-Queens puzzle

    def __init__(self, n):
        # n means how many queens and how big the chess board is
        self.n = n
        # Make an empty chess board filled with 0 (no queens yet)
        self.chess_table = [[0 for i in range(n)] for j in range(n)]

    def solve_n_queens(self):
        # Start solving by placing the first queen in column 0
        if self.solve(0):
            # If we found a solution, show the board
            self.print_queens()
        else:
            # If no solution is possible, print this message
            print('There is no solution to the problem...')

    # col_index tells us which column we are putting a queen in
    def solve(self, col_index):

        # If we placed queens in all columns, we are done!
        if col_index == self.n:
            return True

        # Try putting the queen in every row of this column
        for row_index in range(self.n):

            # Check if it is safe to place the queen here
            if self.is_place_valid(row_index, col_index):

                # Put the queen (1 means queen is placed)
                self.chess_table[row_index][col_index] = 1

                # Now try to place the next queen in the next column
                if self.solve(col_index+1):
                    return True

                # If it didn’t work, remove the queen (this is called backtracking)
                print('BACKTRACKING ...')
                self.chess_table[row_index][col_index] = 0

        # If no row worked in this column, return False
        return False

    def is_place_valid(self, row_index, col_index):

        # Check the same row to see if another queen is already there
        for i in range(self.n):
            if self.chess_table[row_index][i] == 1:
                return False  # Not safe!

        # We do not check the column
        # Because we only put one queen in each column

        # Check diagonal from top-left to bottom-right
        j = col_index
        for i in range(row_index, -1, -1):

            if i < 0:
                break  # Stop if we go outside the board

            if self.chess_table[i][j] == 1:
                return False  # Not safe!

            j = j - 1  # Move left

        # Check diagonal from bottom-left to top-right
        j = col_index
        for i in range(row_index, self.n):

            if j < 0:
                break  # Stop if we go outside the board

            if self.chess_table[i][j] == 1:
                return False  # Not safe!

            j = j - 1  # Move left

        # If no queen can attack this place, it is safe
        return True

    def print_queens(self):
        # Print the board nicely
        for i in range(self.n):
            for j in range(self.n):
                if self.chess_table[i][j] == 1:
                    print(' Q ', end='')  # Show queen
                else:
                    print(' - ', end='')  # Show empty space
            print('\n')  # Move to next row


if __name__ == '__main__':
    # Create a board with 100 queens
    queens = QueensProblem(100)
    # Start solving the puzzle
    queens.solve_n_queens()

```