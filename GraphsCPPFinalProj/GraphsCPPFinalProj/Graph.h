#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>

class Graph {
public:
    void AddNode(std::string node);
    void AddEdge(std::string sourceNode, std::string destinationNode);
    void PrintGraph();
    vector<string> shortestPath(std::string startDest, std::string endDest);

private:
    unordered_map<string, vector<string>> pathList;
};

#endif