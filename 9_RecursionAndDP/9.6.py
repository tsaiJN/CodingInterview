# Implement an algorithm to print all valid combinations of n-pairs of parentheses
# The solution exploit the fact that at each index of string, there must be either left or right paren
# When can we insert left paren:
#   if there are left paren quota remaining
# When can we insert right paren:
#   if there are more left paren used then right

all_combination = []

def insertParen(left_remain, right_remain, string):
    if left_remain < 0 or right_remain < 0:
        return

    if left_remain == 0 and right_remain == 0:
        all_combination.append(string)
        return
    
    # current index must be either left paren
    if left_remain > 0:
        insertParen(left_remain-1, right_remain, string+'(')

    # or right paren
    if right_remain > left_remain:
        insertParen(left_remain, right_remain-1, string+')')

    return

if __name__ == '__main__':
    insertParen(4, 4, '')
    print all_combination
