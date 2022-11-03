N = int(input())
for i in range(N):
    S = int(input())
    for j in range(S):
        input()
    ans = 0
    Q = int(input())
    searched = set()
    for j in range(Q):
        q = input()
        if q not in searched:
            if len(searched) == S - 1:
                searched = set()
                ans += 1
            searched.add(q)
    print(f"Case #{i+1}: {ans}")