#compute all permutations of a string.
import time

def permutation(string):
    if len(string) == 1:
        return [string]
    ret = []
    for i in range(len(string)):
        if i != len(string)-1:
            ret2 = permutation(string[0:i] + string[(i+1):])
        else:
            ret2 = permutation(string[0:i])

        for ii in range(len(ret2)):
            ret2[ii] += string[i]
        ret += ret2

    return ret

def permutationFast(string):
    if len(string) == 1:
        return [string]

    ret = []

    head = string[0]
    ret2 = permutationFast(string[1:])
    
    for perm in ret2:
        for i in range(len(perm)):
            ret.append(perm[0:i] + head + perm[i:])
        ret.append(perm+head)

    return ret

if __name__ == "__main__":
    test_string = 'abcdefgh'
    start = time.time()
    permutation(test_string)
    print time.time() - start

    start = time.time()
    permutationFast(test_string)
    print time.time() - start
