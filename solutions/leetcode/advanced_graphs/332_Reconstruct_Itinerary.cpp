#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;


// Greedy - get at each step minimal lexicographic airport
// Multiset contains keys in lexicographic order!!!

class Solution {
public:
    vector<string> findItinerary(vector<vector<string> >& tickets) {
        for (auto from_to: tickets){
            graph[from_to[0]].insert(from_to[1]);
        }

        vector<string> result;

        dfs("JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    unordered_map<string, multiset<string> > graph;

    void dfs(string airport, vector<string>& result){
        while(!graph[airport].empty()){
            string next_min_lexicographic_airport = *graph[airport].begin();
            
            graph[airport].erase(graph[airport].begin()); // need to pass pointer, if pass string - it will delete all keys with this string!!!
            dfs(next_min_lexicographic_airport, result);
        }

        result.push_back(airport);
    }


};