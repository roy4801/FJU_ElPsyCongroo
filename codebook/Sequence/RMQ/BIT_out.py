from sys import *

def main():
	cases = int(input(''))
	for i in range(cases):
		arr = [int(x) for x in input('').split()]
		arr.pop(0)
		# print(len(arr))
		# input('')
		while True:
			inp = [int(x) for x in input('').split()]
			a, b = inp[0], inp[1]
			if a == 0 and b == 0:
				break

			a -= 1
			b -= 1
			# print('>> {} {}'.format(a, b))
			sum_num = 0
			for k in range(a, b+1):
				sum_num += arr[k]
			print(sum_num, flush=True)

if __name__ == '__main__':
	main()