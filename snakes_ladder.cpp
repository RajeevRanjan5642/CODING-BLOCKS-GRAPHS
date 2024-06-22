// Problem Statement : Minimum Number of Dice Throws Required to reach the destination 36 starting from the source. Find the shortest path as well.

#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <climits>
using namespace std;

template <typename T>
class Graph
{
    // use hashmap for creating adjacency list
    map<T, list<T>> l;

public:
    void addEdge(T src, T dest)
    {
        l[src].push_back(dest);
        // l[dest].push_back(src);
    }
    int bfs(T src, T dest)
    {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;

        q.push(src);

        // initially all nodes have infinite distance except source node
        for (auto nodePair : l)
        {
            T node = nodePair.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;
        parent[src] = src;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (T nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }

        for (auto nodePair : l)
        {
            T node = nodePair.first;
            int d = dist[node];
        }

        T temp = dest;
        while (temp != src)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << src << endl;
        return dist[dest];
    }
};

int main()
{

    int board[50] = {0};
    board[2] = 13;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;

    for (int i = 1; i < 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36, 36);
    cout << g.bfs(1, 36) << endl;
    return 0;
}