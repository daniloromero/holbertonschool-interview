#!/usr/bin/python3
"""determine the fewest number of coins needed to meet a given amount total"""


def makeChange(coins, total):
    """determine the fewest number of coins needed to meet a given amount total
    Args:
        coins is a list of the values of the coins available
        total is the amount the coins must add up
    Return: fewest number of coins needed to meet total
        if total is 0 or less, return 0
        if total cannot be met by any number of coins return -1
    The value of a coin will always be an integer greater than 0
    Assume infinite number of each denomination of coin
    """
    if total <= 0:
        return 0
    coins.sort()
    change = 0
    for iteration in range(len(coins)):
        big = coins.pop()
        coin_set = total / big
        if coin_set >= 1:
            if total % big == 0:
                return change + int(coin_set)
            else:
                total -= int(coin_set) * big
        change += int(coin_set)

    if total:
        return -1
    return change
