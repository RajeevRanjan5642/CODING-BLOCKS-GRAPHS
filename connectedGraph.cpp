#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph
{
    map<int, list<int>> l;

public:
    void addEdge(int src, int dest)
    {
        l[src].push_back(dest);
        l[dest].push_back(src);
    }
    void dfsHelper(int src, map<int, bool>&visited)
    {
        visited[src] = true;
        for (int nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }
    int dfs()
    {
        map<int, bool> visited;
        for (auto pair : l)
        {
            int node=pair.first;
            visited[node] = false;
        }
        int cnt=0;
        for(auto pair:l){
            int node=pair.first;
            if(!visited[node]){
                cnt++;
                dfsHelper(node, visited);
            }
        }
        return cnt;
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,9);
    cout<<g.dfs()<<endl;
}