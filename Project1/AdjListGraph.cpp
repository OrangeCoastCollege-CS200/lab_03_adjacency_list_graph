
#include <iostream>
#include "AdjListGraph.h"

	//default constructor
AdjListGraph::AdjListGraph() {
	capacity = DEFAULT_CAPACITY;
	numVerticies = 0;
	verticies = new string[capacity]();
	graph = new AnyList*[capacity]();
}

	//parameterized constructor
AdjListGraph::AdjListGraph(int newCapacity) {
	numVerticies = 0;
	capacity = 2 * newCapacity;
	verticies = new string[capacity]();
	graph = new AnyList*[capacity]();
}

	//copy constructor
AdjListGraph::AdjListGraph(const AdjListGraph& other) {
	numVerticies = other.numVerticies;
	capacity = other.capacity;

	verticies = new string[capacity]();
	graph = new AnyList*[capacity]();

	for (int i = 0; i < numVerticies; i++) {
		verticies[i] = other.verticies[i];
		graph[i] = new AnyList(*(other.graph[i]));
	}
}

	//move constructor
AdjListGraph::AdjListGraph(AdjListGraph&& other) {
	numVerticies = other.numVerticies;
	capacity = other.capacity;
	verticies = other.verticies;
	graph = other.graph;

	other.numVerticies = 0;
	other.capacity = 0;
	other.verticies = nullptr;
	other.graph = nullptr;
}

	//overloaded copy assignment operator
AdjListGraph& AdjListGraph::operator=(const AdjListGraph& other) {
	if (&other != this) {
		if (capacity != other.capacity) {
			capacity = other.capacity;
			delete[] verticies;
			verticies = new string[capacity]();
		}

		for (int i = 0; i < numVerticies; i++) {
			delete graph[i];
			graph[i] = nullptr;
		}
		delete[] graph;
		graph = new AnyList*[capacity]();

		numVerticies = other.numVerticies;
		for (int i = 0; i < numVerticies; i++) {
			verticies[i] = other.verticies[i];
			graph[i] = new AnyList(*(other.graph[i]));
		}
	}
	else cerr << "Incorrect assignment to self";

	return *this;
}

	//overloaded move assignment operator
AdjListGraph& AdjListGraph::operator=(AdjListGraph&& other) {
	if (&other != this) {
		delete[] verticies;

		for (int i = 0; i < numVerticies; ++i) {
			delete graph[i];
			graph[i] = nullptr;
		}

		delete[] graph;

		numVerticies = other.numVerticies;
		numVerticies = other.numVerticies;
		verticies = other.verticies;
		graph = other.graph;

		other.numVerticies = 0;
		other.capacity = 0;
		other.verticies = nullptr;
		other.graph = nullptr;

	}
	else cerr << "Incorrect assignment to self";

	return *this;
}

ostream& operator<< (ostream& out, const AdjListGraph& printThis) {
	if (printThis.numVerticies == 0) out << "EMPTY";
	else {
		int i = 0;
		for (; i < printThis.numVerticies; i++)
			out << "Vertex: " << printThis.verticies[i] << " -> " << *printThis.graph[i] << endl;
		out << "Vertex:  " << printThis.verticies[i] << " -> " << *printThis.graph[i];

		return out;
	}
}

int AdjListGraph::getNumVerticies() const {
	return numVerticies;
}

int AdjListGraph::getCapacity() const {
	return capacity;
}


void AdjListGraph::createGraph(const vector<vector<string>>& data) {
	if (data.size() <= capacity) {

		numVerticies = data.size();
		for (int vertexNum = 0; vertexNum < numVerticies; vertexNum++) {
			verticies[vertexNum] = data.at(vertexNum).at(0);
			graph[vertexNum] = new AnyList();

			int numOfSuccessors = data.at(vertexNum).size();
			for (int succNum = 1; succNum < numOfSuccessors; succNum++)
				graph[vertexNum]->insertFront(data.at(vertexNum).at(succNum));
		}
	}
	else cerr << "The amount of verticies in the data given is larger than the capacity of the graph";
}

void AdjListGraph::insertVertex(const string& vertex, const vector<string>& predList,
	const vector<string>& succList) {
	if (numVerticies < capacity) {

		bool present = false;
		for (int i = 0; i < numVerticies && !present; i++)
			if (verticies[i] == vertex) present = true;

		if (!present) {
			verticies[numVerticies] = vertex;
			graph[numVerticies] = new AnyList();

			for (string succ : succList)
				graph[numVerticies]->insertFront(succ);

			numVerticies++;

			for (string pred : predList) {

				int predNum = 0;
				while (verticies[predNum] != pred)
					predNum++;

				graph[predNum]->insertFront(vertex);
			}
		}
		else cerr << "Incorrectly attempting to insert a pre-exisiting vertex";
	}
	else cerr << "Incorrectly trying to insert a vertex into a saturated graph";
}

void AdjListGraph::emptyGraph() {
	for (int i = 0; i < numVerticies; ++i)
	{
		verticies[i] = "";
		delete graph[i];
		graph[i] = nullptr;
	}

	numVerticies = 0;
}
AdjListGraph::~AdjListGraph() {
	capacity = 0;
	delete[] verticies;
	verticies = nullptr;
	for (int i = 0; i < numVerticies; i++) {
		delete graph[i];
		graph[i] = nullptr;
	}

	delete[] graph;
	graph = nullptr;
	numVerticies = 0;
}