// test_dijkstra.cpp
// c. 2017 T. O'Neil, C. Reilly

#include <iostream>
#include <fstream>
#include <string>
#include "Digraph.hpp"

using std::ifstream;

int main() {
  Digraph g;
  ifstream dataFile;
  int numPoints, p, q, r;
  string city;

  dataFile.open("nqmq.dat");
  dataFile >> numPoints;
  for (int i = 0; i < numPoints; i++) {
	  dataFile >> city;
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
