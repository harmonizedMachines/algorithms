inputs = """Monkey 0:
  Starting items: 76, 88, 96, 97, 58, 61, 67
  Operation: new = old * 19
  Test: divisible by 3
    If true: throw to monkey 2
    If false: throw to monkey 3

Monkey 1:
  Starting items: 93, 71, 79, 83, 69, 70, 94, 98
  Operation: new = old + 8
  Test: divisible by 11
    If true: throw to monkey 5
    If false: throw to monkey 6

Monkey 2:
  Starting items: 50, 74, 67, 92, 61, 76
  Operation: new = old * 13
  Test: divisible by 19
    If true: throw to monkey 3
    If false: throw to monkey 1

Monkey 3:
  Starting items: 76, 92
  Operation: new = old + 6
  Test: divisible by 5
    If true: throw to monkey 1
    If false: throw to monkey 6

Monkey 4:
  Starting items: 74, 94, 55, 87, 62
  Operation: new = old + 5
  Test: divisible by 2
    If true: throw to monkey 2
    If false: throw to monkey 0

Monkey 5:
  Starting items: 59, 62, 53, 62
  Operation: new = old * old
  Test: divisible by 7
    If true: throw to monkey 4
    If false: throw to monkey 7

Monkey 6:
  Starting items: 62
  Operation: new = old + 2
  Test: divisible by 17
    If true: throw to monkey 5
    If false: throw to monkey 7

Monkey 7:
  Starting items: 85, 54, 53
  Operation: new = old + 3
  Test: divisible by 13
    If true: throw to monkey 4
    If false: throw to monkey 0"""

inputs = """Monkey 0:
  Starting items: 79, 98
  Operation: new = old * 19
  Test: divisible by 23
    If true: throw to monkey 2
    If false: throw to monkey 3

Monkey 1:
  Starting items: 54, 65, 75, 74
  Operation: new = old + 6
  Test: divisible by 19
    If true: throw to monkey 2
    If false: throw to monkey 0

Monkey 2:
  Starting items: 79, 60, 97
  Operation: new = old * old
  Test: divisible by 13
    If true: throw to monkey 1
    If false: throw to monkey 3

Monkey 3:
  Starting items: 74
  Operation: new = old + 3
  Test: divisible by 17
    If true: throw to monkey 0
    If false: throw to monkey 1"""

inputs = inputs.split("\n\n")
monkeys = []
for part in inputs:
    part = part.split('\n')
    startitems = [int(i) for i in part[1].split(": ")[-1].split(",")]
    monkeys.append([startitems, part[2].split("old ")[-1], int(part[3].split(" ")[-1]), int(part[4].split(" ")[-1]), int(part[5].split(" ")[-1]), 0])

for i in range(20):
    for monkey in monkeys:
        copy = monkey[0].copy()
        monkey[0] = []
        for item in copy:
            if monkey[1] == '* old':
                worry = item * item // 3
            elif monkey[1][0] == "*":
                worry = item * int(monkey[1].split(" ")[-1]) // 3
            else:
                worry = (item + int(monkey[1].split(" ")[-1])) // 3
            if worry % monkey[2] == 0:
                monkeys[monkey[3]][0].append(worry)
            else:
                monkeys[monkey[4]][0].append(worry)
            monkey[-1] += 1

print([monkey[-1] for monkey in monkeys])
import tqdm

for i in tqdm.tqdm(range(10000)):
    for monkey in monkeys:
        copy = monkey[0].copy()
        monkey[0] = []
        for item in copy:
            if monkey[1] == '* old':
                worry = item * item
            elif monkey[1][0] == "*":
                worry = item * int(monkey[1].split(" ")[-1])
            else:
                worry = (item + int(monkey[1].split(" ")[-1]))
            if worry % monkey[2] == 0:
                monkeys[monkey[3]][0].append(worry)
            else:
                monkeys[monkey[4]][0].append(worry)
            monkey[-1] += 1

print([monkey[-1] for monkey in monkeys])