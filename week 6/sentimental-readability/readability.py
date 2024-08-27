import cs50


def main():
    """Prompt user for input and print the result."""
    text = cs50.get_string("TEXT: ")

    letter = letters(text)
    sentence = sentences(text)
    word = words(text)

    L = (letter/word) *100
    S = (sentence/word) *100
    index = (0.0588 * L) - (0.296 * S) - 15.8

    if(index < 1):
        print("Before Grade 1")
    if(index > 1 and index <= 16):
        print(f"Grade {round(index)}")
    if(index > 16):
        print("Grade 16+")

    # print(index)
    # print(word)

def letters(text):
    counter = 0
    for i in text:
        if i.isalpha():
            counter+=1

    return counter

def sentences(text):
    counter = 0
    for i in text:
        if i == "." or i == "!" or i == "?":
            counter+=1
    return counter

def words(text):
    counter = 0
    for i in text:
        if i == " " or i == '\0':
            counter+=1
    if(text != None):
        counter+=1
    return counter
main()
