import math
import sys

P = 1000000007

def primes(n):
    if n >= 2:
        sieve = bytearray(n)
        sieve[:2] = 1, 1
        for i in range(math.isqrt(n - 1) + 1):
            if sieve[i] == 0:
                for j in range(i * i, n, i):
                    sieve[j] = 1
        
        
        primes = [i for i, n in enumerate(sieve) if n == 0]
        return primes


def factorial_exponent(n, p):
    # assert is_prime(p)
    e = 0
    t = math.floor(n / p)
    while t > 0:
        e += t
        t //= p
    return e

def binomial_exponent(n, k, p):
    return factorial_exponent(n, p) - (factorial_exponent(k, p) + factorial_exponent(n - k, p))

def phi_cnk(n, k):
    phi = 1
    for p in primes(n + 1):
        e = binomial_exponent(n, k, p)
        if e > 0:
            phi *= ((p - 1) * p ** (e - 1)) % P
    return phi % P


k, n = map(int, sys.stdin.readline().strip().split())

a = phi_cnk(n, k)

print(a)