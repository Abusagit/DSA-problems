class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int result = 0;

        for (auto x = points.begin(); x != points.end(); x++){
            unordered_map<int, int> y_coordinates = x->second;
            int x2 = x->first;
            for (auto y = y_coordinates.begin(); y != y_coordinates.end(); y++){
                int y2 = y->first;

                if (abs(x2-x1)==0 || abs(x2 - x1) != abs(y2 - y1)){
                    continue;
                }

                result += points[x1][y2] * points[x2][y2] * points[x2][y1];

            }

        }

        return result;
    }
private:
    unordered_map<int, unordered_map<int, int>> points;

};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */