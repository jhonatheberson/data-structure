"""The median of a set of integers is the midpoint value of the data set for which an equal number of integers are less than and greater than the value. To find the median, you must first sort your set of integers in non-decreasing order, then:

If your set contains an odd number of elements, the median is the middle element of the sorted sample. In the sorted set ,  is the median.
If your set contains an even number of elements, the median is the average of the two middle elements of the sorted sample. In the sorted set ,  is the median.
Given an input stream of  integers, perform the following task for each  integer:

Add the  integer to a running list of integers.
Find the median of the updated list (i.e., for the first element through the  element).
Print the updated median on a new line. The printed value must be a double-precision number scaled to  decimal place (i.e.,  format).
Example

Sorted          Median
[7]             7.0
[3, 7]          5.0
[3, 5, 7]       5.0
[2, 3, 5, 7]    4.0
Each of the median values is stored in an array and the array is returned for the main function to print.

Note: Add formatting to the print statement.

Function Description
Complete the runningMedian function in the editor below.

runningMedian has the following parameters:
- int a[n]: an array of integers

Returns
- float[n]: the median of the array after each insertion, modify the print statement in main to get proper formatting.

Input Format

The first line contains a single integer, , the number of integers in the data stream.
Each line  of the  subsequent lines contains an integer, , to be inserted into the list.

Constraints

Sample Input

STDIN   Function
-----   --------
6       a[] size n = 6
12      a = [12, 4, 5, 3, 8, 7]
4
5
3
8
7

Sample Output

12.0
8.0
5.0
4.5
5.0
6.0

Explanation

There are  integers, so we must print the new median on a new line as each integer is added to the list:


  """

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'runningMedian' function below.
#
# The function is expected to return a DOUBLE_ARRAY.
# The function accepts INTEGER_ARRAY a as parameter.
#

#def merge(A, aux, esquerda, meio, direita):
#    """
#    Combina dois vetores ordenados em um unico vetor (tambem ordenado).
#    """
#    for k in range(esquerda, direita + 1):
#        aux[k] = A[k]
#    i = esquerda
#    j = meio + 1
#    for k in range(esquerda, direita + 1):
#        if i > meio:
#            A[k] = aux[j]
#            j += 1
#        elif j > direita:
#            A[k] = aux[i]
#            i += 1
#        elif aux[j] < aux[i]:
#            A[k] = aux[j]
#            j += 1
#        else:
#            A[k] = aux[i]
#            i += 1

 #O(nlogn)
#def mergesort(A, aux, esquerda, direita):
#    if direita <= esquerda:
#        return
#    meio = (esquerda + direita) // 2

    # Ordena a primeira metade do arranjo.
#    mergesort(A, aux, esquerda, meio)

    # Ordena a segunda metade do arranjo.
#    mergesort(A, aux, meio + 1, direita)

    # Combina as duas metades ordenadas anteriormente.
#    merge(A, aux, esquerda, meio, direita)

#def runningMedian(a):
    # Write your code here
#    queue = []
#    result = []
#    for inter in a:
#        queue.append(inter)
#        aux = [0] * len(queue)
#        mergesort(queue, aux, 0, len(queue) - 1)
#        meio = (0 + (len(queue) - 1)) // 2
#        if(len(queue)%2 == 0): # par
#            result.append(((queue[meio]+queue[meio+1])/2))
#        else:
#            result.append(queue[meio])
#    return result

def runningMedian(a):
    # Declaring two min heap
    # import at the top
    from heapq import heappush, heappop, heapify

    g = []
    s = []
    result = []
    for i in range(len(a)):

        # Negation for treating it as max heap
        heappush(s, -a[i])
        heappush(g, -heappop(s))
        if len(g) > len(s):
            heappush(s, -heappop(g))

        if len(g) != len(s): # é impar
            result.append(float(-s[0]))
        else:#é par
            result.append(float((g[0] - s[0])/2))

    return result

if __name__ == '__main__':


    a_count = int(input().strip())

    a = []

    for _ in range(a_count):
        a_item = int(input().strip())
        a.append(a_item)

    result = runningMedian(a)

    print('\n'.join(map(str, result)))
    print('\n')
