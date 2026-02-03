Simplifed Backtracking

```py
# Backtracking example for kids
# Rule 1: Don't visit same place twice
# Rule 2: Don't go to Cafe at level 2

tree = {
    "Start": ["Store", "Barber", "Cafe"],
    "Store": ["Cafe", "Barber"],
    "Barber": ["Cafe", "Store"],
    "Cafe": ["Store", "Barber"]
}


def backtrack(node, level, path, visited):

    # stop if already visited (no repeat)
    if node in visited:
        return

    # stop if Cafe at level 2
    if level == 2 and node == "Cafe":
        return

    path.append(node)      # add place to path
    visited.add(node)     # remember visited

    # if path length reaches 4 (Start + 3 moves), print it
    if level == 3:
        print(path)
    else:
        # try all next places
        for child in tree[node]:
            backtrack(child, level + 1, path, visited)

    # go back (remove last place)
    path.pop()
    visited.remove(node)


# start search
backtrack("Start", 0, [], set())

```