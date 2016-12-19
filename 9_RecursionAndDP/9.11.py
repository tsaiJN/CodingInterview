# Given a boolean expression consisting of the symbols 0, 1, &, | and ^, and a desired boolean result
# implement a function to count the number of ways of parenthesizing the expression such that it eval. to result

# exploit the truth table

# if we want result to be true:

#   f(exp1 | exp2, true) = f(exp1, true) * f(exp2, true) +
#                          f(exp1, true) * f(exp2, false) +
#                          f(exp1, false) + f(exp2, true)

#   f(exp1 ^ exp2, true) = f(exp1, true) * f(exp2, false) +
#                          f(exp1, false) + f(exp2, true)

#   f(exp1 & exp2, true) = f(epx1, true) * f(exp2, true)

# if we want result to be false:

#   f(exp1 | exp2, false) = f(exp1, false) * f(exp2, false)

#   f(exp1 ^ exp2, false) = f(exp1, true) * f(exp2, true) +
#                           f(exp1, false) * f(exp2, false)

#   f(exp1 & exp2, false) = f(exp1, true) * f(exp2, false) +
#                           f(exp1, false) * f(exp2, true) +
#                           f(exp1, false) * f(exp2, false)

# return the count of possible parenthesizing
#   exp: str
#   result: boolean
#   start: int
#   end: int
#   @return: int
def f(exp, result, start, end): # use start and end to cut expression
    
    # base case
    if start == end:
      if (exp[start] == "1" and result) or (exp[start] == "0" and (not result)):
          return 1
      return 0
    
    count = 0

    # desired result is truth
    if result:
        for i in range(start+1, end, 2):  # only obtain operator
            op = exp[i]
            if op == '|':
                count += f(exp, True, start, i-1) * f(exp, True, i+1, end)
                count += f(exp, True, start, i-1) * f(exp, False, i+1, end)
                count += f(exp, False, start, i-1) * f(exp, True, i+1, end)
            if op == '^':
                count += f(exp, True, start, i-1) * f(exp, False, i+1, end)
                count += f(exp, False, start, i-1) * f(exp, True, i+1, end)
            if op == '&':
                count += f(exp, True, start, i-1) * f(exp, True, i+1, end)

    # desired result is false
    else:
        for i in range(start+1, end, 2):
            op = exp[i]
            if op == '|':
                count += f(exp, False, start, i-1) * f(exp, False, i+1, end)
            if op == "^":
                count += f(exp, True, start, i-1) * f(exp, True, i+1, end)
                count += f(exp, False, start, i-1) * f(exp, False, i+1, end)
            if op == "&":
                count += f(exp, True, start, i-1) * f(exp, False, i+1, end)
                count += f(exp, False, start, i-1) * f(exp, True, i+1, end)
                count += f(exp, False, start, i-1) * f(exp, False, i+1, end)
    return count

cache = {}
def fDP(exp, result, start, end): # use start and end to cut expression
    
    global cache
    # (use start, end, result) tuple to cache sub_expression
    if (start, end, result) in cache:
        print "[cache hit]"
        return cache[(start, end, result)]

    # base case
    if start == end:
      if (exp[start] == "1" and result) or (exp[start] == "0" and (not result)):
          return 1
      return 0
    
    count = 0

    # desired result is truth
    if result:
        for i in range(start+1, end, 2):  # only obtain operator
            op = exp[i]
            if op == '|':
                count += fDP(exp, True, start, i-1) * fDP(exp, True, i+1, end)
                count += fDP(exp, True, start, i-1) * fDP(exp, False, i+1, end)
                count += fDP(exp, False, start, i-1) * fDP(exp, True, i+1, end)
            if op == '^':
                count += fDP(exp, True, start, i-1) * fDP(exp, False, i+1, end)
                count += fDP(exp, False, start, i-1) * fDP(exp, True, i+1, end)
            if op == '&':
                count += fDP(exp, True, start, i-1) * fDP(exp, True, i+1, end)

    # desired result is false
    else:
        for i in range(start+1, end, 2):
            op = exp[i]
            if op == '|':
                count += fDP(exp, False, start, i-1) * fDP(exp, False, i+1, end)
            if op == "^":
                count += fDP(exp, True, start, i-1) * fDP(exp, True, i+1, end)
                count += fDP(exp, False, start, i-1) * fDP(exp, False, i+1, end)
            if op == "&":
                count += fDP(exp, True, start, i-1) * fDP(exp, False, i+1, end)
                count += fDP(exp, False, start, i-1) * fDP(exp, True, i+1, end)
                count += fDP(exp, False, start, i-1) * fDP(exp, False, i+1, end)

    cache[(start, end, result)] = count
    return count

# Can further optimized with Catalan numbers, so simple

if __name__ == '__main__':
    
    test_str = '1^0|0|1'
    print f(test_str, False, 0, len(test_str)-1)
    print fDP(test_str, False, 0, len(test_str)-1)
