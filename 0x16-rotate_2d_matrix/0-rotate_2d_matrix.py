#!/usr/bin/python3
"""Module that Rotates a 2D matrix 90 degrees clockwise"""


def rotate_2d_matrix(matrix):
    """Rotate a 2D matrix
    Args:
        matrix 2 dimensional matrix
    Return: Nothing The matrix must be edited in-place.
    """
    N = len(matrix)
    for i in range(N // 2):
        for j in range(i, N - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[N - 1 - j][i]
            matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j]
            matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i]
            matrix[j][N - 1 - i] = temp
