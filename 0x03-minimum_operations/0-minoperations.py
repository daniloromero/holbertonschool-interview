#!/usr/bin/python3
"""
method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """ calculates the fewest number of operations needed """
    if type(n) is not int or n == 1:
        return 0
    H = 1
    paste = H
    op = 0
    while H < n:
        if n % H == 0:
            paste = H
            H *= 2
            op += 2
        else:
            H += paste
            op += 1
    return op
