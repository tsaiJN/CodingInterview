# the solution is O(2^n), which is the best we can do since we need to return the whole list
def PowerSetRecursive(raw_set):
    if len(raw_set) == 0:
        return [[]]

    # take one out
    tmp = raw_set[-1]
    
    ret = PowerSetRecursive(raw_set[0:-1])
    ret2 = []
    
    for sset in ret:
        ret2.append(sset+tmp)

    return ret2 + ret



if __name__ == '__main__':
    print PowerSetRecursive([[1],[2],[3]])
