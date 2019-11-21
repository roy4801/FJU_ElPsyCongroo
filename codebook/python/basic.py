import sys

PROBLEM = ''

def ifdef():
    sys.stdin = open(PROBLEM + '.in', 'r')
    sys.stdout = open(PROBLEM + '.out', 'w')


if __name__ == "__main__":
    ifdef()
    while True:
        try:
            # int a, cin >> a
            a = int(input())

        except:
            break
