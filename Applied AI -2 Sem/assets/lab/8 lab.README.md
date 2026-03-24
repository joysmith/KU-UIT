## 8 Implement forward/backward chaining on a small rule-based knowledge base

<img src="../assets/forward backward chaining" width="700">

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


### Challenge Any (12)

1. Add a new fact "windy" and display it with other facts.
1. Add a rule "windy → cold" and test the output.
1. Change starting fact from "cloudy" to "rain" and observe changes.
1. Print each fact on a new line instead of a list.
1. Count total number of facts and print the count.
1. Change backward chaining goal from "dry" to "umbrella".
1. Print "No new facts found" when forward chaining stops.
1. Add rule "cold → wear_jacket" and test it.
1. Add multiple starting facts like "cloudy" and "windy".
1. Ensure duplicate facts are not added (explain how it works).
1. Print all rules in a readable format before execution.
1. Add rule "rain → wet_ground" and check result.
1. Change backward chaining goal to "wet_ground".
1. Add a rule that never gets triggered and explain why.
1. Modify rules so one result needs two conditions (e.g., "cloudy AND humid → rain").
1. Create your own story and convert it into rules.
1. Take user input for starting fact and use it in the program.
1. Count and print number of steps taken in forward chaining.
1. Modify backward chaining to print full reasoning path (e.g., dry → umbrella → rain → cloudy).
1. Add a goal like "snow" and show proper failure message if it cannot be proven.