#include "GraphManager.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class GraphManager {
public:

	/// <summary>
	/// parsing the JSON document and adding edges and nodes to the graph
	/// </summary>
	/// <param name="JSONString"></psaram>
	/// <param name="graph"></param>
	/// <returns></returns>
	 
	bool parseJSON(std::string JSONString, Graph graph) {

		int startNode = JSONString.find("\"nodes\":");
		if (startNode == string::npos)
			return false;
		startNode += 8;

		int endNode = JSONString.find("]", startNode);
		if (endNode == string::npos)
			return false;

		string nodesSection = JSONString.substr(startNode, endNode - startNode);
		stringstream nodesStream(nodesSection);
		string node;

		while (getline(nodesStream, node, ',')) {
			node.erase(remove(node.begin(), node.end(), '"'), node.end());
			node.erase(remove(node.begin(), node.end(), ' '), node.end());
			if (!node.empty())
				graph.AddNode(node);
		}

		int startEdges = JSONString.find("\"edges\":");
		if (startEdges == string::npos)
			return false;
		startEdges += 8;

		int endEdges = JSONString.find("]", startEdges);
		if (endEdges == string::npos)
			return false;

		string edgesSection = JSONString.substr(startEdges, endEdges - startEdges);
		stringstream edgesStream(edgesSection);
		string edge;

		while (getline(edgesStream, edge, '}')) {
			int startPosition = edge.find('{');
			if (startPosition == string::npos)
				continue;
			edge = edge.substr(startPosition + 1);

			int commaPosition = edge.find(",");
			if (commaPosition == string::npos)
				continue;
			string src = edge.substr(1, commaPosition - 1);
			string destination = edge.substr(commaPosition + 1);
			
			destination.erase(remove(destination.begin(), destination.end(), ' '), destination.end());
			destination.erase(remove(destination.begin(), destination.end(), '}'), destination.end());

			src.erase(remove(src.begin(), src.end(), '"'), src.end());
			src.erase(remove(src.begin(), src.end(), ' '), src.end());
			if (!src.empty() && !destination.empty()) {
				graph.AddEdge(src, destination);
			}
		}
	}
};
