#!/usr/bin/python3
"""stats module
"""
from sys import stdin


codes = {'200': 0, '301': 0, '400': 0, '401': 0,
        '403': 0, '404': 0, '405': 0, '500': 0}
size = 0


def print_info():
    """ Args:
        codes: code status
        size: size of files
    """
    print("File size: {}".format(size))
    for key, val in sorted(codes.items()):
        if val > 0:
            print("{}: {}".format(key, val))

if __name__ == '__main__':
    try:
        for i, line in enumerate(stdin, 1):
            try:
                info = line.split()
                size += int(info[-1])
                if info[-2] in codes.keys():
                    codes[info[-2]] += 1
            except:
                pass
            if not i % 10:
                print_info()
    except KeyboardInterrupt:
        print_info()
        raise
    print_info()