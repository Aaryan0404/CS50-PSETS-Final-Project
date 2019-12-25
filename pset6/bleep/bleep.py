from cs50 import get_string
import sys
import curses.ascii


def load(file):
    banned_words = list()
    banned_file = open(file, "r")
    for line in banned_file:
        banned_words.append(line.rstrip("\n"))
    banned_file.close()
    return banned_words
    
    
def main(abc):
    if (abc == 0):
        print("Usage: python bleep.py dictionary")
        exit(1)
    
    input_text = get_string("What message would you like to censor?\n")
    
    x = len(abc)
    
    act_list = load(abc)
    input_text_list = list(input_text.split())

    g = 0
    for u in input_text_list:
        for s in act_list:
            if ((u == s) or (u.lower() == s) or (u.upper() == s)):
                d = "*"
                f = len(u)
                input_text_list.remove(u)
                for x in range(f - 1):
                    d = d + "*"
                input_text_list.insert(g, d)
            else:
                g = g
        g = g + 1
    
    final = " ".join(input_text_list)
    print(f"{final}")


# Runs the entire program if command-line inputs are valid #
if (len(sys.argv) == 2):
    if __name__ == '__main__':
        main(sys.argv[1])
else:
    if __name__ == '__main__':
        main(0)
