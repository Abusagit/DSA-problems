class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> result;

        int next_digit = 1;

        for (int i = digits.size() - 1; i >= 0; i--){
            int sum = digits[i] + next_digit;

            digits[i] = sum % 10;
            next_digit = sum / 10;
        }

        if (next_digit == 0){
            return digits;
        }

        result.push_back(next_digit);
        
        result.reserve(result.size() + distance(digits.begin(), digits.end()));
        result.insert(result.end(), digits.begin(), digits.end());

        return result;
    }
};