# 3. Implementing DFS in 2d array

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

<br>
<br>

# Implementing BFS in 2d array

```py
from collections import deque

# This is our number grid (matrix)
test_matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
]

# These tell us how to move: up, right, down, left
directions = [
    (-1, 0),  # move up
    (0, 1),   # move right
    (1, 0),   # move down
    (0, -1)   # move left
]


# This function walks through the grid using BFS
def traversal_bfs(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    # Make a grid to remember visited places
    seen = [[False for _ in range(cols)] for _ in range(rows)]

    # Store the numbers we collect
    values = []

    # A queue to remember where to go next
    queue = deque()
    queue.append((0, 0))  # start from top-left corner

    # Keep going while there are places to visit
    while queue:
        row, col = queue.popleft()  # take the first place

        # Skip if outside the grid or already visited
        if row < 0 or row >= rows or col < 0 or col >= cols or seen[row][col]:
            continue

        # Mark this place as visited
        seen[row][col] = True

        # Save the number here
        values.append(matrix[row][col])

        # Add all nearby places to the queue
        for dr, dc in directions:
            queue.append((row + dr, col + dc))

    return values


# Run the program
print(traversal_bfs(test_matrix))

```
