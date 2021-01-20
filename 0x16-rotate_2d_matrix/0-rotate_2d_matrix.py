#!/usr/bin/python3
"""
0x16. Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise.
    """
    m1 = [x[:] for x in matrix]
    for i, z in zip(reversed(range(len(matrix))), range(len(matrix))):
        for j in range(len(matrix)):
            new_int = m1[z][j]
            matrix[j][i] = new_int
