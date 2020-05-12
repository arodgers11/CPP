// test_dijkstra.cpp
// c. 2017 Andrew Rodgers

#include <iostream>
#include <fstream>
#include <string>
#include "Digraph.hpp"

using std::ifstream;

//user interface
void UI(Digraph g,std::vector<string> cities){
	system("clear");	//make thing pretty
	int origin,destination;
	for(int i=0;i<g.noVertices();i++)
		cout<<i<<" : "<<cities[i]<<endl;
	cout<<"\nOrigin: ";
	std::cin>>origin;
	cout<<"Destination: ";
	std::cin>>destination;
	cout<<endl;
	cout<<"\n"<<"It is "<<g.dijkstra(origin,destination)<<" miles from "
		<<cities[origin]<<" to "<<cities[destination]<<"\n\n";
}

int main() {
  Digraph g;
  ifstream dataFile;
  int numPoints, p, q, r;
  string city;
  std::vector<string> cities;	//list to hold city names in
  dataFile.open("nqmq.dat");
  dataFile >> numPoints;
  for (int i = 0; i < numPoints; i++) {
	  dataFile >> city;
	  cities.push_back(city);	//adds city to vector lsit of cities for UI since Digraph.vector is protected
	  g.addVertex(city);
  }
  g.resetEdges();
  dataFile >> p;
  dataFile >> q;
  dataFile >> r;
  while (p > -1) {
	  g.addEdge(p, q, r);
	  g.addEdge(q, p, r);
	  dataFile >> p;
	  dataFile >> q;
	  dataFile >> r;
  }
  dataFile.close();
  
  UI(g,cities); //user interface functionality. Prompts for two cities and finds minimum
				//distance between and path between cities
  
  cout << "TEST 1. Los Angeles to Boston" << endl;
  p = g.dijkstra(4, 1);
  cout << "*** Final distance: " << p << " miles." << endl;
  if (p != 2602) cout << "TEST FAILED";
  else cout << "Test passed";
  cout << endl << endl;
  cout << "TEST 2. San Francisco to Miami" << endl;
  p = g.dijkstra(7, 5);
  cout << "*** Final distance: " << p << " miles." << endl;
  if (p != 3056) cout << "TEST FAILED";
  else cout << "Test passed";
  cout << endl << endl;
}
