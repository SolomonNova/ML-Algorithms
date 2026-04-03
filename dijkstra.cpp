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
            cout << v << "----" << p.second << "----" << p.first << "\n\n";
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
            unordered_map<vertexName, weight> distances;
            unordered_map<vertexName, vertexName> parents;

            for (auto &vertex : vertices)
            {
                distances[vertex.first] = INT_MAX;
                parents[vertex.first] = '\0';
            }
           
            priority_queue
            <
                pair<weight, vertexName>,
                vector<pair<weight, vertexName>>,
                greater<pair<weight, vertexName>>
            > minHeap;
            
            distances[v] = 0;
            minHeap.push({0, v});

            while (!minHeap.empty())
            {
                auto [dist, node] = minHeap.top();
                minHeap.pop();

                if (dist != distances[node])
                    continue;
                
                for (auto &neighbor : vertices[node])
                {
                    vertexName adj = neighbor.first;
                    weight w = neighbor.second;

                    if (distances[adj] > w + dist)
                    {
                        distances[adj] = w + dist;
                        parents[adj] = node;
                        minHeap.push({ distances[adj], adj});
                    }
                }
            }
                
            // printing the parents and ditanecs finally
            for (auto &distance : distances) 
                cout << "distance: " << distance.first << " weight: " << distance.second << "\n";

            cout << "\n";
            
            for (auto &parent : parents)
                cout << "parent of: " << parent.first << " is: " << parent.second << "\n";
        }
};

int main()
{
    graph<> G;

    // A connections
    G.add_edge('A', {'B', 4});
    G.add_edge('A', {'C', 2});
 
    // B connections
    G.add_edge('B', {'A', 4});
    G.add_edge('B', {'C', 1});
    G.add_edge('B', {'D', 5});

    // C connections
    G.add_edge('C', {'A', 2});
    G.add_edge('C', {'B', 1});

    // D connections
    G.add_edge('D', {'B', 2});

    G.dijkstra('A');
    // G.print_graph();
    
    return 0;
}

