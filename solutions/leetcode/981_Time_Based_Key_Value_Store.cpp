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
        timestamp_values[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if (timestamp_values.find(key) == timestamp_values.end()){
            return "";
        }
        
        int left = 0;
        int right = timestamp_values[key].size() - 1;

        while (left <= right){
            int middle = right + (left - right) / 2;

            int middle_t = timestamp_values[key][middle].first;

            if (timestamp < middle_t){
                right = middle - 1;
            } else if (timestamp > middle_t){
                left = middle + 1;
            } else {
                return timestamp_values[key][middle].second;
            }

        }
        
        if (right >= 0){
            return timestamp_values[key][right].second;
        }
        return "";

    }

private:
    unordered_map<string, vector<pair<int, string>>> timestamp_values;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */