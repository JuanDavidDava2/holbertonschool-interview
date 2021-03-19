#!/usr/bin/python3
import sys


def queens(n):
    paths = []
    data_set = set()
    for column in range(n):
        paths.append([0, column])
        data_set.add(column)

    track = []

    while paths:
        [row, column] = paths.pop(0)
        while track and (row < track[0][0]):
            track.pop(0)
        if track and (row == track[0][0]):
            track[0] = [row, column]
        else:
            track.insert(0, [row, column])

        nextRow = row + 1

        data_death_zone = set()
        for (r, c) in track:
            data_death_zone.add(c)
            distance = nextRow - r
            if c - distance >= 0:
                data_death_zone.add(c - distance)
            if c + distance < n:
                data_death_zone.add(c + distance)

        localSafeZone = data_set.difference(data_death_zone)
        if not localSafeZone:
            if nextRow == n:
                copy = track.copy()
                copy.reverse()
                print(copy, flush=True)
            track.pop(0)
        else:
            localSafeZone = list(localSafeZone)
            localSafeZone.reverse()
            for position in localSafeZone:
                paths.insert(0, [nextRow, position])


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    elif int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)
    try:
        n = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)
    queens(n)
