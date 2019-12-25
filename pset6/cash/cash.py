# Imports get_float and floor (rounding down) function #
from cs50 import get_float
from math import floor

# Gets input from user #
change = get_float("Change Owed: ")

while (change < 0):
    change = get_float("Change Owed: ")

# Sets value of types of coins #
cents = change * 100
quarter = 25
dime = 10 
nickel = 5
penny = 1
nc = 0
x = 0

# Calculates maximum number of quarters that can be used #
while (cents >= quarter):
    x = (cents/quarter)
    x = floor(x)
    nc = nc + x
    cents = cents - (quarter * x)
    if (cents < quarter):
        break
    
# Calculates maximum number of dimes that can be used #
while (cents >= dime):
    x = (cents/dime)
    x = floor(x)
    nc = nc + x
    cents = cents - (dime * x)
    if (cents < dime): 
        break
    
# Calculates maximum number of nickels that can be used #
while (cents >= nickel):
    x = (cents/nickel)
    x = floor(x)
    nc = nc + x
    cents = cents - (nickel * x)
    if (cents < nickel): 
        break
   
# Calculates maximum number of pennies that can be used #
while (cents >= penny):
    x = (cents/penny)
    x = floor(x)
    nc = nc + x
    cents = cents - (penny * x)
    if (cents < penny):
        break

# Returns output #
print(f"Coins Owed: {nc}")