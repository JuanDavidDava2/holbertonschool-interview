#!/usr/bin/python3
'''a method that determines if a given data set represents'''


def validUTF8(data):
        '''Check UTF-8'''
        if not data:
            return False
        byte = 0
        for i in data:
            if byte > 0:
                if (i & 192) == 128:
                    byte -= 1
                else:
                    return False
            elif (i & 192) == 128:
                return False
            elif (i & 224) == 192:
                byte += 1
            elif (i & 240) == 224:
                byte += 2
            elif (i & 248) == 240:
                byte += 3
            elif (i > 248):
                return False
        return byte == 0
