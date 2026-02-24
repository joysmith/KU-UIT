# Implementing BFS 

### Uses of BFS:

1. Finding the shortest path: In maps and GPS to find the closest route.
1. Games: To find the quickest way to reach a goal.
1. Social networks: Finding friends, then friends of friends.
1. Robots: Moving step-by-step safely.
1. Grids and boards: Visiting nearby boxes first.

```py

class Node:

    def __init__(self, name):
        self.name = name
        self.adjacency_list = []
        self.visited = False


def breadth_first_search(start_node):

    # FIFO: first item we insert will be the first one to take out
    queue = [start_node]
    start_node.visited = True

    # we keep iterating (considering the neighbors) until the queue becomes empty
    while queue:

        # remove and return the first item we have inserted into the list
        actual_node = queue.pop(0)
        print(actual_node.name)

        # let's consider the neighbors of the actual_node one by one
        for n in actual_node.adjacency_list:
            if not n.visited:
                n.visited = True
                queue.append(n)


if __name__ == '__main__':

    # we can create the nodes or vertices
    node1 = Node("A")
    node2 = Node("B")
    node3 = Node("C")
    node4 = Node("D")

    # we have to handle the neighbors
    node1.adjacency_list.append(node2)
    node2.adjacency_list.append(node3)
    node2.adjacency_list.append(node4)
    node3.adjacency_list.append(node4)

    # run the BFS
    breadth_first_search(node1)

```



<br>
<br>

#  Implementing DFS 
### Uses of DFS:

1. Solving puzzles: Sudoku, mazes, word games.
1. Searching files & folders: Opening folders inside folders.
1. Website links: Visiting one full website path before another.
1. Artificial Intelligence: Trying many choices in games like chess.
1. Maps: Checking all possible paths.



#### Iterative solution
```py

class Node:

    def __init__(self, name):
        self.name = name
        self.adjacency_list = []
        self.visited = False


def depth_first_search(start_node):

    # that we need a LIFO: last item we insert is the first one we take out
    stack = [start_node]

    # let's iterate until the stack becomes empty
    while stack:

        # the pop() function returns with the last item we have inserted - O(1)
        actual_node = stack.pop()
        actual_node.visited = True
        print(actual_node.name)

        for n in actual_node.adjacency_list:
            # if the node has not been visited so far
            if not n.visited:
                # insert the item into the stack
                stack.append(n)


if __name__ == '__main__':

    # first we have to create the vertices (nodes)
    node1 = Node("A")
    node2 = Node("B")
    node3 = Node("C")
    node4 = Node("D")
    node5 = Node("E")

    # handle and set the neighbors accordingly
    node1.adjacency_list.append(node2)
    node1.adjacency_list.append(node3)
    node2.adjacency_list.append(node4)
    node4.adjacency_list.append(node5)

    # run the DFS
    depth_first_search(node1)
```

<br>

#### Recursive solution

```py

class Node:

    def __init__(self, name):
        self.name = name
        self.adjacency_list = []
        self.visited = False


def depth_first_search(node):

    node.visited = True
    print(node.name)

    for n in node.adjacency_list:
        if not n.visited:
            depth_first_search(n)


if __name__ == '__main__':

    # first we have to create the vertices (nodes)
    node1 = Node("A")
    node2 = Node("B")
    node3 = Node("C")
    node4 = Node("D")
    node5 = Node("E")

    # handle and set the neighbors accordingly
    node1.adjacency_list.append(node2)
    node1.adjacency_list.append(node3)
    node2.adjacency_list.append(node4)
    node4.adjacency_list.append(node5)

    # run the DFS
    depth_first_search(node1)


```




<br>
<br>

### BFS Vs DFS

| BFS                  | DFS                  |
| -------------------- | -------------------- |
| Like water spreading | Like climbing a tree |
| Nearest first        | Deep first           |
| Shortest path        | Explore everything   |
