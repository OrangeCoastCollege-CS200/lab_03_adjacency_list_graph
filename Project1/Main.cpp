/*
Badajoz, Severiano

CS A200
March 11, 2018

Lab 03
*/

#include <iostream>
#include "AdjListGraph.h"

using namespace std;


void print(const AdjListGraph& graph);

int main()
{
	vector<vector<string>> data =
	{
		{ "A", "B", "F" },
	{ "B", "C", "D", "F" },
	{ "C", "E" },
	{ "D", "G" },
	{ "E", "D", "F" },
	{ "F", "G" },
	{ "G" },
	};

	cout << "DEFAULT CONSTRUCTOR" << endl;
	AdjListGraph graph1;
	print(graph1);
	cout << endl;

	cout << "OVERLOADED CONSTRUCTOR" << endl << "Parameter: 7" << endl;
	AdjListGraph graph2(7);
	print(graph2);
	cout << endl;

	cout << "CREATE GRAPH" << endl; 
	cout << "-Before--" << endl;
	print(graph2);
	cout << "-After-" << endl;
	graph2.createGraph(data);
	print(graph2);
	cout << endl;

	cout << "CREATE GRAPH(ERROR)" << endl; 
	cout << "-Before-" << endl;
	AdjListGraph graph3(1);
	print(graph3);
	cout << "-After-" << endl;
	graph3.createGraph(data);
	print(graph3);
	cout << endl;

	cout << "COPY CONSTRUCTOR" << endl; 
	cout << "-Before-" << endl;
	cout << "other: ";
	print(graph2);
	cout << "-After-" << endl;
	AdjListGraph copyGraph(graph2);
	cout << "new: ";
	print(copyGraph);
	cout << "other: ";
	print(graph2);
	cout << endl;


	cout << "OVERLOADED ASSIGNMENT(> VERTEXES)" << endl;
	cout << "-Before-" << endl;
	cout << "calling:";
	print(graph1);
	cout << "other: ";
	print(graph2);
	cout << "-After-" << endl;
	graph1 = graph2;
	cout << "calling: ";
	print(graph1);
	cout << "other: ";
	print(graph2);
	cout << endl;

	cout << "OVERLOADED ASSIGNMENT (< VERTEXES)" << endl; 
	cout << "-Before-" << endl;
	cout << "calling: " << endl;
	print(graph1);
	cout << "other: " << endl;
	print(graph3);
	cout << "-After-" << endl;
	graph1 = graph3;
	cout << "calling: " << endl;
	print(graph1);
	cout << "other: " << endl;
	print(graph3);
	cout << endl;

	cout << "MOVE CONSTRUCTOR" << endl; 
	cout << "-Before-" << endl;
	cout << "other: ";
	print(graph2);
	cout << "-After-" << endl;
	AdjListGraph moveGraph(move(graph2));
	cout << "new: ";
	print(moveGraph);
	cout << "other: ";
	print(graph2);
	cout << endl;

	cout << "MOVE ASSIGNMENT (ASSIGN MORE VTXS)" << endl; 
	cout << "-Before-" << endl;
	cout << "calling: ";
	print(graph2);
	cout << "other: ";
	print(moveGraph);
	cout << "-After-" << endl;
	graph2 = move(moveGraph);
	cout << "calling: ";
	print(graph2);
	cout << "other: ";
	print(moveGraph);
	cout << endl;

	cout << "TESTING MOVE ASSIGNMENT (ASSIGN LESS VTXS)" << endl; 
	cout << "-Before-" << endl;
	cout << "calling: ";
	print(graph2);
	cout << "other: ";
	print(moveGraph);
	cout << "-After-" << endl;
	graph2 = move(moveGraph);
	cout << "calling: ";
	print(graph2);
	cout << "other: ";
	print(moveGraph);
	cout << endl;

	AdjListGraph * destGraph = new AdjListGraph(7);
	destGraph->createGraph(data);
	cout << "DESTRUCTOR" << endl; 
	cout << "-Before-" << endl;
	print(*destGraph);
	cout << "-After-" << endl;
	delete destGraph;
	print(*destGraph);
	destGraph = nullptr;
	cout << endl;


	cout << "INSERT VERTEX" << endl; 
	cout << "-Original-" << endl;
	print(copyGraph);
	cout << "Adding vertex H (with successors A and C)" << endl;
	copyGraph.insertVertex("H", vector<string>(), { "A", "C" });
	print(copyGraph);
	cout << "Adding vertex I (with predecessors B and D)" << endl;
	copyGraph.insertVertex("I", { "B", "D" }, vector<string>());
	print(copyGraph);
	cout << "Adding vertex J (with predecessors E and G and successors F and H)" << endl;
	copyGraph.insertVertex("J", { "E", "G" }, { "F", "H" });
	print(copyGraph);
	cout << "Attempting to add vertex J again" << endl;
	copyGraph.insertVertex("J", { "E", "G" }, { "F", "H" });
	print(copyGraph);
	cout << "Adding verticies K, L, M, and N (no predecessors or successors)" << endl;
	copyGraph.insertVertex("K", vector<string>(), vector<string>());
	copyGraph.insertVertex("L", vector<string>(), vector<string>());
	copyGraph.insertVertex("M", vector<string>(), vector<string>());
	copyGraph.insertVertex("N", vector<string>(), vector<string>());
	print(copyGraph);
	cout << "Attempting to add vertex O (already at max vertices)" << endl;
	copyGraph.insertVertex("O", vector<string>(), vector<string>());
	print(copyGraph);
	cout << endl;


	cout << "TRAVERSE" << endl; 
	cout << "Graph to traverse:" << endl;
	print(copyGraph);
	cout << "Traversing: ";
	vector<string> travGraphVect = copyGraph.traverse();
	for (string vtx : travGraphVect) cout << vtx << " ";
	cout << endl;


	cout << "EMPTY GRAPH" << endl; 
	cout << "-Before-" << endl;
	print(copyGraph);
	cout << "-After-" << endl;
	copyGraph.emptyGraph();
	print(copyGraph);
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}

void print(const AdjListGraph& graph)
{
	cout << graph << endl 
		<< "Number of vertices= " << graph.getNumVerticies()
		<< "Capacity= " << graph.getCapacity() << endl
		<< "Memory= " << &graph << endl;
}