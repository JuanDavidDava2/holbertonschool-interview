#!/usr/bin/python3
"""
Given a pile of coins of different values
"""


def makeChange(coins, total):
    """
    determine the fewest number of coins needed
    to meet a given amount total
    """
    if total <= 0:
        return 0

    tmp = total + 1
    tmp_list = {0: 0}

    for i in range(1, total + 1):
        tmp_list[i] = tmp

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            tmp_list[i] = min(tmp_list[current] + 1, tmp_list[i])

    if tmp_list[total] == total + 1:
        return -1

    return tmp_list[total]
