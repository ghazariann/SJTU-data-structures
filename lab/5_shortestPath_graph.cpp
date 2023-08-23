#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Connection {
    int source, destination, weight;
};

vector<int> findShortestDistances(int numNodes, int numConnections, vector<Connection>& network, int startNode) {
    vector<int> distances(numNodes, INT_MAX);
    distances[startNode] = 0;

    for(int i = 1; i <= numNodes - 1; ++i) {
        for(int j = 0; j < numConnections; ++j) {
            int u = network[j].source;
            int v = network[j].destination;
            int weight = network[j].weight;
            if(distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    return distances;
}

int main() {
    int numNodes, numConnections, startNode, endNode;
    cin >> numNodes >> numConnections >> startNode >> endNode;
    startNode--;
    endNode--;

    vector<Connection> network;
    for(int i = 0; i < numConnections; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        source--;
        destination--;
        network.push_back({source, destination, weight});
    }

    vector<int> shortestDistances = findShortestDistances(numNodes, numConnections, network, startNode);

    cout << shortestDistances[endNode];
    return 0;
}
