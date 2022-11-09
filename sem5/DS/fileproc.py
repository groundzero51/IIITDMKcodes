import pickle

def readfile():
    file = open("input.dat", "rb")
    while(1):
        try:
            x = pickle.load(file)
            print(x)
        except EOFError:
            print("End of the file")
            break

def writefile():
    file = open("input.dat", "wb")
    i = 0
    n = int(input("\nEnter number of books you would like to add : "))
    for i in range(0,n):
        book = []
        ISSN = int(input("Enter the issue number :"))
        book.append(ISSN)
        title = input("Enter the title of the book :")
        book.append(title)
        price = int(input("Enter the price of the book :"))
        book.append(price)
        edition = int(input("Enter the book edition :"))
        book.append(edition)
        year = int(input("Enter the year it should be published :"))
        book.append(year)
        author_name = input("Enter the author's name :")
        book.append(author_name)
        pickle.dump(book,file)
        print(book)
        
        
    file.close()

while 1:
    ch = int(input("1. write \n2. read\n3. search\n4. exit\nEnter your choice : "))
    if ch == 1:
        writefile()    
    elif ch == 2:
        readfile()
    elif ch == 3:
        word = input("\nEnter the book you want to search for : ")
        file  = open("input.dat","rb")
        books = pickle.load(file)
        if word in books:
            print("book is found in the library")
        else:
            print("book not found in the librayr")
    elif ch == 4:
        print("Code Exited")
        quit(1)
    
