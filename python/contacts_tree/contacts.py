# We're going to make our own Contacts application! The application must perform two types of operations:

# add name, where  is a string denoting a contact name. This must store  as a new contact in the application.
# find partial, where  is a string denoting a partial name to search the application for. It must count the number of contacts starting with  and print the count on a new line.
# Given  sequential add and find operations, perform each operation in order.

# Example
# Operations are requested as follows:

# add ed
# add eddie
# add edward
# find ed
# add edwina
# find edw
# find a
# Three  operations include the names 'ed', 'eddie', and 'edward'. Next,  matches all  names. Note that it matches and counts the entire name 'ed'. Next, add 'edwina' and then find 'edw'.  names match: 'edward' and 'edwina'. In the final operation, there are  names that start with 'a'. Return the array .

# Function Description

# Complete the contacts function below.

# contacts has the following parameters:

# string queries[n]: the operations to perform
# Returns

# int[]: the results of each find operation
# Input Format

# The first line contains a single integer, , the number of operations to perform (the size of ).
# Each of the following  lines contains a string, .

# Constraints

#  and  contain lowercase English letters only.
# The input does not have any duplicate  for the  operation.
# Sample Input

# STDIN           Function
# -----           --------
# 4               queries[] size n = 4
# add hack        queries = ['add hack', 'add hackerrank', 'find hac', 'find hak']
# add hackerrank
# find hac
# find hak
# Sample Output

# 2
# 0
# Explanation

# Add a contact named hack.
# Add a contact named hackerrank.
# Find the number of contact names beginning with hac. Both name start with hac, add  to the return array.
# Find the number of contact names beginning with hak. neither name starts with hak, add  to the return array.

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
