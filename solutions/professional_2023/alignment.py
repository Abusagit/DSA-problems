# n = int(input())
# m = int(input())

# matrix = [list(map(int, input().split())) for _ in range(n)]


# D = [[0] * m for _ in range(n)]

# D[0][0] = matrix[0][0]



# for i in range(n):
#     for j in range(m):

n = int(input())
m = int(input())
A = [list(map(int, input().split(','))) for _ in range(n)]

dp = [[-1]*m for _ in range(n)]
path = [[0]*m for _ in range(n)]

# Заполнение матрицы dp
dp[0][0] = A[0][0]
for j in range(1, m):
    dp[0][j] = dp[0][j-1] + A[0][j]
    
for i in range(1, n):
    for j in range(i, m):
        dp[i][j] = A[i][j] + max(dp[i-1][j-1], dp[i][j-1])



# Восстановление пути
i, j = n-1, m-1
path[i][j] = 1

while i > 0 or j > 0:
    if i == 0:
        j -= 1
    elif j == 0:
        i -= 1
    else:
        if dp[i-1][j-1] > dp[i][j-1]:
            i -= 1
            j -= 1
        else:
            j -= 1
            
    path[i][j] = 1
            
path[0][0] = 1

# Вывод результата
for row in path:
    print(', '.join(map(str, row)))