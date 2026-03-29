#include <queue>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

template <typename vertexName = char, typename weight = int>

class graph
{
    unordered_map<vertexName, vector<pair<vertexName, weight>>> vertices;

    public:    
        
        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////
        void add_edge(vertexName v, pair<vertexName, weight> p)
        {
            vertices[v].push_back(p);
            vertices[p.first];
        }

        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////
        void print_graph()
        {
            cout << "\ncurrent graph: \n\n";
            cout << "==========================\n\n";

            for (auto &vertex : vertices)
            {
                cout << "vertex: " << vertex.first << "\n";
                cout << "neighbors: \n";

                for (auto &edge : vertex.second)
                {
                    cout << "vertex: " << edge.first << "\t";
                    cout << "weight: " << edge.second;
                    cout << "\n";
                }

                cout << "\n";
            }
            
            cout << "==========================";
        }

        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////
        void dijkstra(vertexName v)
        {
            // priority queue to be implemente
            vector<int> distances(vertices.size());
            vector<char> previous(vertices.size());

            for (auto &distance : distances)
                distance = INT_MAX;

            for (auto &prev : previous)
                prev = '\0';

            distance[v] = 0;
            
        }

};

int main()
{
    graph G;
    G.add_edge('A', {'B', 5});
    G.add_edge('B', {'A', 5});
    G.print_graph();


    return 0;
}

