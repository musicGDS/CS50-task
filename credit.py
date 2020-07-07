import re
from cs50 import get_string

def legitNumber(number):
    x = 1
    y = 0

    lenght = len(number)

    for i in range(lenght - 1, -1, -2):
        x = x + 2 * int(number[i])

    for i in range(lenght, -1, -2):
        y = y + int(number[i])

    if (x + y) % 10 == 0:
        return True
    else:
        return False

# check which brand the car is



cardNumber = get_string("Number: ")

if  cardNumber.isdigit() != True:
    print("foo")
elif re.search("^3[4,7].*", cardNumber) and len(cardNumber) == 15:
    print("AMEX")
elif re.search("^4.*", cardNumber) and len(cardNumber) == 16 or len(cardNumber) == 13 :
    print("VISA")
elif re.search("^5[1-5].*") and len(cardNumber) == 16 :
    print("MASTERCARD")
else:
    print("foo")
