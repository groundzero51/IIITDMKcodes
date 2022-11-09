set1 = set()
set2 = set()
flag1 = 0   #flag for first set
flag2 = 0   #flag for second set
while 1:
    ch = int(input("1. Create Empty Set \n2. Insert \n3. Delete \n4. Search \n5. Print \n6. Union \n7. Intersection \n8. Set Difference \n9. Symmetric Difference \n10. Exit \nEnter your choice : "))
    if ch == 1:
        if flag1 == 0:
            flag1 = 1
            print("Set is created.")
        elif flag2 == 0:
            flag2 = 1
            print("2nd set is created.")
        else:
            print("Two sets are already created")

    elif ch == 2:
        if flag1 == 0 and flag2 == 0:
            print("No set to insert in...")
        else:
            set_number = int(
                input("Enter the set you want to insert into(1/2) : "))
            if set_number == 1:
                if not flag1:
                    print("set 1 doesnt exist")
                else:
                    print("enter the element you want to insert: ")
                    element = input()
                    set1.add(element)
            elif set_number == 2:
                if not flag2:
                    print("set 2 doesnt exist")
                else:
                    print("enter the element you want to insert: ")
                    element = input()
                    set2.add(element)
            else:
                print("Invalid input, skill issue detected")
    elif ch == 3:
        set_number = int(
            input("Enter the set you want to delete the element from: "))
        if set_number == 1:
            if not flag1:
                print("set 1 doesnt exist")
            else:
                element = input("enter the element you want to delete: ")
                if element not in set1:
                    print("element not found")
                else:
                    set1.remove(element)
                    print("The given element: " +
                          element + " is removed from set1")
        elif set_number == 2:
            if not flag2:
                print("set 2 doesnt exist")
            else:
                print("enter the element you want to delete: ")
                element = input()
                if element not in set2:
                    print("element not found")
                else:
                    set2.remove(element)
                    print("The given element: " +
                          element + " is deleted from set2")
        else:
            print("Invalid input")

    elif ch == 4:
        set_number = int(input("Enter set you want to search the element from: "))
        if set_number == 1:
            if not flag1:
                print("Please Create Set1 and Try Again")
            else:
                print("Please Enter the element you want to search: ")
                element = input()
                if element not in set1:
                    print("The given element: " + element + " doesn't exist in the set1")
                else:
                    print("The given element: " + element + " is there in set1")
        elif set_number == 2:
            if not flag2:
                print("Please Create Set2 and Try Again")
            else:
                print("Please Enter the element you want to search: ")
                element = input()
                if element not in set2:
                    print("The given element: " + element + " doesn't exist in the set2")
                else:
                    print("The given element: " + element + " is there in set2")
        else:
            print("Invalid Input")

    elif ch == 5:
        if flag1 and flag2:
            print("\nelements in set1 : ", set1)
            print("elements in set2 : ", set2)
        elif flag1 and not flag2:
            print("\nelements in set1 : ", set1)
        else:
            print("No set available to print")

    elif ch == 6:
        print("\nunion : ")
        set3 = set2.union(set1)
        print(set3)

    elif ch == 7:
        print("\nintersection : ")
        set3 = set2.intersection(set1)
        print(set3)

    elif ch == 8:
        print("\nset diff : ")
        set3 = set2.difference(set1)
        print(set3)

    elif ch == 9:
        print("\nsymmetric diff : ")
        set3 = set2.symmetric_difference(set1)
        print(set3)

    elif ch == 10:
        print("\nCode Exited")
        quit(1)
