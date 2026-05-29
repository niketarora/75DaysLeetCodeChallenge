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
private:
    unordered_map<Node*, Node*> clonedMap;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        // If the node has already been cloned, return its clone
        if (clonedMap.find(node) != clonedMap.end()) {
            return clonedMap[node];
        }
        
        // Create a new node and map it to the original
        Node* cloneNode = new Node(node->val);
        clonedMap[node] = cloneNode;
        
        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};
