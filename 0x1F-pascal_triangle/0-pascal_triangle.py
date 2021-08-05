#!/usr/bin/python3
"""
Create a function def pascal_triangle(n):
"""


def pascal_triangle(n):
    """
    Create a function def pascal_triangle(n):
    """
    t = [[1]]
    for _ in range(n - 1):
        t += [[1] + [t[-1][i] + t[-1][i + 1]
                          for i in range(len(t[-1]) - 1)] + [1]]
    return t if n > 0 else []