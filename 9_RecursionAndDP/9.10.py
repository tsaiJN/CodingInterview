from numpy import inf

class Box:

    def __init__(self, width, height, depth):
        
        self.width = width
        self.height = height
        self.depth = depth

    def __repr__(self):
        return "[" + str(self.height) + "]"

    def canBeAbove(self, anotherBox):
        
        if (anotherBox.width > self.width and 
            anotherBox.height > self.height and 
            anotherBox.depth > self.depth):
            return True
        return False

    @staticmethod
    def getStackHeight(boxes):
        
        ret = 0
        for box in boxes:
            ret += box.height

        return ret


# Recursive Solution
def createStackR(boxes, bottom):

    maxHeight = 0
    maxStack = []

    for box in boxes:
        if box.canBeAbove(bottom):
            newStack =  createStackR(boxes, box) # use box as bottom
            newHeight = Box.getStackHeight(newStack)

            if newHeight > maxHeight:
                maxStack = newStack
                maxHeight = newHeight
    
    maxStack.insert(0, bottom)
    return maxStack

# In fact, since canBeAbove ensure strictly increase height, the state above bottom
# is simply defined by bottom (we know what above will look like as long as we see the bottom)
# Therefore, cache the result using DP (use bottom as key)
def createStackDP(boxes, bottom, cache):

    if bottom in cache:
        print "[cache hit]"
        return cache[bottom]

    maxHeight = 0
    maxStack = []

    for box in boxes:
        if box.canBeAbove(bottom):
            newStack = createStackDP(boxes, box, cache)
            newHeight = Box.getStackHeight(newStack)
            
            if newHeight > maxHeight:
                maxStack = newStack
                maxHeight = newHeight

    maxStack.insert(0, bottom)
    cache[bottom] = maxStack
    return maxStack


def makeTestData():

    boxes = [Box(i, i, i) for i in range(10, 1, -1)]
    boxes.reverse()
    return boxes


if __name__ == '__main__':
    
    boxes = makeTestData()
    print boxes
    
    maxStack = createStackDP(boxes, Box(inf, inf, inf), dict())  # use a infinitely large box to ground the case
    del maxStack[0]                                                    # delete that infinitely large box

    print maxStack
