# binary search tree is good at keeping relative ordering, as well as
# updating when we insert new elements.

class Node:
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left = None
        
        # keeping track of how many nodes are in the left sub-tree
        # to speed up getRank
        self.count = 0

class Tree:
    def __init__(self, root):
        # start with a root node
        self.root = root

    def insert(self, node):
        Tree._insertHelper(self.root, node)

    @staticmethod
    def _insertHelper(root, node):
        if node.value == root.value:
            root.count += 1

        elif node.value > root.value:
            # send to right
            if root.right == None:
                root.right = node 
            else:
                Tree._insertHelper(root.right, node)

        else:
            # send to left
            root.count += 1
            
            if root.left == None:
                root.left = node
            else:
                Tree._insertHelper(root.left, node)

    def getRank(self, target):
        return Tree._getRankHelper(self.root, target)

    @staticmethod
    def _getRankHelper(root, target):
        # search the tree
        if target == root.value:
            return root.count

        if target < root.value:
            # look to the left
            return Tree._getRankHelper(root.left, target)

        if target > root.value:
            # look to the right
            return Tree._getRankHelper(root.right, target) + root.count + 1

if __name__ == '__main__':

    root = Node(5)
    tree = Tree(root)

    tree.insert(Node(1))
    tree.insert(Node(4))
    tree.insert(Node(4))
    tree.insert(Node(5))
    tree.insert(Node(9))
    tree.insert(Node(7))
    tree.insert(Node(13))
    tree.insert(Node(3))

    print tree.getRank(1)
    print tree.getRank(3)
    print tree.getRank(4)
    print tree.getRank(5)
    print tree.getRank(7)
    print tree.getRank(9)
    print tree.getRank(13)
