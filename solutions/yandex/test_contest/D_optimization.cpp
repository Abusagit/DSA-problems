#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


typedef unsigned long long ull;
using namespace std;


void fill_array(vector<ull>& array){
    for (int i = 0; i < array.size(); i++){
        cin >> array[i];
    }

}

void print_q(priority_queue<ull, vector<ull>, greater<ull>> q){
    while (!q.empty()){
        cout << q.top() << ' ';
        q.pop();
    }
    cout << '\n';
}

ull function(vector<ull>& array){
    ull result = 0;

    sort(array.begin(), array.end());

    if (array.size() >= 3){

        priority_queue<ull, vector<ull>, greater<ull>> minq_1(array.begin(), array.end() - 2); // len = n - 2
        priority_queue<ull, vector<ull>, greater<ull>> minq_2(array.end() - 2, array.end()); // len = 2




        while (!minq_1.empty()){
            // print_q(minq_1);
            // cout << "-----\n";
            // print_q(minq_2);


            ull x = minq_1.top() + minq_2.top(); // x = a[0] + a[n-2]

            // cout << x << "\n============\n";
            result += x;

            minq_1.pop(); 
            minq_2.pop(); // delete(a, 0), delete(a, n-2)
            minq_2.push(x); // add(a, x) and sort immediately

        }

        ull a0, a1;
        a0 = minq_2.top();
        minq_2.pop();

        a1 = minq_2.top();
        minq_2.pop();

        result += a0 + a1;

        // sum(array) = a1 + a0

    } else if (array.size() == 2){
        result += array[0] + array[1];
    } else {
        result += array[0];
    }
    return result;
}


int main() {
    int n; cin >> n;

    vector<ull> array(n);
    fill_array(array);

    ull result = function(array);
    cout << result << '\n';

    return 0;
}