#!/usr/bin/python3
"""calculate how many square units of water will be retained after it rains"""


def rain(walls):
    """calculate how many square units of water will be retained after it rains
    Args:
        walls: a list of non-negative integers
    Return: integer indicating total amount of rainwater retained.
            If the list is empty return 0.
    """
    if type(walls) != list or len(walls) < 3:
        return 0
    # if len([*filter(lambda x: x < 0, walls)]) > 0:
    #    return 0
    l_height = 0
    r_height = 0
    width = 0
    water = 0
    for i in range(len(walls)):
        if l_height == 0 and walls[i] > 0:
            l_height = walls[i]
        if l_height and walls[i] != 0:
            r_height = walls[i]
        if walls[i] == 0:
            width += 1
        if walls[i] != 0 and r_height:
            water += min(l_height, r_height) * width
            width = 0
            l_height = r_height
    return water
