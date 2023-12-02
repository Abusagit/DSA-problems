#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

double countExpectation(const std::vector<int>& deck) {
    // Create an unordered set to hold unique values
    std::unordered_set<int> uniqueSet(deck.begin(), deck.end());
    // Convert the set to a vector and sort it
    std::vector<int> uniqueValues(uniqueSet.begin(), uniqueSet.end());
    std::sort(uniqueValues.begin(), uniqueValues.end());
    
    // Calculate the CDF of X
    std::unordered_map<int, double> F_x;
    for (int number : deck) {
        F_x[number]++;
    }
    for (auto& pair : F_x) {
        pair.second /= deck.size();
    }
    for (size_t j = 1; j < uniqueValues.size(); ++j) {
        F_x[uniqueValues[j]] += F_x[uniqueValues[j - 1]];
    }

    // Calculate CDF of min and max of three i.i.d random variables
    std::unordered_map<int, double> F_min, F_max;
    for (int number : uniqueValues) {
        double cdf_number = F_x[number];
        F_min[number] = 1 - pow(1 - cdf_number, 3);
        F_max[number] = pow(cdf_number, 3);
    }

    // Calculate PMF of min and max
    std::unordered_map<int, double> P_min, P_max;
    P_min[uniqueValues[0]] = F_min[uniqueValues[0]];
    P_max[uniqueValues[0]] = F_max[uniqueValues[0]];
    for (size_t j = 1; j < uniqueValues.size(); ++j) {
        int current_number = uniqueValues[j];
        int prev_number = uniqueValues[j - 1];
        P_min[current_number] = F_min[current_number] - F_min[prev_number];
        P_max[current_number] = F_max[current_number] - F_max[prev_number];
    }

    // Calculate the expected value
    double expectedValue = 0.0;
    for (int number : uniqueValues) {
        expectedValue += number * (P_min[number] + P_max[number]);
    }
    
    return expectedValue;
}

int main() {
    std::vector<int> deck = {1, 1, 4, 5, 6}; // Example deck
    std::cout << "Expected value: " << countExpectation(deck) << std::endl;
    return 0;
}
