class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (char x: s){
            if (x == '('){
                leftMin++;
                leftMax++;
            } else if (x == ')'){
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }

            if (leftMax < 0){
                return false;
            }

            if (leftMin < 0){ // s = ( * ) (
                leftMin = 0;
            }
        }

        return leftMin <= 0 && 0 <= leftMax;
    }
};