# A magic index in an array A is defined to be an index such that index == content.
# Given a sorted array of integers, write a method to find a magic index

test_data = [-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13]

def magicFast(test_data, start, end):
    if start > end or start < 0 or end > len(test_data):
        return -1 # no magic index found

    mid = (start + end) / 2

    if mid == test_data[mid]:
        return mid
    
    leftIndex = min(mid-1, test_data[mid])
    left = magicFast(test_data, start, leftIndex)
    if (left >= 0): # valid answer
        return left

    # continue searching in right
    rightIndex = max(mid+1, test_data[mid])
    return magicFast(test_data, rightIndex, end)


if __name__ == "__main__":
    print magicFast(test_data, 0, len(test_data)-1)

