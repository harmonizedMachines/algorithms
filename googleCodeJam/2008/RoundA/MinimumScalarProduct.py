N = int(input())
for i in range(N):
    a = int(input())
    arr1 = [int(j) for j in input().split()]
    arr2 = [int(j) for j in input().split()]
    arr1.sort()
    arr2.sort(reverse=True)
    s = sum(arr1[j] * arr2[j] for j in range(a))
    print(f"Case #{i+1}: {s}")