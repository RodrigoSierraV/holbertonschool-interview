#!/usr/bin/python3
"""Minimum operations module"""


def minOperations(n):
    """Calculates minimum operations"""
    text = "H"
    operations = 0
    while len(text) < n:
        if operations == 0 or n % len(text) == 0:
            copy_all = text
            operations += 1
        text += copy_all
        operations += 1
    return operations
