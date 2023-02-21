class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize){
            return false;
        }

        map<int, int> counter;

        for (auto x: hand){ // count values
            counter[x]++;
        }

        while (!counter.empty()){ // number of elements is divisible by groupSize!
            int current_min = counter.begin()->first; //get key of first element;

            // get current minimum as startin value and then check if consecutive lements exist
            for (int i = 0; i < groupSize; i++){
                if (counter.find(current_min + i) == counter.end()){
                    return false;
                }

                counter[current_min + i]--;

                if (counter[current_min + i] <= 0){
                    counter.erase(current_min + i);
                }
            }
        }

        return true;

    }
};