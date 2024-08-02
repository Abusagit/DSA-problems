class Solution:
    def largestGoodInteger(self, num: str) -> str:
        
        sliding_window_counter = {}
        
        x1, x2, x3 = num[0], num[1], num[2]
        
        sliding_window_counter[x1] = 1
        sliding_window_counter[x2] = sliding_window_counter.get(x2, 0) + 1
        sliding_window_counter[x3] = sliding_window_counter.get(x3, 0) + 1
        
        if sliding_window_counter[x1] == 3: # or x2, or x3 - this is equivalent
            max_good_integer = x1
        else:
            max_good_integer = ""
        
        for i in range(3, len(num)):
            
            x_i = num[i]
            
            sliding_window_counter[num[i-3]] -= 1
            sliding_window_counter[x_i] = sliding_window_counter.get(x_i, 0) + 1
            
            if sliding_window_counter[x_i] == 3:
                max_good_integer = max(max_good_integer, x_i)

        
        return max_good_integer * 3