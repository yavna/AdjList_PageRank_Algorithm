#include <iostream>
#include "adjacencylist.h"

int main() {
    // template from project 2 handout
    // getting user input
    int no_of_lines, power_iterations;
    std::string from, to;

    std::cin >> no_of_lines;
    std::cin >> power_iterations;

    // builds the graph
    AdjacencyList graph;

    for (int i = 0; i < no_of_lines; i++) {
        std::cin >> from >> to;
        graph.InsertEdge(from, to);
    }

    // performs page rank calculations and prints them out
    graph.PageRank(power_iterations);

    return 0;
}