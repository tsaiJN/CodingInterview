# each round we can remove 1/4 of total possible position
# time complexity would be O(log MN) [using 4/3 as base]
def BinarySearch2D(matrix, target, startx, endx, starty, endy):
    midx = (startx + endx) / 2
    midy = (starty + endy) / 2

    if startx > endx or starty > endy:
        return (-1, -1)
    
    current_value = matrix[midx][midy]

    if target == current_value:
        return (midx, midy)

    if target > current_value:
        # not in upper left block
        ret = [
                BinarySearch2D(matrix, target, midx+1, endx, midy+1, endy),
                BinarySearch2D(matrix, target, midx+1, endx, starty, midy),
                BinarySearch2D(matrix, target, startx, midx, midy+1, endy)
              ]
    else:
        # not in lower right block
        ret = [
                BinarySearch2D(matrix, target, startx, midx-1, starty, midy-1),
                BinarySearch2D(matrix, target, midx, endx, starty, midy-1),
                BinarySearch2D(matrix, target, startx, midx-1, midy, endy)
              ]

    for pair in ret:
        if pair != (-1, -1):
            return pair

    return (-1, -1)

if __name__ == '__main__':
    matrix = [
            [15, 20, 40, 85],
            [20, 35, 80, 95],
            [30, 55, 95, 105],
            [40, 80, 100, 120]
            ]

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            ret = BinarySearch2D(matrix, matrix[i][j], 0, len(matrix)-1, 0, len(matrix[0])-1)
            print '{}: {}'.format(matrix[i][j], ret)
