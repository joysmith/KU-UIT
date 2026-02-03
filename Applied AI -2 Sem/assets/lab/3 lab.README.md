# 3. Implementing DFS in 2d array

### Uses of DFS:

1. Solving puzzles: Sudoku, mazes, word games.
1. Searching files & folders: Opening folders inside folders.
1. Website links: Visiting one full website path before another.
1. Artificial Intelligence: Trying many choices in games like chess.
1. Maps: Checking all possible paths.

```py
# DFS means go deep first, then come back

# Step 1: create the tree using dictionary
tree = {
    9: [6, 12],
    6: [1, 4],
    12: [34, 45],
    1: [],
    4: [],
    34: [],
    45: []
}

# Step 2: DFS function using recursion
def dfs(node, visited):
    visited.append(node)   # visit the node first

    # go to each child one by one (go deep)
    for child in tree[node]:
        dfs(child, visited)

# Step 3: start DFS
visited = []
dfs(9, visited)

print("DFS Order:", visited)



# Output
# DFS Order: [9, 6, 1, 4, 12, 34, 45]


```

<br>
<br>

# Implementing BFS in 2d array

### Uses of BFS:

1. Finding the shortest path: In maps and GPS to find the closest route.
1. Games: To find the quickest way to reach a goal.
1. Social networks: Finding friends, then friends of friends.
1. Robots: Moving step-by-step safely.
1. Grids and boards: Visiting nearby boxes first.

```py
# BFS means visiting nodes level by level

from collections import deque   # special list that helps remove from front easily

# Step 1: Create the tree using a dictionary
tree = {
    9: [6, 12],     # 9 has two children
    6: [1, 4],      # 6 has two children
    12: [34, 45],   # 12 has two children
    1: [],          # leaves have no children
    4: [],
    34: [],
    45: []
}

# Step 2: BFS function
def bfs(start):
    queue = deque([start])   # put first node in the queue
    visited = []             # store visited nodes

    while queue:             # repeat until queue is empty
        node = queue.popleft()   # take first node (FIFO rule)
        visited.append(node)     # save it

        # add all children of this node to queue
        for child in tree[node]:
            queue.append(child)

    return visited


# Step 3: Run BFS starting from root (9)
result = bfs(9)

print("BFS Order:", result)

# Output
# BFS Order: [9, 6, 12, 1, 4, 34, 45]

```

### BFS Vs DFS

| BFS                  | DFS                  |
| -------------------- | -------------------- |
| Like water spreading | Like climbing a tree |
| Nearest first        | Deep first           |
| Shortest path        | Explore everything   |
