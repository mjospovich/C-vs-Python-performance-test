from time_mem_measure import print_time_and_memory


# Third test function. It is O(N^2) time complexity, where N is the lenght of the list.
def bubble_sort():
    """Sorts a list of numbers using bubble sort algorithm."""

    # load the list of numbers from csv file
    import pandas as pd
    numbers = pd.read_csv('assets/numbers.csv', header=None).values.flatten()

    # bubble sort algorithm
    for i in range(len(numbers)):
        for j in range(len(numbers) - 1):
            if numbers[j] > numbers[j + 1]:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]

    print(numbers)


if __name__ == '__main__':
    print_time_and_memory(bubble_sort)