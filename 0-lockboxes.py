#!/usr/bin/python3
""" method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""
    to_open = [0] * len(boxes)
    keys = boxes[0]
    to_open[0] = 1
    if len(boxes) > 1:
        for i, key in enumerate(keys):
            if to_open[key] == 1:  # skips opened box
                continue
            keys.extend(boxes[key])
            to_open[key] = 1
            keys = list(set(keys))
            while keys[-1] > len(boxes):  # removes key out of range in boxes
                keys.pop()
        return (sum(to_open) == len(boxes))
    return False
