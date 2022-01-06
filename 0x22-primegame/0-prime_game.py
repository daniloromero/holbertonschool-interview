#!/usr/bin/python3
"""Impements a game with primer number between players Maria and Ben"""


def is_prime(n):
    """ Checks if a number given n is a prime number """
    for i in range(2, int(n ** 0.5) + 1):
        if not n % i:
            return False
    return True


def make_prime_list(max_num):
    """Create prime number list from a max given number"""
    prime_list = [0, 0, 2]
    max_prime = prime_list[-1]
    if max_num > max_prime:
        for i in range(max_prime + 1, max_num + 1):
            if is_prime(i):
                prime_list.append(i)
            else:
                prime_list.append(0)

    return prime_list


def isWinner(x, nums):
    """They play x rounds of the game, where n may be different for each round.
        Assuming Maria always goes first  and both players play optimally,
        determine who the winner of each game is.
    Args:
        x is the number of rounds and nums is an array of n
    Return: name of the player that won the most rounds
    If the winner cannot be determined, return None
    You can assume n and x will not be larger than 10000
    You cannot import any packages in this task
    """
    players = {"Maria": 0, "Ben": 0}
    prime_list = make_prime_list(max(nums))

    for i in range(x):
        n = nums[i]
        if n == 1:
            players["Ben"] += 1
            continue
        count = 0
        for k in range(2, n + 1):
            if prime_list[k]:
                count += 1
        if count % 2 != 0:
            players["Maria"] += 1
        else:
            players["Ben"] += 1
    if players["Maria"] > players["Ben"]:
        return "Maria"
    elif players["Maria"] < players["Ben"]:
        return "Ben"
    return None
