#include <iostream>
#include <vector>
#include <cmath>

unsigned long long P = 1000000007;

using namespace std;

vector<unsigned long long> PRIMES;


vector<int> factorize_factorial(int factorial){
    vector<int> factors(PRIMES.size());


    for (int i = 0; i < PRIMES.size(); i++){
        
        unsigned long long p = PRIMES[i];

        int number_of_p_in_factorial_decomposition = 0;
        
        // see factorial prime factorization in Wikipedia
        int t = floor(factorial / p);
        while (t > 0){
            // cout << factorial << " " << power << "\n";
            number_of_p_in_factorial_decomposition += t;
            t /= p;
        }

        // cout << p << ' ' << number_of_p_in_factorial_decomposition << '\n';
        factors[i] = number_of_p_in_factorial_decomposition;

    }


    return factors;
};


void simplify_factors(vector<int>& n_factors, vector<int> k_factors, vector<int> n_minus_k_factors){

    for (int i = 0; i < n_factors.size(); i++){

        n_factors[i] -= (k_factors[i] + n_minus_k_factors[i]);

    }
}

unsigned long long myPow(unsigned long long x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  unsigned long long tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}


unsigned long long count_phi(vector<int> prime_decomposition){

    unsigned long long result = 1;

    for (int i = 0; i < prime_decomposition.size(); i++){

        if (prime_decomposition[i] == 0){
            continue;
        }


        unsigned long long prime = PRIMES[i];

        int power = prime_decomposition[i];


        unsigned long long prime_alpha_minus_1 = myPow(prime, power - 1);

        result *= prime_alpha_minus_1 * (prime - 1);
        result %= P;
    }

    return result % P;

}


void generate_primes(int n){
    vector<bool> p(n + 1, true);
    p[0] = false;
    p[1] = false;
    // cout << n << "\n";

    int x = 2;
    while (x * x <= n){
        // cout << x << "\n";
        if (p[x]){
            PRIMES.push_back(x);

            for (int y = x * x; y <= n; y+=x){
                p[y] = false;
            }
        }
        x++;
    }

    for (int i = x; i <= n; i++){
        // cout << i << "\n";
        if (p[i]){
            PRIMES.push_back(i);
        }
    }


    // for (auto x: PRIMES){
    //     cout << x << " ";
    // }

    // cout << "\n";
}

int main(){
    int k, n;
    cin >> k >> n;

    generate_primes(n);

    vector<int> n_decomposition = factorize_factorial(n);
    vector<int> k_decomposition = factorize_factorial(k);

    vector<int> n_minus_k_decomposition;
    
    if (k == n-k){
        n_minus_k_decomposition = k_decomposition;
    } else {
        n_minus_k_decomposition = factorize_factorial(n - k);
    }

    simplify_factors(n_decomposition, k_decomposition, n_minus_k_decomposition);

    // for (auto x: final_decomposition){
    //     cout << x << " ";
    // }

    // cout << '\n';
    unsigned long long phi = count_phi(n_decomposition);

    cout << phi << '\n';

    return 0;
}