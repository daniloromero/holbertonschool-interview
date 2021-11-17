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
    rows = len(grid)
    cols = len(grid[0])

    count = 0
    for r in range(1, rows):
        for c in range(1, cols):
            if grid[r][c] == 1:
                if grid[r - 1][c] == 0:
                    count += 1
                if grid[r + 1][c] == 0:
                    count += 1
                if grid[r][c - 1] == 0:
                    count += 1
                if grid[r][c + 1] == 0:
                    count += 1
    return count
