#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


unsigned long long bin_search_over_the_answer(int slow_t, int fast_t, unsigned long long n){

    unsigned long long right = n * fast_t;

    unsigned long long left = 1;


    // keep the smallest time possible
    unsigned long long leftmost = right;

    while (left <= right){
        unsigned long long mid = (left + right) / 2;

        unsigned long long papers_copied = mid / slow_t + mid / fast_t;

        if (papers_copied < n){
            left = mid + 1;
        } else {
            leftmost = mid;
            right = mid - 1;
        }
    }

    return leftmost;
}

int main(){
    long long n;
    int x, y;
    cin >> n >> x >> y;

    int minimum = min(x, y);
    long long ans = bin_search_over_the_answer(x + y - minimum, minimum, n - 1) + minimum;
    cout << ans;


}