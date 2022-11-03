from heapq import *

def addTime(time1, minutes):
    hour, min = time1.split(":")
    totalminutes = int(hour) * 60 + int(min) + minutes
    hour, min = totalminutes // 60, totalminutes % 60
    return f"{hour:02}:{min:02}"

N = int(input())
for i in range(N):
    ans = [0, 0]
    T = int(input())
    NA, NB = [int(j) for j in input().split()]
    trips = []
    for j in range(NA):
        trips.append(input().split() + [0])
    for j in range(NB):
        trips.append(input().split() + [1])
    trips.sort()
    trains = [[], []]
    for trip in trips:
        d = trip[2]
        if trains[d] and trains[d][0] <= trip[0]:
            heappop(trains[d])
        else:
            ans[d] += 1
        heappush(trains[1-d], addTime(trip[1], T))
    print(f"Case #{i+1}: {ans[0]} {ans[1]}")