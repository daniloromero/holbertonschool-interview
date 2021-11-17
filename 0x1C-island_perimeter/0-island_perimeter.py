#!/usr/bin/python3
"""Returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """
    Args:
        grid is a list of list of integers:
            0 represents water
            1 represents land
            Each cell is square, with a side length of 1
            Cells are connected horizontally/vertically (not diagonally).
            grid is rectangular, with its width and height not exceeding 100
    Return: integer indicating the erimeter of the island
    """
    count = 0
    if grid is None or len(grid) == 0 or len(grid[0]) == 0:
        return count
    cols = len(grid[0])
    rows = len(grid)
    for r in range(rows):
        for c in range(cols):
            if r == 0 and grid[r][c] == 1:
                count += 1
            if c == 0 and grid[r][c] == 1:
                count += 1
            if r == rows - 1 and grid[r][c] == 1:
                count += 1
            if c == cols - 1 and grid[r][c] == 1:
                count += 1
            if r != 0 and grid[r][c] == 1 and grid[r - 1] == 0:
                count += 1
            if r != rows - 1 and grid[r][c] == 1 and grid[r + 1][c] == 0:
                count += 1
            if c != 0 and grid[r][c] == 1 and grid[r][c - 1] == 0:
                count += 1
            if c != cols - 1 and grid[r][c] == 1 and grid[r][c + 1] == 0:
                count += 1
            print(count)
            if c == 100:
                break
        if r == 100:
            break
    return count
