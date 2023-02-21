class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, current = 0, n = gas.size();

        int result = 0;
        for (int i = 0; i < n; i++){
            total+= gas[i] - cost[i];

            current += gas[i] - cost[i];

            if (current < 0){
                result = i + 1;
                current = 0;
            }
        }

        return total < 0? -1: result;
    }
};