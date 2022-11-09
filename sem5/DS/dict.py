students = dict()
while 1:
    ch = int(input("1. insert\n2. delete\n3. search\n4. exit\nEnter your choice : "))

    if ch == 1:
        
        n = int(input("Enter number of students you wanna insert :"))
        for i in range(n):
            roll = input("\nEnter roll num of student :")
            sname = input("Enter name of student :")
            cgpa = input("Enter cgpa of student :")
            phno = input("Enter phone num of student :")
            students[roll] = sname,cgpa,phno
        print("student details :")
        print(students)

    elif ch == 2:
        rolln = input("Enter roll num of student :")
        if rolln in students.keys():
            print("deleted : ",students[rolln])
            students.pop(rolln)
            print("Current dictionary : ",students)
        else :
            print("No student found")

    elif ch == 3:

        rolln = input("Enter roll num of student :")
        if rolln in students.keys():
            print(students[rolln])
        else :
            print("No student found")
        
    elif ch == 4:
        print("Code Exited")
        quit(1)



    