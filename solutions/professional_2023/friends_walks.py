MOD = 1000000007


def count_values(initial_values: list[int], k):
    overall_sum = sum(initial_values) % MOD
    
    n = len(initial_values)
    
    
    for step in range(k):
        
        for i in range(n):
            coord = initial_values[i]
            
            overall_sum -= coord
            initial_values[i] = overall_sum

            overall_sum += overall_sum
            overall_sum %= MOD

    return initial_values
            
t = int(input())

for _ in range(t):
    
    n, k = map(int, input().split())
    
    coords = list(map(int, input().split()))
    print(*count_values(coords, k))