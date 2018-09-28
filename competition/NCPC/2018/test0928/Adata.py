def isprime(n):
	if n == 1:
		return False
	for i in range(2, n):
		if n % i == 0:
			return False
	return True


with open('Adata2', 'w') as f:
	for i in range(1, 100005):
		if isprime(i):
			print(i, end=',', file=f)
