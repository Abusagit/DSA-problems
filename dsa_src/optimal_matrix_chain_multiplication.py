import sys

def MatrixChainOrder(p):
    # Length of the chain of matrices
    n = len(p) - 1

    # Initializing the m and s arrays
    m = [[0 for x in range(n)] for x in range(n)]
    s = [[0 for x in range(n)] for x in range(n)]

    # Fill the entries for chains of length 2 to n
    for chain_length in range(2, n + 1):
        for i in range(1, n - chain_length + 2):
            j = i + chain_length - 1
            m[i-1][j-1] = sys.maxsize  # Set to infinity
            for k in range(i, j):
                # Cost calculation
                q = m[i-1][k-1] + m[k][j-1] + p[i-1] * p[k] * p[j]
                # Update minimum cost and placement
                if q < m[i-1][j-1]:
                    m[i-1][j-1] = q
                    s[i-1][j-1] = k

    return m, s

def PrintOptimalParens(s, i, j):
    if i == j:
        print(f"A{i}", end='')  # single matrix
    else:
        print("(", end='')  # opening bracket
        PrintOptimalParens(s, i, s[i-1][j-1])  # split left subchain
        PrintOptimalParens(s, s[i-1][j-1] + 1, j)  # split right subchain
        print(")", end='')  # closing bracket

# Example usage
p = [10, 7, 4, 1]  # dimensions of A1...A6
m, s = MatrixChainOrder(p)
print(f"Minimum number of multiplications is {m[0][len(p)-2]}.")
print("Optimal Parenthesization is: ", end='')
PrintOptimalParens(s, 1, len(p)-1)
