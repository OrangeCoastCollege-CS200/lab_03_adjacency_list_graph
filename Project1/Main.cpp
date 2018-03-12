#include <iostream>
#include "AdjListGraph.h"

using namespace std;

int main()
{
	vector<vector<string>> graphData =
	{
		{ "A", "B", "F" },
	{ "B", "C", "D", "F" },
	{ "C", "E" },
	{ "D", "G" },
	{ "E", "D", "F" },
	{ "F", "G" },
	{ "G" },
	};

	// TESTING DEFAULT CONSTRUCTOR
	cout << "TESTING DEFAULT CONSTRUCTOR\n";
	AdjListGraph defGraph;
	printGraphInfo(defGraph);
	cout << "\n";

	// TESTING OVERLOADED CONSTRUCTOR
	cout << "TESTING OVERLOADED CONSTRUCTOR\nParameter: 7\n";
	AdjListGraph ovGraph(7);
	printGraphInfo(ovGraph);
	cout << "\n";

	// TESTING CREATEGRAPH
	cout << "TESTING CREATEGRAPH\n-------Before-------\n";
	printGraphInfo(ovGraph);
	cout << "-------After-------\n";
	ovGraph.createGraph(graphData);
	printGraphInfo(ovGraph);
	cout << "\n";
	// Error when Graph data has more vertices than Graph object max vertices
	cout << "TESTING CREATEGRAPH (FAILURE)\n-------Before-------\n";
	AdjListGraph failGraph(1);
	printGraphInfo(failGraph);
	cout << "-------After-------\n";
	failGraph.createGraph(graphData);
	printGraphInfo(failGraph);
	cout << "\n";

	// TESTING COPY CONSTRUCTOR
	cout << "TESTING COPY CONSTRUCTOR\n-------Before-------\n";
	cout << "**Copy from**\n";
	printGraphInfo(ovGraph);
	cout << "-------After-------\n";
	AdjListGraph copyGraph(ovGraph);
	cout << "**New copy**\n";
	printGraphInfo(copyGraph);
	cout << "**Copy from**\n";
	printGraphInfo(ovGraph);
	cout << "\n";

	// TESTING OVERLOADED ASSIGNMENT
	// Assign graph to graph with more vertices.
	cout << "TESTING OVERLOADED ASSIGNMENT (ASSIGN MORE VTXS)\n-------Before-------\n";
	cout << "**Assign to**\n";
	printGraphInfo(defGraph);
	cout << "**Assign from**\n";
	printGraphInfo(ovGraph);
	cout << "-------After-------\n";
	defGraph = ovGraph;
	cout << "**Assign to**\n";
	printGraphInfo(defGraph);
	cout << "**Assign from**\n";
	printGraphInfo(ovGraph);
	cout << "\n";
	// Assign graph to graph with less vertices.
	cout << "TESTING OVERLOADED ASSIGNMENT (ASSIGN LESS VTXS)\n-------Before-------\n";
	cout << "**Assign to**\n";
	printGraphInfo(defGraph);
	cout << "**Assign from**\n";
	printGraphInfo(failGraph);
	cout << "-------After-------\n";
	defGraph = failGraph;
	cout << "**Assign to**\n";
	printGraphInfo(defGraph);
	cout << "**Assign from**\n";
	printGraphInfo(failGraph);
	cout << "\n";

	// TESTING MOVE CONSTRUCTOR
	cout << "TESTING MOVE CONSTRUCTOR\n-------Before-------\n";
	cout << "**Move from**\n";
	printGraphInfo(ovGraph);
	cout << "-------After-------\n";
	AdjListGraph moveGraph(move(ovGraph));
	cout << "**New Graph**\n";
	printGraphInfo(moveGraph);
	cout << "**Move from**\n";
	printGraphInfo(ovGraph);
	cout << "\n";

	// TESTING MOVE ASSIGNMENT
	// Assign graph to graph with more vertices.
	cout << "TESTING MOVE ASSIGNMENT (ASSIGN MORE VTXS)\n-------Before-------\n";
	cout << "**Move to**\n";
	printGraphInfo(ovGraph);
	cout << "**Move from**\n";
	printGraphInfo(moveGraph);
	cout << "-------After-------\n";
	ovGraph = move(moveGraph);
	cout << "**Move to**\n";
	printGraphInfo(ovGraph);
	cout << "**Move from**\n";
	printGraphInfo(moveGraph);
	cout << "\n";
	// Assign graph to graph with less vertices.
	cout << "TESTING MOVE ASSIGNMENT (ASSIGN LESS VTXS)\n-------Before-------\n";
	cout << "**Move to**\n";
	printGraphInfo(ovGraph);
	cout << "**Move from**\n";
	printGraphInfo(moveGraph);
	cout << "-------After-------\n";
	ovGraph = move(moveGraph);
	cout << "**Move to**\n";
	printGraphInfo(ovGraph);
	cout << "**Move from**\n";
	printGraphInfo(moveGraph);
	cout << "\n";

	// TESTING DESTRUCTOR
	AdjListGraph * destGraph = new AdjListGraph(7);
	destGraph->createGraph(graphData);
	cout << "TESTING DESTRUCTOR\n-------Before-------\n";
	printGraphInfo(*destGraph);
	cout << "-------After-------\n";
	delete destGraph;
	printGraphInfo(*destGraph);
	destGraph = nullptr;
	cout << "\n";

	// TESTING INSERTVERTEX
	cout << "TESTING INSERTVERTEX\n-------Original-------\n";
	printGraphInfo(copyGraph);
	cout << "--- Adding vertex H (with successors A and C) ---\n";
	copyGraph.insertVertex("H", vector<string>(), { "A", "C" });
	printGraphInfo(copyGraph);
	cout << "--- Adding vertex I (with predecessors B and D) ---\n";
	copyGraph.insertVertex("I", { "B", "D" }, vector<string>());
	printGraphInfo(copyGraph);
	cout << "--- Adding vertex J (with predecessors E and G and successors F and H) ---\n";
	copyGraph.insertVertex("J", { "E", "G" }, { "F", "H" });
	printGraphInfo(copyGraph);
	cout << "--- Attempting to add vertex J again ---\n";
	copyGraph.insertVertex("J", { "E", "G" }, { "F", "H" });
	printGraphInfo(copyGraph);
	cout << "--- Adding verticies K, L, M, and N (no predecessors or successors) ---\n";
	copyGraph.insertVertex("K", vector<string>(), vector<string>());
	copyGraph.insertVertex("L", vector<string>(), vector<string>());
	copyGraph.insertVertex("M", vector<string>(), vector<string>());
	copyGraph.insertVertex("N", vector<string>(), vector<string>());
	printGraphInfo(copyGraph);
	cout << "--- Attempting to add vertex O (already at max vertices) ---\n";
	copyGraph.insertVertex("O", vector<string>(), vector<string>());
	printGraphInfo(copyGraph);
	cout << "\n";

	// TESTING TRAVERSE
	cout << "TESTING TRAVERSE\nGraph to traverse:\n";
	printGraphInfo(copyGraph);
	cout << "Traversing: ";
	vector<string> travGraphVect = copyGraph.traverse();
	for (string vtx : travGraphVect) cout << vtx << " ";
	cout << "\n";

	// TESTING EMPTYGRAPH
	cout << "TESTING EMPTYGRAPH\n-------Before-------\n";
	printGraphInfo(copyGraph);
	cout << "-------After-------\n";
	copyGraph.emptyGraph();
	printGraphInfo(copyGraph);
	cout << "\n";

	cout << endl;
	system("Pause");
	return 0;
}

void printGraphInfo(const AdjListGraph& graph)
{
	cout << graph << "\nNumber of vertices: " << graph.n()
		<< "\nMax vertices: " << graph.getMaxVertices()
		<< "\nAddress: " << &graph << "\n";
}