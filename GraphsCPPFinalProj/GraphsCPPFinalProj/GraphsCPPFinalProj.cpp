#include <iostream>
#include "GraphManager.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    GraphManager graphManager;
    Graph graph;
    string filename = "graph.json";

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file : " << filename;
        return 1;
    }

    stringstream informationHolder;
    informationHolder << file.rdbuf();
    string JSONString = informationHolder.str();
    file.close();

    if (!graphManager.parseJSON(JSONString, graph)) {
        cout << "Can't parsing JSON";
        return 1;
    }

    graph.PrintGraph();

    string startNode, endNode;
    cout << "Enter start node: ";
    cin >> startNode;
    cout << "Enter end node: ";
    cin >> endNode;

    vector<string> path = graph.shortestPath(startNode, endNode);
    if (path.empty()) {
        cout << "No path has found from " << startNode << " to " << endNode;
    }
    else {
        cout << "The shortest path from " << startNode << " to " << endNode << " is: ";
        for (string node : path) {
            cout << node << " ";
        }
    }

    return 0;
}

