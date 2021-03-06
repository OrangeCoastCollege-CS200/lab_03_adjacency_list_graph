#ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H

#include<iostream>
#include <string>
#include <vector>
#include "AnyList.h"
using namespace std;


const int DEFAULT_CAPACITY = 11;

class AdjListGraph {
	friend ostream& operator<< (ostream&, const AdjListGraph&);
public:
	AdjListGraph();
		//default constructor

	AdjListGraph(int);
		//parameterized constructor

	AdjListGraph(const AdjListGraph&);
		//copy constructor

	AdjListGraph(AdjListGraph&&);
		//move constructor

	AdjListGraph& operator=(const AdjListGraph&);
		//overloaded copy assignment operator

	AdjListGraph& operator=(AdjListGraph&&);
		//overloaded move assignment operator

	int getNumVerticies() const;

	int getCapacity() const;

	void createGraph(const vector<vector<string>>& data);

	void insertVertex(const string& newVertex, const vector<string>& predList,
		const vector<string>& succList);

	vector<string> traverse() const;

	void emptyGraph();

	~AdjListGraph();
	


private:
	string * verticies;
	AnyList ** graph;
	int numVerticies;
	int capacity;
};

#endif // !ADJLISTGRAPH_H

