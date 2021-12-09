#!/usr/bin/env python3
"""Module that creates list of list representing a pascal traingle"""


def pascal_triangle(n):
    """function that creates list of list representing pascal traingle
    Args:
        n: is an integer for the size of the triangle
    Return: list of list or empty list if n <= 0
    """
    triangle = []
    if n <= 0:
        return triangle
    row = []
    for i in range(1, n + 1):
        # set edges of triangle with 1
        for j in range(1, i + 1):
            if j == 1 or j == len(triangle) + 1:
                row.append(1)
            # Calculate the inner indexes of the triangle
            else:
                row.append(triangle[i - 2][j - 2] + triangle[i - 2][j - 1])
        triangle.append(row)
        row = []
    return triangle
