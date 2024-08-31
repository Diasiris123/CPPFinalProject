#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {

	public:

		/// <summary>
		/// Adds a node to the graph if not exist
		/// </summary>
		/// <param name="node"></param>
		
		void AddNode(std::string node) {

			if (pathList.find(node) == pathList.end()) {
				pathList[node] = vector<string>();
			}

		}

		/// <summary>
		/// Conncects the source node to another node, making them neighbors and forming two sided edge
		/// </summary>
		/// <param name="sourceNode"></param>
		/// <param name="destinationNode"></param>
		
		void AddEdge(std::string sourceNode, std::string destinationNode) {

			pathList[sourceNode].push_back(destinationNode);
			pathList[destinationNode].push_back(sourceNode);

		}

		/// <summary>
		/// Prints the Graph
		/// </summary>
		
		void PrintGraph() {

			for (auto keyValue : pathList) {
				cout << keyValue.first << ":";
				for (std::string neighbors : keyValue.second) {
					cout << neighbors << " ";
				}
				cout << "\n";
			}

		}

		/// <summary>
		/// Shortest path algorithm without weights, using BFS method
		/// </summary>
		/// <param name="startDest"></param>
		/// <param name="endDest"></param>
		/// <returns></returns>

		vector<string> shortestPath(std::string startDest, std::string endDest) {

			unordered_map<string, string> previousNode;
			unordered_set<string> visitedNodes;
			queue<string> nodesToVisit;
			vector<string> path;

			nodesToVisit.push(startDest);
			visitedNodes.insert(startDest);
			previousNode[startDest] = "";

			while (nodesToVisit.empty()) {

				string currentNode = nodesToVisit.front();
				nodesToVisit.pop();

				if (currentNode == endDest){
					break;
				}

				for (std::string neighbor : pathList.at(currentNode)) {
					if (visitedNodes.find(neighbor) == visitedNodes.end()) {
						nodesToVisit.push(neighbor);
						visitedNodes.insert(neighbor);
						previousNode[neighbor] = currentNode;
					}
				}
			}

			for (std::string cn = endDest; !cn.empty(); previousNode[cn]) {
				path.push_back(cn);

				if (cn == startDest)
					break;
			}

			reverse(path.begin(), path.end());

			if (path.front() != startDest) {
				path.clear();
			}

			return path;
		}

	private:
		unordered_map<string, vector<string>> pathList;
};
 
 


