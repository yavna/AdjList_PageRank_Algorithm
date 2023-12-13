#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class AdjacencyList {
private:
    // implementing the adjacency list using a map of string and pair
    map<string, pair<vector<string>, double>> graph;
    map <string, double> pageRanks;

public:
    AdjacencyList() { }
    ~AdjacencyList() { }
    void InsertEdge(const string& from, const string& to);
    void PowerIteration(int n);
    void PageRank(int n);
};