#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define DUMMY 1000000

struct Disjoint_set
{
    Disjoint_set() {}
    Disjoint_set(int min_val, int max_val, int size): min_val(min_val), max_val(max_val), size(size) {}
    int min_val;
    int max_val;
    int size;
};


int find_parent(int x, vector<int>& parents){
    if (x != parents[x]){
        // cout << x << " ";
        parents[x] = find_parent(parents[x], parents);
    }
    // cout << x << "\n";
    return parents[x];
}


vector<int> get(vector<int>& parents, vector<Disjoint_set>& sets, int x){
    Disjoint_set s = sets[find_parent(x, parents)];
    return {s.min_val, s.max_val, s.size};
}

void perform_union(vector<int>& parents, vector<Disjoint_set>& sets, int x, int y){
    x = find_parent(x, parents);
    y = find_parent(y, parents);
    if (x == y){
        return;
    }

    // x != y
    Disjoint_set set_with_x = sets[x];
    Disjoint_set set_with_y = sets[y];
    Disjoint_set merged_set(min(set_with_x.min_val, set_with_y.min_val),
                            max(set_with_x.max_val, set_with_y.max_val),
                            set_with_x.size + set_with_y.size);
    

    parents[y] = x;
    sets[x] = merged_set;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> results;

    int n; cin >> n;

    vector<Disjoint_set> sets(n + 1);
    vector<int> parents(n + 1);

    for (int i = 0; i <= n; i++){
        Disjoint_set d(i, i, 1);
        parents[i] = i;
        sets[i] = d;
    }


    string command;

    while (cin >> command){
        if (command == "union"){
            int x, y; cin >> x >> y;
            perform_union(parents, sets, x, y);
        } else {
            int x; cin >> x;
            // cout << find_parent(x, parents) << " !!!\n";
            vector<int> output = get(parents, sets, x);

            // cout << output[0] << ' ' << output[1] << ' ' << output[2] << '\n';
            results.push_back(output);
        }
    
    }



    for (auto result: results){
        cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
    }

    return 0;
}