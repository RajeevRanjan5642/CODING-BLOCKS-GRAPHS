#include <iostream>
#include<queue>
#include <map>
#include<list>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> mp;

public:
    void addEdge(int x, int y)
    {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void bfs(T src){
        map<T,bool>visited;
        queue<T>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            for(int nbr:mp[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }


};

int main()
{
    Graph<int>gr;
    gr.addEdge(0,1);
    gr.addEdge(0,3);
    gr.addEdge(1,2);
    gr.addEdge(2,3);
    gr.addEdge(3,4);
    gr.addEdge(4,5);
    gr.bfs(0);
}