from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    list_string_A = []
    list_string_B = []
    similar_line = []

    string_a = a.split('\n')
    string_b = b.split('\n')

    for line in string_a:
        list_string_A.append(line.rstrip())

    for line in string_b:
        list_string_B.append(line.rstrip())

    for x in list_string_A:
        for y in list_string_B:
            if (x == y):
                similar_line.append(x)

    f = set(similar_line)
    u = list(f)
    return u


def sentences(a, b):
    """Return sentences in both a and b"""

    sentences_a = set(sent_tokenize(a))
    sentences_b = set(sent_tokenize(b))
    similar_sentence = set()

    for a in sentences_a:
        for b in sentences_b:
            if (a == b):
                similar_sentence.add(a)

    g = list(similar_sentence)
    return g


def substring_divider(string, boo):
    substring_list = []
    x = 0
    y = boo
    for i in range((len(string) - (boo-1))):
        substring_list.append(string[x:y])
        x = x + 1
        y = y + 1

    return substring_list


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    substring_list_a = substring_divider(a, n)
    substring_list_b = substring_divider(b, n)
    common_substrings = []

    for j in substring_list_a:
        for u in substring_list_b:
            if (j == u):
                common_substrings.append(j)

    p = set(common_substrings)
    return p
