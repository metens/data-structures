
class Node:
    def __init__(self, data = 0):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        self.root = self._insert(self.root, data)

    def _insert(self, root: Node, data: int) -> Node:
        if root is None:
            root = Node(data)
            return root
        elif data < root.data:
            root.left = self._insert(root.left, data)
        else: root.right = self._insert(root.right, data)
        return root

    def display(self):
        if self.root is not None:
            self._display(self.root)
        print()

    def _display(self, root: Node):
        if root is None:
            return
        self._display(root.left)
        print(root.data, end=" ")
        self._display(root.right)

def main():
    tree = BST()

    items = [5, 9, 3, 4, 1, 3, 2, 4, 8, 10]
    print("Inserting: ", end="")
    for data in items:
        tree.insert(data)
        print(data, end=" ")

    print("\nBST in order: ", end="")
    tree.display()

if __name__ == "__main__":
    main()
