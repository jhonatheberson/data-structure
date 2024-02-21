#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isBalanced' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isBalanced(s):
    # Write your code here
    stack = []
    # map right bracket (key) to left bracket (value)
    right = {'}':'{',')':'(',']':'['}
    left = ['(','{','[']
    for c in s:
        # push all left brackets to the stack
        if c in left:
            stack.append(c)
        else:
            if len(stack) > 0 and stack[-1] == right[c]:
                # matches
                stack.pop()
            else:
                # doesn't match
                return 'NO'
    # if anything is still on the stack
    if len(stack) > 0:
        return 'NO'
    # made it through all tests
    return 'YES'

if __name__ == '__main__':

    t = int(input().strip())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        print(result + '\n')
