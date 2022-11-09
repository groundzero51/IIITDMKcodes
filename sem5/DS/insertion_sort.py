n = int(input("Enter the number of elements in array : "))#input for number of elements is taken
arr = []
print("enter elements for the array : ")
for i in range(0, n):#for loop to take input for elements of the array
    n = int(input())
    arr.append(n)

for i in range(0, n):

    key = arr[i]

    j = i-1
    while j >= 0 and key < arr[j]:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = key

print("sorted array : ", arr)
