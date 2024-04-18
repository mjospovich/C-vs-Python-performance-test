from time_mem_measure import print_time_and_memory


def count_letters():
    """Loads the sample text from file and counts the number of letters in it (cap sensitive)."""
    
    with open("assets/sample_text.txt") as file:
        text = file.read()

    dict = {}
    skipped = [" ", ".", ",", "!", "?", ":", "\n"]

    for let in set(text):
        if let not in skipped:
            dict[let] = 0

    for let in text:
        if let not in skipped:
            dict[let] += 1

    print(dict)


if __name__ == "__main__":
    print_time_and_memory(count_letters, 20)