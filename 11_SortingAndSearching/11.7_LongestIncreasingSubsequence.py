# We have a list of pairs of items. Find the longest sequence such that both the first and second
# items are in non-decreasing order.

# O(n^2), recursive approach
# recurrence:
#   length(n) = max (length(i) + 1: if s[i] < s[n]) for i in range(0, n)
#
#   length(n): the length of longest increasing subsequence that ends with nth element
#   s:         the array of elements
def LIS(test_set, n, cache):
    if n in cache:
        return cache[n]
    if n == 0:
        return 1

    max_len = 0
    for i in range(n):
        if test_set[i][1] < test_set[n][1]:
            max_len = max(max_len, LIS(test_set, i, cache)+1)

    cache[n] = max_len
    return cache[n]

if __name__ == '__main__':
    test_set = [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 55)]

    # sort by first item    
    # Built-in sort is implemented by Timsort which is a stable O(n log n) algorithm
    test_set.sort(key = lambda x: x[0]) 

    # finding longest increasing subsequence in the second items
    print LIS(test_set, len(test_set)-1, {})

    print test_set
