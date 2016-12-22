# Given a sorted array of n integers that has been rotated an unknown number of times,
# write code to find an element in the array, you may assume that the array was originally
# sorted in increasing order.

def search(array, target, start, end):
    mid = (start + end) / 2
    
    if target == array[mid]:
        return mid
    if target == array[start]:
        return start
    if target == array[end]:
        return end

    if start >= end:
        return -1
    
    if array[end] < array[mid]:
        # left side is normally aranged
        if target < array[mid] and target > array[start]:
            return search(array, target, start+1, mid-1)
        else:
            return search(array, target, mid+1, end-1)

    elif array[start] > array[mid]:
        # right side is normally arranged
        if target > array[mid] and target < array[end]:
            return search(array, target, mid+1, end-1)
        else:
            return search(array, target, start+1, mid-1)

    else:
        # array[start] == array[mid] == array[end]
        return max(
                search(array, target, start+1, mid-1),
                search(array, target, mid+1, end-1)
        ) # both sides might be normally arranged

if __name__ == '__main__':
    test_set = [15, 16, 19, 1, 3, 4, 5, 7, 10, 12]
    test_set2 = [2, 2, 2, 3, 4, 2]
    
    print "test set #1"
    print test_set

    for i in test_set:
        print '{}: {}'.format(i, search(test_set, i, 0, len(test_set)-1))

    print "test set #2"
    print test_set2

    for i in test_set2:
        print '{}: {}'.format(i, search(test_set2, i, 0, len(test_set2)-1))
