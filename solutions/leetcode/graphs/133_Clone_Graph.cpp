/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        Node* copy = new Node(node->val);
        dict[node] = copy;


        queue<Node*> q;
        q.push(node);


        while (!q.empty()) {
            Node* current_old_node = q.front();
            q.pop();

            for (Node* old_neighbor: current_old_node->neighbors){

                if (dict.find(old_neighbor) == dict.end()){
                    dict[old_neighbor] = new Node(old_neighbor->val);
                    q.push(old_neighbor);
                }

                dict[current_old_node]->neighbors.push_back(dict[old_neighbor]);
            }
        }
    
    return copy;
    }
private:
    unordered_map<Node*, Node*> dict;
};