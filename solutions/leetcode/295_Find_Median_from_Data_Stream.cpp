#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap_first_half.empty()){
            max_heap_first_half.push(num);
            return;
        }
        int max_heap_top = max_heap_first_half.top();

        // if (!min_heap_second_half.empty()){
        //     min_heap_top = min_heap_second_half.top();
        // } else {
        //     min_heap_top = MIN; // ??????
        // }


        //rebalance heaps to fit invariant - size of maxHeap shoul be equal or greater than minHeap

        if (num <= max_heap_top){
            max_heap_first_half.push(num);
            if (max_heap_first_half.size() - min_heap_second_half.size() > 1){
                min_heap_second_half.push(max_heap_first_half.top());
                max_heap_first_half.pop();
            }
        } else {
            min_heap_second_half.push(num);
            if (min_heap_second_half.size() - max_heap_first_half.size() > 0){
                max_heap_first_half.push(min_heap_second_half.top());
                min_heap_second_half.pop();
            }
        }


    }
    
    double findMedian() {
        if (min_heap_second_half.size() == max_heap_first_half.size()){
            return static_cast<double>(max_heap_first_half.top() + min_heap_second_half.top()) / 2;
        } else {
            return static_cast<double>(max_heap_first_half.top());
        }

    }
private:

priority_queue<int, vector<int>> max_heap_first_half;
priority_queue<int, vector<int>, greater<int>> min_heap_second_half;



};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */