#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
const int MAX_N = 20; // Maximum size of the matrix

typedef vector<vector <long long> > matrix;

// Function for matrix multiplication
matrix multiply(const matrix &a, const matrix &b, int n) {
    matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

// Function for matrix exponentiation
matrix power(matrix a, long long p, int n) {
    matrix result(n, vector<long long>(n, 0));
    // Initialize result as the identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    while (p > 0) {
        if (p % 2) {
            result = multiply(result, a, n);
        }
        a = multiply(a, a, n);
        p /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> initial(n);
        for (int i = 0; i < n; i++) {
            cin >> initial[i];
        }

        // Construct the transition matrix
        matrix trans(n, vector<long long>(n, 0));

        for (int row_index=0; row_index<n; row_index++){
            for (int col_index=1; col_index<n; col_index++){
                if (col_index > row_index){
                    trans[row_index][col_index] += 1;
                }
                for (int upper_row_index=0; upper_row_index<row_index; upper_row_index++){
                    trans[row_index][col_index] += trans[upper_row_index][col_index];
                } 
            }
        }

        // Exponentiate the transition matrix
        matrix trans_k = power(trans, k, n);

        // Multiply the initial state vector by the exponentiated matrix
        for (int i = 0; i < n; i++) {
            long long position = 0;
            for (int j = 0; j < n; j++) {
                position = (position + trans_k[i][j] * initial[j]) % MOD;
            }
            cout << position << " ";
        }
        cout << endl;
    }
    return 0;
}
