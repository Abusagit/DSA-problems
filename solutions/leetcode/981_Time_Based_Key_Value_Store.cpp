#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using std::string;
using std::unordered_map;
using std::vector;
using std::pair;

class TimeMap {
public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (timestamp_values.find(key) != timestamp_values.end()){
            timestamp_values[key].push_back({timestamp, value});
        } else {
            timestamp_values[key] = {{0, ""}, {timestamp, value}};
        }
    }
    
    string get(string key, int timestamp) {

        vector<pair<int, string>> query_vector = timestamp_values[key];

        string rightmost_s = binary_search_of_the_rightmost_value(query_vector, timestamp);
        return rightmost_s;

    }

private:
    unordered_map<string, vector<pair<int, string>>> timestamp_values;

    string binary_search_of_the_rightmost_value(vector<pair<int, string>>& timestamps, int time){
        int left = 0;
        int right = timestamps.size();

        while (left < right){
            int middle = right + (left - right) / 2;

            int middle_t = timestamps[middle].first;

            if (time < middle_t){
                right = middle;
            } else {
                left = middle + 1;
            }

        }

        return timestamps[left].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */