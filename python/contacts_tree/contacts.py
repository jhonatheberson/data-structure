#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'contacts' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts 2D_STRING_ARRAY queries as parameter.
#

class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0

def add_contact(root, contact):
    node = root
    for char in contact:
        node = node.children.setdefault(char,TrieNode())
        node.count += 1

def find_contacts(root, partial):
    node = root
    for char in partial:
        if char not in node.children:
            return 0
        node = node.children[char]
    return node.count

def contacts(queries):
    root = TrieNode()
    res = []
    for opertaion,content in queries:
        if opertaion == "add":
            add_contact(root,content)
        elif opertaion == "find":
            count = find_contacts(root,content)
            res.append(count)
    return res

if __name__ == '__main__':


    queries_rows = int(input().strip())

    queries = []

    for _ in range(queries_rows):
        queries.append(input().rstrip().split())

    result = contacts(queries)

    print('\n'.join(map(str, result)))
    print('\n')
