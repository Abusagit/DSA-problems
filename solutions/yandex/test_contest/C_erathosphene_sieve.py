N = 500000


numbers = [True for _ in range(N + 1)]

numbers[0], numbers[1] = False, False

x = 2

while x ** 2 <= N:
    if numbers[x]:
        for i in range(x ** 2, N + 1, x):
            numbers[i] = False
    x += 1
    
PRIMES = '{' + ','.join(str(i) for i, n in enumerate(numbers) if n) + '}'

with open("primes_below_500k.txt", "w") as f_write:
    f_write.write(PRIMES)