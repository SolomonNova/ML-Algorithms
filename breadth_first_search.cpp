/*
 *  How this works:
 *      assing `color` to each vertex
 *      'W' -> represents "white" color, meaning that this state is not pushed in the queue
 *      'G' -> represents "gray" color, meaning that this state is in the queue
 *      'B' -> represents "Black" color, meaning that this state is finished processing and is out of the queue.
 *
 *      'B' is not assigned to any state because they are instantly popped fron the queue 
 */

#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>

struct state
{
    size_t value;
    int depth;
    int parent;
    char color;
};
/////////////////////////////// fucntion declerations ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
inline bool is_final(state s) { return s.value == 3; };
void bfs(std::vector<std::vector<int>> graph, std::vector<state> &statesList);

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    // 0th state is taken as the initial state
    std::vector<state> statesList = 
    {
        {0},
        {1},
        {2},
        {3},
        {4}
    };

    std::vector<std::vector<int>> graph
    {
        {1, 3, 4},
        {0, 4},
        {0, 1, 4},
        {1},
        {2, 3}
    };

    bfs(graph, statesList);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void bfs(std::vector<std::vector<int>> graph, std::vector<state> &statesList)
{
    for (size_t i = 0; i < statesList.size(); i++)
    {
        statesList[i].color  = 'W';
        statesList[i].depth  = -1;
        statesList[i].parent = -1;
    }

    statesList[0].color = 'G';
    statesList[0].depth = 0;

    std::queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (is_final(statesList[current]))
        {
            std::cout << "final state reached\n";
            return;
        }

        for (int v : graph[current])
        {
            if (statesList[v].color == 'W')
            {
                statesList[v].color  = 'G';
                statesList[v].depth  = statesList[current].depth + 1;
                statesList[v].parent = current;

                q.push(v);
            }
        }
    }

    std::cout << "bfs ended\n";
}


