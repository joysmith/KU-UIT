# Day 9

> **_Business Objective: Secret Auction_**

<img src="notes/secret_auction.gif" >

| Technology    | Description     |
| ------------- | --------------- |
| `Language`    | python          |
| `Framework`   | -               |
| `Library`     | -               |
| `Text editor` | Vs code, replit |

---

## Exercise

- https://repl.it/@lenargasimov/day-9-1-exercise#main.py
- https://repl.it/@lenargasimov/day-9-2-exercise#main.py

## Secret Auction

1. create file "art.py"

```py
logo = '''
                         ___________
                         \         /
                          )_______(
                          |"""""""|_.-._,.---------.,_.-._
                          |       | | |               | | ''-.
                          |       |_| |_             _| |_..-'
                          |_______| '-' `'---------'` '-'
                          )"""""""(
                         /_________\\
                       .-------------.
                      /_______________\\
'''
```

2. Create file "main.py"

```py
from art import logo
print(logo)

bids = {}
bidding_finished = False

def find_highest_bidder(bidding_record):
  highest_bid = 0
  winner = ""

  for bidder in bidding_record:
    bid_amount = bidding_record[bidder]
    if bid_amount > highest_bid:
      highest_bid = bid_amount
      winner = bidder
  print(f"The winner is {winner} with a bid of ${highest_bid}")

while not bidding_finished:
  name = input("What is your name?: ")
  price = int(input("What is your bid?: $"))
  bids[name] = price
  should_continue = input("Are there any other bidders? Type 'yes or 'no'.\n")
  if should_continue == "no":
    bidding_finished = True
    find_highest_bidder(bids)
  elif should_continue == "yes":
    clear()
```
