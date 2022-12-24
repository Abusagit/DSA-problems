import sys

P = 1000000007

N = sys.stdin.readline()
array = map(int, sys.stdin.readline().strip().split())

remainders_of_power_of_2 = [1 for _ in range(101)]

exp = 1
for i in range(1, 100 + 1):
    exp <<= 1
    
    exp = exp if exp < P else exp - P
    remainders_of_power_of_2[i] = exp

print(remainders_of_power_of_2)
ways_to_cover_without_last_vertex = ways_to_cover_with_last_vertex = 1

next(array)

for d in array:
    
    tmp = ways_to_cover_with_last_vertex
    print(remainders_of_power_of_2[d])
    s = (ways_to_cover_with_last_vertex + ways_to_cover_without_last_vertex) % P
    ways_to_cover_with_last_vertex = (remainders_of_power_of_2[d] * s) % P

    ways_to_cover_without_last_vertex = tmp

print((ways_to_cover_with_last_vertex + ways_to_cover_without_last_vertex) % P)