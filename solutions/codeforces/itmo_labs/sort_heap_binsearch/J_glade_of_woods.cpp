#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>


#define EPS 1e-10

using namespace std;

double time(double x, double v_p, double v_f, double a){
    
    return sqrt((1 - a) * (1 - a) + x * x) / v_p + sqrt(a * a + (1 - x) * (1 - x)) / v_f;
}

double TernarySearchMin(int v_p, int v_f, double border){

    double left = 0.0;
    double right = 1.0;

    while (right - left > EPS){
        double a = left + (right - left) / 3;
        double b = right - (right - left) / 3;

        double y_1 = time(a, v_p, v_f, border);
        double y_2 = time(b, v_p, v_f, border);

        if (y_1 < y_2){
            right = b;
        } else {
            left = a;
        }
    }

    return (left + right) / 2;
    // return left;

}


int main(){

    int v_p, v_f;
    double a;
    cin >> v_p >> v_f;
    cin >> a;

    cout << fixed << setprecision(9) << TernarySearchMin(v_p, v_f, a);

    return 0;
}