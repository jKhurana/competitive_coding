#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj; // Pointer to the array of list<int>
    Graph(int V);
    void addEdge(int v,int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V]; // an array of list<int>
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=0;
    }

    queue<int> q; // queue for BFS

    q.push(s);
    visited[s]=true;

    //iterator for list<int>
    list<int>::iterator i;

    while(!q.empty())
    {
        s=q.front();
        printf("%d ",s);
        q.pop();

        // now enquqe all the adjacent
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                q.push(*i);
            }
        }
    }
}

// Driver program for checking BFS
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,0);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    cout << "BFS for the above graph which start with certex 2" << endl;
    g.BFS(2);
}

