#include <vector>
#include <algorithm>
#include <queue>


// priority queue

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;


        for (int i = 0; i < nums.size(); i++){
                min_pq.push(nums[i]);
        }

        while (min_pq.size() > k){
            min_pq.pop();
        }
        
    }

    
    int add(int val) {
        min_pq.push(val);

        if (min_pq.size() > k){
            min_pq.pop();
        }

        return min_pq.top();


    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq; // min_heap containing k largest elements. min_pq.top() == a_(k)

    int k;

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */