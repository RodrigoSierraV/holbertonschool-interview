#!/usr/bin/python3
""" Module to determine if a data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    bins = list(map(lambda x: "{:08b}".format(x), data))
    utf8 = True
    for i in range(len(bins)):
        if bins[i][0] == '0':
            continue
        elif bins[i][:3] == '110' and bins[i+1][:2] == '10':
            continue
        elif bins[i][:4] == '1110' and bins[i+1][:2] == '10'\
                and bins[i+2][:2] == '10':
            continue
        elif bins[i][:5] == '11110' and bins[i+1][:2] == '10' and\
                bins[i+2][:2] == '10' and bins[i+3][:2] == '10':
            continue
        elif bins[i][:2] == '10':
            continue
        else:
            utf8 = False

    return utf8
