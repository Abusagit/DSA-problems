#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define EPS 1e-10

double f(double x){
    return x * x + sqrt(x);
}

 
double answer(double c){


    double epsilon = 1e-6;
    double left = 0.0;

    double right = 1e11;

    while (right - left > EPS){
        double x = (left + right) / 2;

        double value = f(x);

        // if (abs(value - c) < epsilon){
        //     return x;
        // }

        if (value > c){
            right = x;
        } else {
            left = x;
        }

    }

    return left;


}


int main(){
    double c;
    cin >> c;


    cout << fixed << setprecision(9) << answer(c); // ADD THESE LINES!!!!! << fixed << setprecision(9)

    return 0;

}