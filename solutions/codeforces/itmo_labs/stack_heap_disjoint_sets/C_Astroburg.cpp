#include <iostream>
#include <vector>

using namespace std;

#define int long long int


vector<int> queue(100001);
vector<int> id2position(100001);

int head_index = 0;
int tail_index = 0;

void push_back(int id){
    queue[tail_index] = id;
    id2position[id] = tail_index;

    tail_index++;
}


int pop_from_back(){

    return queue[--tail_index];
}

int pop_from_front(){

    return queue[head_index++];

}

int get_queue_size_before_element(int q){
    return id2position[q] - head_index;
}

signed main(){

    int n; cin >> n;
    cin.tie(0);

    for (int i = 0; i < n; i++){

        int command_id; cin >> command_id;

        if (command_id == 1){
            int id; cin >> id;
            push_back(id);

        } else if (command_id == 2){
            pop_from_front();

        } else if (command_id == 3){
            pop_from_back();
        } else if (command_id == 4){
            int id; cin >> id;
            cout << get_queue_size_before_element(id) << '\n';

        } else {
            cout << queue[head_index] << '\n';
        }
    }

    return 0;
}