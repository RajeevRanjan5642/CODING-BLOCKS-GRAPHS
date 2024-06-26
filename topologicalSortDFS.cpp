#include <iostream>
#include <map>
#include <list>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
    }
    void dfs_helper(T node, map<T, bool> &visited, list<T> &ordering)
    {
        visited[node] = true;
        for (T nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(node);
    }
    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }

        for (auto p : l)
        {
            T node = p.first;
            
            if (!visited[node])
            {
                dfs_helper(node, visited, ordering);
            }
        }

        for (T node : ordering)
        {
            cout << node << " ";
        }
    }
};

int main()
{
    Graph<string>g;
    g.addEdge("Python","DataPreprocessing");
    g.addEdge("Python","PyTorch");
    g.addEdge("Python","ML");
    g.addEdge("DataPreprocessing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("DL","FaceRecognition");
    g.addEdge("dataset","FaceRecognition");
    g.dfs();
}