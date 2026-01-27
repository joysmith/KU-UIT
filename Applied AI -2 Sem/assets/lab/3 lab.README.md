# 3. Implementing DFS

```py
# This is our number grid (matrix)
test_matrix = [
    [1, 2, 3, 4, 5],
    [6, 7, 8, 9, 10],
    [11, 12, 13, 14, 15],
    [16, 17, 18, 19, 20]
]

# These tell us how to move: up, right, down, left
directions = [
    (-1, 0),  # move up
    (0, 1),   # move right
    (1, 0),   # move down
    (0, -1)   # move left
]


# This function starts the DFS walk
def traversal_dfs(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    # Make a same-size grid to remember visited places
    seen = [[False for _ in range(cols)] for _ in range(rows)]

    # Store the numbers we collect
    values = []

    # Start from the top-left corner (0, 0)
    dfs(matrix, 0, 0, seen, values)

    return values


# This function moves around the grid
def dfs(matrix, row, col, seen, values):
    # Stop if we go outside the grid or visit again
    if row < 0 or col < 0 or row >= len(matrix) or col >= len(matrix[0]) or seen[row][col]:
        return

    # Mark this place as visited
    seen[row][col] = True

    # Save the number here
    values.append(matrix[row][col])

    # Try moving in all 4 directions
    for dr, dc in directions:
        dfs(matrix, row + dr, col + dc, seen, values)


# Run the program
print(traversal_dfs(test_matrix))
```
