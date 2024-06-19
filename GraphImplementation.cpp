#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "vertex " << i << "->";
            for (int nbr : l[i])
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph gr(4);

    gr.addEdge(0, 1);
    gr.addEdge(0, 2);
    gr.addEdge(2, 3);
    gr.addEdge(1, 2);

    gr.print();

    return 0;
}