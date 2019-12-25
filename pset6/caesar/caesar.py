from cs50 import get_string
import math
import sys
import curses.ascii


# Defined functions that rotates certain types of characters according to the Caesar cipher #
def character_replacer(oldchr, m, key):
    newchr = oldchr
    newchr = newchr.replace(oldchr, chr((ord(oldchr) + key) - (26 * (m + 1))), 1)
    return newchr
    

def character_replacer1(oldchr, key):
    newchr = oldchr
    newchr = newchr.replace(oldchr, chr(ord(oldchr) + key))
    return newchr
    
    
# Main Function #
def main(abc):    
    # Conditions and loop check for key input validity #
    if (abc == 0):
        print("Usage: python caesar.py k")
        exit(1)
    x = len(abc)
    for i in range(x):
        if (abc[i].isdigit()):
            key = int(abc)
        else:
            print("Usage: python caesar.py k") 
            exit(1)
            
    key = int(abc)
    # Takes input text #
    plaintext = get_string("plaintext:  ")
    y = len(plaintext)
    # Creates a list of the characters inputted as plaintext - lists can be mutated, but string cannot #
    newtext = list(plaintext)
        
    for j in range(y):
        if (plaintext[j].isalpha()):
            # Conditions to determine type of character (uppercase/lowercase) #
            if (((ord(plaintext[j]) + key > 90) and (ord(plaintext[j]) + key < 97)) or ((ord(plaintext[j]) + key) > 122)):
                if ((ord(plaintext[j]) > 65) and (ord(plaintext[j]) < 91)):
                    m = math.floor(((ord(plaintext[j]) + key) - 91)/26)
                    # Respective element in the list is replaced with new character according to the Caesar cipher #
                    newtext[j] = character_replacer(plaintext[j], m, key)    
                elif ((ord(plaintext[j])) > 96):
                    h = math.floor(((ord(plaintext[j]) + key) - 123)/26)
                    # Respective element in the list is replaced with new character according to the Caesar cipher #
                    newtext[j] = character_replacer(plaintext[j], h, key)
            else: 
                # Respective element in the list is replaced with new character according to the Caesar cipher #
                newtext[j] = character_replacer1(plaintext[j], key)
        # Condition checks and sorts all spaces and punctutation in the plaintext - spaces and punctuation marks are unaffected by the Caesar cipher #
        elif (curses.ascii.isspace(plaintext[j]) or curses.ascii.ispunct(plaintext[j])):
            # Respective element in the list is replaced with new character according to the Caesar cipher #
            newtext[j] = character_replacer1(plaintext[j], 0)
        
    # Joins all elements of the list (now rotated according to the Caesar cipher) to create a string, and prints output ciphertext #
    abc = "".join(newtext)
    print(f"ciphertext: {abc}")
    exit(0)
    

# Runs the entire program if command-line inputs are valid #
if (len(sys.argv) == 2):
    if __name__ == '__main__':
        main(sys.argv[1])
else:
    if __name__ == '__main__':
        main(0)

