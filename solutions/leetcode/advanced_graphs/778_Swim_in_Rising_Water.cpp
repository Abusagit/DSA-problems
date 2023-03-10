
#include <vector>
#include <queue>
#include <utility>
// #include <iostream>

using namespace std;


class Solution {
public:
    int swimInWater(vector<vector<int> >& grid) {
        n = grid.size();

        // if only single cell - can already swim
        if (n == 1){
            return 0;
        }

        vector<vector<bool> > visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        int result = max(grid[0][0], grid[n - 1][n - 1]);

        pq.push({result, 0, 0});

        while (!pq.empty()){
            auto current = pq.top();
            pq.pop();

            result = max(result, current[0]); // water should be at most as maximum elevation of points if we want to swim between 2 points

            for (auto direction: directions){
                int x_offset = direction.first, y_offset = direction.second;

                int x = current[1] + x_offset, y = current[2] + y_offset;


                // check boundaries and if we have alredy visited this cell with less value of result
                if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]){
                    continue;
                }

                // due to priority queue, if we have reached (n-1, n-1) at first time, we eill reach it in the least possible time
                if (x == n - 1 && y == n - 1){
                    return result;
                }

                pq.push({grid[x][y], x, y});
                visited[x][y] = true;
            }
        
        }

        // this line will never be achieved

        return -1;

    }
private:
    int n;
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;

    vector<pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    
};