#include <iostream>
#include <unordered_map>
#include <iterator>
#include <list>

using namespace std;

class Graph
{
    // Adjacency list
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string x, string y, bool bidir, int wt)
    {
        l[x].push_back({y, wt});
        if (bidir)
            l[y].push_back({x, wt});
    }

    void print()
    {
        unordered_map<string, list<pair<string, int>>>::iterator it;
        for (it = l.begin(); it != l.end(); it++)
        {
            cout << it->first << "->";
            for (auto p : it->second)
            {
                cout << "(" << p.first << "," << p.second << ")";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph gr;

    gr.addEdge("A", "B", true, 20);
    gr.addEdge("B", "D", true, 40);
    gr.addEdge("C", "D", true, 30);
    gr.addEdge("A", "C", true, 10);
    gr.addEdge("A", "D", false, 50);

    gr.print();

    return 0;
}
