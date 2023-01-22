#include <iostream>
#include <vector>


using namespace std;

int LIS(vector<int>& nums, vector<int>& d) {
    // O(n^2)

    int result = 1;
    for (int i = 1; i < nums.size(); i++){
        for (int j = 0; j < i; j++){
            if (nums[j] < nums[i]){
                d[i] = max(d[i], 1 + d[j]);
            }
        }

        result = max(result, d[i]);
    }

    return result;

}


int main(){
    int n; cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> d(n, 1);

    int lis_len = LIS(nums, d);

    int k = lis_len;
    int i = n - 1;
    vector<int> res;

    while (i >= 0 && k > 0){
        if (d[i] == k){
            res.push_back(nums[i]);
            k--;
        }
        i--;
    }

    cout << lis_len << '\n';
    for (auto it = res.end() - 1; it >= res.begin(); it--){
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
