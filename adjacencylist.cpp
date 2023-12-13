#include "adjacencylist.h"
#include <iomanip>
#include <map>

void AdjacencyList::InsertEdge(const string& from, const string& to) {
    // if to or from vertex not present add vertex (from Aman's slides)
    if (graph.find(from) == graph.end()) {
        graph[from] = {};
    }

    if (graph.find(to) == graph.end()) {
        graph[to] = {};
    }

    // update out-degree, in-degree
    graph[from].second += 1;
    graph[to].first.push_back(from);
}

void AdjacencyList::PowerIteration(int n) {
    for (int i = 1; i < n; i ++) {
        // hold page rank temporarily to update the ranks
        map<string, double> updatedPageRanks;
        updatedPageRanks = pageRanks;
        // iterates over each page (vertex) in the graph
        for (const auto &page: graph)  {
            double sum = 0.0;
            // iterates over each out-degree associated with vertex
            for (const auto &edge : page.second.first) {
                // formula: rank(i) = rank(j)/outDegree(j) + rank(k)/outDegree(k) + rank(L)/outDegree(L) …
                sum += (1.0 / graph[edge].second) * pageRanks[edge];
            }
            // update ranks
            updatedPageRanks[page.first] = sum;
        }
        pageRanks = updatedPageRanks;
    }
}

void AdjacencyList::PageRank(int n) {
    // initialize page ranks as 1 / (number of vertices in the graph)
    for (const auto& vertex : graph) {
        pageRanks[vertex.first] = 1.0 / graph.size();
    }

    PowerIteration(n);

    // print out ranks
    for (const auto& vertex : pageRanks) {
        cout << setprecision(2) << fixed << vertex.first << " " << vertex.second << "\n";
    }

}