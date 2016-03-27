#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

/**
 * Definition for Directed graph.
 */
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
    void addIncomingConnection(DirectedGraphNode* node,
                               map<DirectedGraphNode*, int> &incomingConnections) {
        auto it = incomingConnections.find(node);

        if (it == incomingConnections.end()) {
            incomingConnections[node] = 1;
        } else {
            incomingConnections[node] = incomingConnections[node] + 1;
        }
    }

    void calculateIncomingConnections(vector<DirectedGraphNode*> &graph,
                                      map<DirectedGraphNode*, int> &incomingConnections,
                                      unordered_set<DirectedGraphNode*> &visited) {
        for (auto &node : graph) {
            auto it = incomingConnections.find(node);

            if (it == incomingConnections.end()) {
                incomingConnections[node] = 0;
            }

            if (visited.emplace(node).second) {
                for (auto &neighbor : node->neighbors) {
                    addIncomingConnection(neighbor, incomingConnections);
                }

                calculateIncomingConnections(node->neighbors, incomingConnections, visited);
            }
        }
    }

    queue<DirectedGraphNode *> getRoots(map<DirectedGraphNode*, int> &incomingConnections) {
        queue<DirectedGraphNode*> roots;

        for (auto &pair : incomingConnections) {
            if (pair.second == 0) {
                //cout << "found a root" << pair.first->label << endl;
                roots.emplace(pair.first);
            }
        }

        return roots;
    }

    vector<DirectedGraphNode *> topSort(vector<DirectedGraphNode*> &graph,
                                        map<DirectedGraphNode*, int> &incomingConnections) {
        vector<DirectedGraphNode*> result;
        queue<DirectedGraphNode*> roots = getRoots(incomingConnections);

        while (!roots.empty()) {
            DirectedGraphNode* node = roots.front();
            roots.pop();

            result.push_back(node);

            for (auto &neighbor : node->neighbors) {
                --incomingConnections[neighbor];

                if (incomingConnections[neighbor] == 0) {
                    //cout << "adding node as a root" << neighbor->label << endl;
                    roots.emplace(neighbor);
                }
            }
        }

        return result;
    }
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        map<DirectedGraphNode*, int> incomingConnections;
        unordered_set<DirectedGraphNode*> visited;

        calculateIncomingConnections(graph, incomingConnections, visited);

        /*for (auto &pair : incomingConnections) {
            cout << pair.first->label << " has " << pair.second << " incoming connections" << endl;
        }*/

        return topSort(graph, incomingConnections);
    }
};
