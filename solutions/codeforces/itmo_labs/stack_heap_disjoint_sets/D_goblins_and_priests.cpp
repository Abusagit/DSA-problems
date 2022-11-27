#include <iostream>
#include <deque>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int size = 0;
    deque<int> first_half, second_half;

    for (int i = 0; i < n; i++){
        char q; cin >> q;

        if (q == '+'){
            int i; cin >> i;

            second_half.push_back(i);
            size++;

            if (size % 2 == 1 && first_half.size() < second_half.size()){
                first_half.push_back(second_half.front());
                second_half.pop_front();
            }


        } else if (q == '*'){
            int i; cin >> i;
            first_half.push_back(i);
            size++;

            if (size % 2 == 0 && first_half.size() - second_half.size() > 1){
                second_half.push_front(first_half.back());
                first_half.pop_back();
            }

        } else {
            size--;
            cout << first_half.front() << '\n';
            first_half.pop_front();

            if (size % 2 == 1){
                first_half.push_back(second_half.front());
                second_half.pop_front();
            }
            

        }
    }

    return 0;
}