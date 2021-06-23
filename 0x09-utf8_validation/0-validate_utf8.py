#!/usr/bin/python3
"""
Module that determines if a given data set represents a valid UTF-8 encodin
"""


def validUTF8(data):
    """method that determines if a given data set represents
    a valid UTF-8 encoding
    """
    count = 0
    for byte in data:
        if count == 0:
            if byte >= 192 and byte < 224:
                count += 1
            if byte >= 224 and byte < 240:
                count += 2
            if byte > 240:
                count += 3
        else:
            if byte < 128:
                return False
            count -= 1
    return True
