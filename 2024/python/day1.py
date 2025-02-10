def read_file(filename: str):
	left = []
	right = []
	with open(filename) as f:
		while line := f.readline():
			l, r = line.split('   ')
			left.append(int(l))
			right.append(int(r))
	return left, right


def part1():
	left, right = read_file('..\\input\\day1.txt')
	res = sum(abs(l - r) for l, r in zip(sorted(left), sorted(right)))
	print(f'part 1: {res}')


def part2():
	left, right = read_file('..\\input\\day1.txt')
	res = sum(abs(l) * right.count(l) for l, r in zip(sorted(left), sorted(right)))
	print(res)


part2()

