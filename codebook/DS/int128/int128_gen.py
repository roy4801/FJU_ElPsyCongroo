'''
Testdata generate for int128.cpp
Author: roy4801
Team: FJU_ElPsyCongroo
'''

import random

def main():
	dataForIn = open('int128.in', 'w')
	dataForOut = open('int128_cor.out', 'w')

	num_data = 1000
	upperB = 2 ** 100
	lowerB = -2 ** 100

	for i in range(num_data):
		a, b = random.randint(lowerB, upperB), random.randint(lowerB, upperB)


		dataForIn.write('{} {}\n'.format(a, b))
		dataForOut.write('{}\n'.format(a+b))
if __name__ == '__main__':
	main()