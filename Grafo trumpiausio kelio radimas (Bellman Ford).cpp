#include <iostream>

using namespace std;
struct Edge
{
    int virs, kelias, atstumas;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
};
int iter = 0;
void BellmanFord(struct Graph* graph, int virs)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for (int i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[virs] = 0;
    for(int i=1; i<=V-1; i++)
    {
        for (int j=0; j<E; j++)
        {
            iter++;
            int u = graph->edge[j].virs;
            int v = graph->edge[j].kelias;
            int weight = graph->edge[j].atstumas;
            if(dist[u] != INT_MAX && dist[i] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i=0; i<E; i++)
    {
        int u = graph->edge[i].virs;
        int v = graph->edge[i].kelias;
        int weight = graph->edge[i].atstumas;
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout<<"Graph contains negative weight cycle"<<endl;
            return;
        }

    }
    cout<<"Virsunes: ";
    for(int i=0; i<V; i++)
        cout<<i<<" ";
    cout<<endl;
    cout<<"Trumpiausi keliai:"<<endl;
    for(int i=0; i<V; i++)
        cout<<"["<<i<<"] "<<"virsune = "<<dist[i]<<endl;
    return;
}
int main()
{
    int V = 6;
    int E = 9;
    // src yra virsune, dest i kuria virsune nukeliauja, o weight atstumas.
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].virs = 0;
    graph->edge[0].kelias = 1;
    graph->edge[0].atstumas = 6;
    graph->edge[1].virs = 0;
    graph->edge[1].kelias = 2;
    graph->edge[1].atstumas = 4;
    graph->edge[2].virs = 0;
    graph->edge[2].kelias = 3;
    graph->edge[2].atstumas = 5;
    graph->edge[3].virs = 1;
    graph->edge[3].kelias = 4;
    graph->edge[3].atstumas = -1;
    graph->edge[4].virs = 2;
    graph->edge[4].kelias = 1;
    graph->edge[4].atstumas = -2;
    graph->edge[5].virs = 2;
    graph->edge[5].kelias = 4;
    graph->edge[5].atstumas = 3;
    graph->edge[6].virs = 3;
    graph->edge[6].kelias = 2;
    graph->edge[6].atstumas = -2;
    graph->edge[7].virs = 3;
    graph->edge[7].kelias = 5;
    graph->edge[7].atstumas = 0;
    graph->edge[8].virs = 4;
    graph->edge[8].kelias = 5;
    graph->edge[8].atstumas = 3;
    BellmanFord(graph, 0);
    cout<<endl;
    cout<<"Is viso "<<iter<<" Iteraciju"<<endl;
    return 0;
}
