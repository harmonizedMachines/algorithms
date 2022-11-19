import math

def circularSegment(rad, th):
    return rad * rad * (th - math.sin(th)) / 2

def wrapper(f, R, t, r, g):
    x1, y1 = r + f, r + f
    x2 = x1 + g - 2 * f
    y2 = y1 + g - 2 * f
    return intersection(x1, y1, x2, y2)

def intersection(x1, y1, x2, y2):
    if x1 * x1 + y1 * y1 > 1:
        return 0
    if x2 * x2 + y2 * y2 < 1:
        return (x2 - x1) * (y2 - y1)
    if (x2 - x1) * (y2 - y1) < 1e-6 * 1e-6:
        return (x2 - x1) * (y2 - y1) / 2
    mx = (x1 + x2) / 2
    my = (y1 + y2) / 2
    return intersection(x1, y1, mx, my) + intersection(mx, y1, x2, my) + intersection(x1, my, mx, y2) + intersection(mx, my, x2, y2)

def getArea(f, R, t, r, g):
    rad = R - t - f
    area = 0
    x1, y1 = r + f - g - 2 * r, r + f - g - 2 * r
    while x1 < rad:
        while y1 < rad:
            x1 += g + 2 * r
            y1 += g + 2 * r
            x2 = x1 + g - 2 * f
            y2 = y1 + g - 2 * f
            # if no gap
            if x2 <= x1 or y2 <= y1:
                continue
            # range of the rectangle outside the circle
            if x1 * x1 + y1 * y1 >= rad * rad:
                continue
            # fully inside the circle
            if x2 * x2 + y2 * y2 <= rad * rad:
                area += (x2 - x1) * (y2 - y1)
            # only one corner inside the circle
            elif x1 * x1 + y2 * y2 >= rad * rad and x2 * x2 + y1 * y1 >= rad * rad:
                area += circularSegment(rad, math.acos(x1 / rad) - math.asin(y1 / rad)) + (math.sqrt(rad * rad - x1 * x1) - y1) * (math.sqrt(rad * rad - y1 * y1) - x1) / 2
            # only two corners inside the circle
            elif x1 * x1 + y2 * y2 >= rad * rad:
                area += circularSegment(rad, math.acos(x1 / rad) - math.acos(x2 / rad)) + (x2 - x1) * (math.sqrt(rad * rad - x1 * x1) - y1 + math.sqrt(rad * rad - x2 * x2) - y1) / 2
            # another case of two corners inside the circle
            elif x2 * x2 + y1 * y1 >= rad * rad:
                area += circularSegment(rad, math.asin(y2 / rad) - math.asin(y1 / rad)) + (y2 - y1) * (math.sqrt(rad * rad - y1 * y1) - x1 + math.sqrt(rad * rad - y2 * y2) - x1) / 2
            # 3 corners inside the circle
            else:
                area += circularSegment(rad, math.asin(y2/ rad) - math.acos(x2 / rad)) + (x2 - x1) * (y2 - y1) - (y2 - math.sqrt(rad * rad - x2 * x2)) * (x2 - math.sqrt(rad * rad - y2 * y2)) / 2
    return 1.0 - area / math.pi / R / R * 4

N = int(input())
for i in range(N):
    f, R, t, r, g = [float(j) for j in input().split()]
    prob = getArea(f, R, t, r, g)
    # prob = wrapper(f, R, t, r, g)
    print(f"Case #{i+1}: {prob:.6f}")