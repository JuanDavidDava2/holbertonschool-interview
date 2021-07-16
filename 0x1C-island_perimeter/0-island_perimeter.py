#!/usr/bin/python3
"""
returns the per of the island described in grid:
O(n) time O(1) space
"""


def island_perimeter(grid):
    """Looks up and left to subtract water"""
    per = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                per += 4
                if row and grid[row - 1][col] == 1:
                    per -= 2
                if col and grid[row][col - 1] == 1:
                    per -= 2
    return per
