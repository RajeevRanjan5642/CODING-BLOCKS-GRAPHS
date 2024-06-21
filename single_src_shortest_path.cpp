// the shortest path is discovered first in level order traversal

#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <climits>
using namespace std;

template <typename T>
class Graph
{
    // use hashmap for creating adjacency list
    map<T, list<T>> l;

public:
    void insert(T src, T dest)
    {
        l[src].push_back(dest);
        l[dest].push_back(src);
    }
    void bfs(T src)
    {
        queue<T> q;
        map<T, int> dist;

        q.push(src);

        // initially all nodes have infinite distance except source node
        for (auto nodePair : l)
        {
            T node = nodePair.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;

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
                }
            }
        }

        for (auto nodePair : l)
        {
            T node = nodePair.first;
            int d = dist[node];
            cout << "Node " << node << " Dist from src " << d << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.insert(0, 1);
    g.insert(0, 3);
    g.insert(1, 2);
    g.insert(2, 3);
    g.insert(3, 4);
    g.insert(4, 5);
    g.bfs(0);
}