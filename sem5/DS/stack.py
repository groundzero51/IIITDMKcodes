class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
 
    def is_empty(self):
        if self.head == None:
            return True
        else:
            return False
 
    def push(self, data):
        if self.head == None:
            self.head=Node(data)
              
        else:
            newnode = Node(data)
            newnode.next = self.head
            self.head = newnode
 
    def pop(self):
        poppednode = self.head
        self.head = self.head.next
        poppednode.next = None
        return poppednode.data

    def peek(self):
        return self.head.data

    def print(self):
        iternode = self.head
        if self.is_empty():
            print("Stack Underflow")
          
        else:   
            while(iternode != None):  
                print(iternode.data," ")
                iternode = iternode.next
            return
 
 
s = Stack()
count = 0
i = 0
while True:
    print("1. push")
    print("2. pop")
    print("3. peek")
    print("4. print")
    print("5. exit")
    choice = int(input("Enter your choice : "))
 
    if choice == 1:
        n = int(input(print("enter the integer you want to insert : ")))
        s.push(int(n))
        count +=1

    elif choice == 2:
        if s.is_empty():
            print("Stack is empty.")
        else:
            count -= 1
            print("Popped value: ", s.pop())

    elif choice == 3:
        if s.is_empty():
            print("Stack is empty.")
        else:
            print("Front value: ", s.peek())

    elif choice == 4:
        if s.is_empty():
            print("Stack is empty.")
        else:
            print("Stack from front to back : ")
            print(s.print())

    elif choice == 5:
        quit(1)