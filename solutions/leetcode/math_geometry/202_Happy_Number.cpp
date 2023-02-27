class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        // fast and slow will eventually be the same if it is endless loop

        while (slow != fast && fast != 1){
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        if (fast == 1){
            return true;
        }

        return false;

    }
private:
    int getNext(int n){
        int s = 0;

        while (n > 0){
            int k = n % 10;
            s += k * k;
            n /= 10;
        }
        return s;
    }
};