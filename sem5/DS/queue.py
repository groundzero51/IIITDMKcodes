class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.front = self.rear = None

    def is_empty(self):
        if self.front == None:
            return True
        else:
            return False

    def Enqueue(self, data):
        temp = Node(data)
        if self.rear == None:
            self.front = self.rear = temp
            return
        self.rear.next = temp
        self.rear = temp

    def Dequeue(self):
        temp = self.front
        self.front = temp.next

        if(self.front == None):
            self.rear = None

    def peek(self):
        return self.front.data

    def print(self):
        iternode = self.front

        while(iternode != None):
            print(iternode.data, " ")
            iternode = iternode.next
        return


s = Queue()

while True:
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. peek")
    print("4. print")
    print("5. exit")
    choice = int(input("Enter your choice : "))

    if choice == 1:
        n = int(input(print("enter the integer you want to insert : ")))
        s.Enqueue(int(n))
        
    elif choice == 2:
        if s.is_empty():
            print("Queue is empty.")
        else:
            
            print("Dequeued value: ", s.Dequeue())

    elif choice == 3:
        if s.is_empty():
            print("Queue is empty.")
        else:
            print("Front value: ", s.peek())

    elif choice == 4:
        if s.is_empty():
            print("Queue is empty.")
        else:
            print("Queue from front to rear : ")
            print(s.print())

    elif choice == 5:
        quit(1)
