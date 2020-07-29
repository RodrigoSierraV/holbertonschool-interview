#!/usr/bin/python3
""" Module for placing N non-attacking queens on an N×N chessboard"""
from sys import argv, exit


def is_attack(i, j, result):
    """ Checks if there is a queen in row or column """
    for k in range(N):
        if [i, k] in result or [k, j] in result:
            return True
    # checking diagonals
    for row in range(N):
        for col in range(N):
            if row + col == i + j or row - col == i - j:
                if [row, col] in result:
                    return True
    return False


def n_queen(N, row, col, result=[]):
    """ Recursive function to find solutions """
    while col < N:
        if not is_attack(row, col, result):
            result.append([row, col])
            if row == N - 1:
                print(result)
                result.pop()
            else:
                n_queen(N, row + 1, 0, result)
        col += 1
    if len(result) > 0:
        result.pop()
    return


args_len = len(argv)
if args_len != 2:
    print("Usage: nqueens N")
    exit(1)
if not argv[1].isdigit():
    print("N must be a number")
    exit(1)
N = int(argv[1])
if N < 4:
    print("N must be at least 4")
    exit(1)

n_queen(N, 0, 0)
