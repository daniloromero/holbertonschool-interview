#!/usr/bin/python3
"""
Module that determines if a given data set represents a valid UTF-8 encodin
"""


def validUTF8(data):
    """method that determines if a given data set represents
    a valid UTF-8 encoding
    """
    byte_size = 0
    for byte in data:
        if byte_size == 0:
            if byte >> 5 == 0b110:
                byte_size += 1
            if byte >> 4 == 0b1110:
                byte_size += 2
            if byte >> 3 == 0b11110:
                byte_size += 3
        else:
            if byte >> 6 != 0b10:
                return False
            byte_size -= 1
    return True
