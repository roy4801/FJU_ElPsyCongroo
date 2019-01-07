import random

LOW = 0
UPPER = 10000

def main():
	num = 1
	len_limit = 100
	ask_limit = 1000

	with open('BIT_test.in', 'w') as fp:
		fp.write(str(num)+'\n')

		for i in range(num):
			l = random.randint(1, len_limit+1)
			fp.write(str(l)+' ')
			for j in range(l):
				fp.write(str(random.randint(LOW, UPPER)))
				fp.write(' ')
			fp.write('\n')

			ask = random.randint(1, ask_limit)
			for j in range(ask):
				a, b = random.randint(1, l), random.randint(1, l)
				fp.write(str(min(a, b)) + ' ' + str(max(a, b)) + '\n')
			fp.write("0 0\n")


if __name__ == "__main__":
	main()