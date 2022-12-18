inputs = """addx 1
addx 4
noop
noop
noop
addx 5
addx 3
noop
addx 2
noop
noop
noop
noop
addx 3
addx 5
addx 2
addx 1
noop
addx 5
addx -1
addx 5
noop
addx 3
noop
addx -40
noop
addx 38
addx -31
addx 3
noop
addx 2
addx -7
addx 8
addx 2
addx 5
addx 2
addx 3
addx -2
noop
noop
noop
addx 5
addx 2
noop
addx 3
addx 2
noop
addx 3
addx -36
noop
noop
addx 5
noop
noop
addx 8
addx -5
addx 5
addx 2
addx -15
addx 16
addx 4
noop
addx 1
noop
noop
addx 4
addx 5
addx -30
addx 35
addx -1
addx 2
addx -36
addx 5
noop
noop
addx -2
addx 5
addx 2
addx 3
noop
addx 2
noop
noop
addx 5
noop
addx 14
addx -13
addx 5
addx -14
addx 18
addx 3
addx 2
addx -2
addx 5
addx -40
noop
addx 32
addx -25
addx 3
noop
addx 2
addx 3
addx -2
addx 2
addx 2
noop
addx 3
addx 5
addx 2
addx 9
addx -36
addx 30
addx 5
addx 2
addx -25
addx 26
addx -38
addx 10
addx -3
noop
noop
addx 22
addx -16
addx -1
addx 5
addx 3
noop
addx 2
addx -20
addx 21
addx 3
addx 2
addx -24
addx 28
noop
addx 5
addx 3
noop
addx -24
noop"""

inputs = inputs.split('\n')
ans = 0
counter = 1
cycle = 1
target = {20, 60, 100, 140, 180, 220}
for line in inputs:
    if line.startswith("noop"):
        cycle += 1
    else:
        line = line.split(" ")
        cycle += 1
        if cycle in target:
            ans += cycle * counter
        cycle += 1
        counter += int(line[-1])
    if cycle in target:
        ans += cycle * counter
print(ans)

def draw(cycle, counter):
    row, col = (cycle - 1) // 40, (cycle - 1) % 240 % 40
    if len(crt) - 1 < row:
        crt.append(['.' for _ in range(40)])
    crt[row][col] = '#' if counter <= col + 1 and counter >= col - 1 else '.'

def test():
    return ["".join(i) for i in crt]

crt = [['.' for _ in range(40)] for _ in range(6)]
counter = 1
cycle = 1
draw(cycle, counter)
for line in inputs:
    if line.startswith("noop"):
        cycle += 1
        draw(cycle, counter)
    else:
        line = line.split(" ")
        cycle += 1
        draw(cycle, counter)
        cycle += 1
        counter += int(line[-1])
        draw(cycle, counter)
        
print("\n".join(test()))