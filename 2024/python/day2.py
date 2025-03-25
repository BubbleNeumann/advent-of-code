import copy


def part1():
	ans = 0
	with open(r'..\input\day2.txt') as f:
		while line := f.readline():
			arr = line.split(' ')
			i = 1
			inc = (int(arr[1]) - int(arr[0])) > 0
			while i < len(arr):
				diff = int(arr[i]) - int(arr[i-1])
				if diff and (diff > 0) == inc and (-4 < diff < 4):
					i += 1
					continue
				break
			else:
				ans += 1
	print(ans)

def part2():
	ans = 0
	with open(r'..\input\day2.txt') as f:
		while line := f.readline():
			arr = line.split(' ')
			for i_to_remove in range(len(arr)):
				local_arr = copy.copy(arr)
				del local_arr[i_to_remove]
				i = 1
				inc = (int(local_arr[1]) - int(local_arr[0])) > 0
				while i < len(local_arr):
					diff = int(local_arr[i]) - int(local_arr[i - 1])
					if diff and (diff > 0) == inc and (-4 < diff < 4):
						i += 1
						continue
					break
				else:
					ans += 1
					break
	print(ans)


if __name__ == '__main__':
	part2()