
class Node:
    def __init__(self, data = 0):
        self.data = data
        self.next = None

class Linked_List:
    def __init__(self):
        self.head = None

    def insert(self, data: int) -> None:
        self.head = self._insert(data, self.head)

    def _insert(self, data: int, head: Node) -> Node:
        if head is None:
            head = Node(data)
        else:
            head.next = self._insert(data, head.next)
        return head

    def display(self) -> None:
        if self.head is None:
            return
        curr = self.head

        while curr:
            print(curr.data, end=" ")
            curr = curr.next
        print()

def main():
    my_list = Linked_List()

    data_values = [1, 2, 3, 4, 5, 6]
    for data in data_values:
        my_list.insert(data)

    my_list.display()

if __name__=="__main__":
    main()
