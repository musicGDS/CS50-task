from cs50 import get_float

coin = 0

change = 0

while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

changeCents = round(change * 100)

while (changeCents - 25) >= 0:
    changeCents = changeCents - 25
    coin += 1

while (changeCents - 10) >= 0:
    changeCents = changeCents - 10
    coin += 1

while (changeCents - 5) >= 0:
    changeCents = changeCents - 5
    coin += 1

while (changeCents - 1) >= 0:
    changeCents = changeCents - 1
    coin += 1

print (coin)
