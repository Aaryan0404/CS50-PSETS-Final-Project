# Imports get_int function from cs50 library #
from cs50 import get_int

# Asks user for height input #
h = get_int("Height: ")

# Checks if input is in the valid range #
while (h < 1) or (h > 8):
    h = get_int("Height: ")
    if (h > 1) and (h < 8):
        break

else:
    # Loop creates half-pyramid according to height input #
    for x in range(h):
        for y in range(h - (x + 1)):
            print(" ", end="")
        for z in range(x + 1):
            print("#", end="")
        print()