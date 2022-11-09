n = int(input("Enter the number of elements in array : "))
arr = []
print("enter elements for the array : ")
for i in range(0, n):
    n = int(input())
    arr.append(n)
arr.sort()
print("sorted array : ", arr)
x = int(input("Enter the element you want to search for : "))
end = n-1
result = 0
start = 0
if x > arr[n-1] or x < arr[0]:
    print("The element doesnt exist in the array")
    quit()
else:
    for i in range(0, n-1):
        mid = (end + start)//2
        if arr[mid] == x:
            result = mid+1
        elif arr[mid] > x:
            end = mid-1
        elif arr[mid] < x:
            start = mid+1


print("the element is found at %d" % result)
