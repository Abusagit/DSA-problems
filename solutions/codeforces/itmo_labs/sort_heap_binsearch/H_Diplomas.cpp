#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


// LEFTMOST SEARCH
unsigned long long bin_search_over_the_answer(unsigned long long w, unsigned long long h, unsigned long long n){

    unsigned long long right = max(w, h) * n;

    unsigned long long left = 0;

    while (left <= right){
        unsigned long long mid = right - (right - left) / 2;
        unsigned long long rectangles_can_be_places = (mid / w) * (mid / h);

        if (rectangles_can_be_places < n){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // return again the lowest possible value we can get

    return left;
}


int main(){
    unsigned long long n, w, h;
    cin >> w >> h >> n;


    cout << bin_search_over_the_answer(w, h, n);




}