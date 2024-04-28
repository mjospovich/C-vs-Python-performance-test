from time_mem_measure import print_time_and_memory
import numpy as np
import pandas as pd


# Second test function. It is O(N^3) time complexity, where N is one dimension of the matrix.
def matrix_multiplication():
    """Loads two matrices from csv files and multiplis them."""

    # load the matrices from csv files
    matrix1 = pd.read_csv('assets/matrix1.csv', header=None).values
    matrix2 = pd.read_csv('assets/matrix2.csv', header=None).values

    # multiply the matrices
    result = np.dot(matrix1, matrix2)

    # print the result
    #print(result)


if __name__ == '__main__':
    print_time_and_memory(matrix_multiplication, 1)