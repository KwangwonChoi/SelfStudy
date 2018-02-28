#include "DataStructures.h"

template<typename T>
bool hasRouteBetweenTwoGraph(Graph<T>* grph1, Graph<T>* grph2) {

	if (grph1->hasRouteByDFS(grph2))
		return true;
	if (grph2->hasRouteByDFS(grph1))
		return true;

	return false;
}

int main()
{
	Graph<int>* graph1 = new Graph<int>(1);
	Graph<int>* graph2 = new Graph<int>(2);
	Graph<int>* graph3 = new Graph<int>(3);
	Graph<int>* graph4 = new Graph<int>(4);
	Graph<int>* graph5 = new Graph<int>(5);
	Graph<int>* graph6 = new Graph<int>(6);
	Graph<int>* graph7 = new Graph<int>(7);
	Graph<int>* graph8 = new Graph<int>(8);

	graph1->Link(graph2);
	graph1->Link(graph3);
	graph3->Link(graph1);
	graph2->Link(graph4);
	graph2->Link(graph5);
	graph3->Link(graph5);
	graph6->Link(graph1);
	graph4->Link(graph8);

	if (hasRouteBetweenTwoGraph(graph1, graph6))
		cout << "linked" << endl;

	return 0;
}