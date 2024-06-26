#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Graph
{

    list<int> *l;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }
    void topological_sort()
    {
        int *indegree = new int[v];
        for (int i = 0; i < v; i++)
        {
            indegree[i] = 0;
        }
        for (int i = 0; i < v; i++)
        {
            for (int nbr : l[i])
            {
                indegree[nbr]++;
            }
        }
        // bfs
        // 1. find node with indegree 0
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.topological_sort();
}
