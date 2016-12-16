# be ware of the pass-by-object-pointer property of python
# I pass deepcopy(Map) for each function call to simulate pass-by-value
from __future__ import print_function
import copy

count = 1

def printMap(Map):
    global count
    print("solution #"+str(count))
    for i in range(8):
        for j in range(8):
            print (Map[i][j], end='')
        print ('\n')
    count += 1
    print ('\n\n')

# Instead of marking invalid points, we can actually check the validity
# of the point where we are about to place a queen. Time complexity would
# be the same but execution time should be optimized a little bit
def MarkInvalidPoints(Map, rowIdx, columnIdx):

    for i in range((columnIdx+1), 8):
        # right
        Map[rowIdx][i] = '*'

    for i in range(8):
        # upper right diagonal
        id1 = rowIdx - 1 - i
        id2 = columnIdx + 1 + i
        if (id1 >= 0 and id2 < 8):
            Map[id1][id2] = '*'

        # lower right diagonal
        id3 = rowIdx + 1 + i
        if (id3 < 8 and id2 < 8):
            Map[id3][id2] = '*'

    return Map


def eightQueen(Map, columnIdx):
    if columnIdx >= 8:
        printMap(Map)
        return

    # select each valid idx in this column
    flag = True
    for i in xrange(8):
        if Map[i][columnIdx] == '.':
            flag = False
            Map2 = copy.deepcopy(Map)
            Map2[i][columnIdx] = 'o'
            Map2 = MarkInvalidPoints(copy.deepcopy(Map2), i, columnIdx)
            eightQueen(copy.deepcopy(Map2), columnIdx+1)

    return

if __name__ == '__main__':
    row = ['.' for i in range (8)]
    Map = [copy.copy(row) for i in range(8)]

    eightQueen(Map, 0)

    # verified to be true by counting the total distinct solutions (which should be 92 solution)
