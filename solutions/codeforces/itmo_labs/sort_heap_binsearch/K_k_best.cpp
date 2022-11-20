#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stdio.h>

using namespace std;


struct Tresure{
    int index;
    int weight;
    int value;

    double coeff;
};



bool compare_by_coeff(Tresure a, Tresure b){ //descending order of Treasures by their amortized coefficients
    return a.coeff > b.coeff;
}

bool compare_by_index(Tresure a, Tresure b){ //ascending order before final output
    return a.index < b.index;
}

bool check(double coefficient, vector<Tresure>& array, int k){
    for (int i = 0; i < array.size(); i++){
        // get larger values for Treasures with lower denominators 
        // coefficient should be small enough to penalize Treasures with high value/weight ratio but with high weight as well
        // ==> e.g. with small coefficient Treasure with value 2 and weight 5 will be more pleasant than Treasure with value 200 and weight 500
        array[i].coeff = 1.0 * array[i].value * coefficient - 1.0 * array[i].weight;
    }

    sort(array.begin(), array.end(), compare_by_coeff);

    double sum = 0;

    // sum of top K treasures` coeffs should be zero
    for (int i = 0; i < k; i++){
        sum += array[i].coeff;
    }

    return sum < 0;
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    vector<Tresure> array(n);
    

    // initialize array of things
    for (int i = 0; i < n; i++){
        scanf("%d %d", &array[i].value, &array[i].weight);
        array[i].index = i + 1;
    }

    double left = 0, right = 1e+7;
    for (int j = 0; j < 50; j++){
        double m = (left + right) / 2;

        
        if (check(m, array, k)) { // checks whether new sum of coeff for the top K treasures sums up to 0 
            left = m;
        } else {
            // if sum is not zero - try smaller coefficient ==> large denominators will make sum = 0
            right = m;
        }
        // printf("%lf, %d \n", m, check(m, array, k));
    
    }

    // printf("%lf:\n", (left + right) / 2);

    sort(array.begin(), array.begin() + k, compare_by_index);
    for (int i = 0; i < k; i++){
        printf("%d %lf\n", array[i].index, array[i].coeff);
    }
    return 0;
}