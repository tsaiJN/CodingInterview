face_map = {0: 25, 1: 10, 2: 5, 3: 1}

def sub_possible_ways(target, face):
    if target < 0:
        return 0
    if target == 0:
        return 1

    if face == 3:
        return 1

    base = face_map[face]
    total_ways = 0
    
    total_ways += sub_possible_ways(target, face+1)
    while target >= base:
        target -= base
        total_ways += sub_possible_ways(target, face+1)

    return total_ways

if __name__ == '__main__':
    print sub_possible_ways(1000, 0)
