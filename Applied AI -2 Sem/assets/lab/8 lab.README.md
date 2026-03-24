## 8 Implement forward/backward chaining on a small rule-based knowledge base

Story: "Ravi and the Rainy Day"

Ravi wakes up and looks outside.

If it is cloudy, then it might rain.
If it rains, Ravi will carry an umbrella.
If Ravi carries an umbrella, he will stay dry.

Today:
It is cloudy

So what will happen?

<br>
Knowledge Base (Rules)

We convert the story into rules:

If cloudy → rain
If rain → umbrella
If umbrella → dry

Fact:

cloudy = True

<br>


```py
# ----------- FORWARD CHAINING -----------
# Forward chaining means:
# Start from facts and move forward to find new facts

# Rules are written like:
# "if this then that"
rules = [
    ("cloudy", "rain"),
    ("rain", "umbrella"),
    ("umbrella", "dry")
]

# Known facts (starting point)
facts = ["cloudy"]

def forward_chaining(rules, facts):
    print("Forward Chaining Start\n")

    # Keep checking until no new facts are added
    while True:
        new_fact_added = False

        for condition, result in rules:
            # If condition is true and result is not already known
            if condition in facts and result not in facts:
                print(f"Because it is {condition}, we can say it is {result}")
                facts.append(result)
                new_fact_added = True

        # Stop if nothing new is found
        if not new_fact_added:
            break

    print("\nFinal Facts:", facts)


# Run forward chaining
forward_chaining(rules, facts.copy())


# ----------- BACKWARD CHAINING -----------
# Backward chaining means:
# Start from goal and go backward to check if it is true

def backward_chaining(goal, rules, facts):
    print(f"\nChecking if '{goal}' is true...")

    # If goal is already a known fact
    if goal in facts:
        print(f"{goal} is already known!")
        return True

    # Check rules to find how to prove the goal
    for condition, result in rules:
        if result == goal:
            print(f"To prove {goal}, we need {condition}")
            return backward_chaining(condition, rules, facts)

    # If no rule found
    print(f"Cannot prove {goal}")
    return False


# Run backward chaining
goal = "dry"
result = backward_chaining(goal, rules, facts)

print(f"\nFinal Answer: Is Ravi dry? -> {result}")
```
