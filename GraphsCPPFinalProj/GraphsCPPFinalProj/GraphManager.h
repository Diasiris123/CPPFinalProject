#ifndef GRAPHMANAGER_H
#define GRAPHMANAGER_H

#include "Graph.h"

class GraphManager {
public:
	bool parseJSON(std::string JSONString, Graph graph);
};

#endif
