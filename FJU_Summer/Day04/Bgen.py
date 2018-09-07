with open('B.data', 'w') as f:
     for i in range(4294967926):
             f.write(str((2 ** i) % 2076030))
             f.write('\n')