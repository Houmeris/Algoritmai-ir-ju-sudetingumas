#include <iostream>

using namespace std;
struct Edge
{
    int virs, kelias, atstumas;
};
struct Graph
{
    int V, E;
    Edge* edge;
};
struct subset
{
    int parent;
    int rank;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
};
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
void Boruvka (struct Graph* graph)
{
    int V = graph->V, E = graph->E;
    Edge *edge = graph->edge;
    struct subset *subsets = new subset[V];
    int *cheapest = new int[V];
    for(int i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
        cheapest[i] = -1;
    }
    int numtrees = V;
    int MSTweight = 0;
    while(numtrees > 1)
    {
        for(int i = 0; i < V; i++)
        {
            cheapest[i] = -1;
        }
        for(int i = 0; i < E; i++)
        {
            int set1 = find(subsets, edge[i].virs);
            int set2 = find(subsets, edge[i].kelias);
            if(set1 == set2)
                continue;
            else
            {
                if(cheapest[set1] == -1 || edge[cheapest[set1]].atstumas > edge[i].atstumas)
                    cheapest[set1] = i;
                if(cheapest[set2] == -1 || edge[cheapest[set2]].atstumas > edge[i].atstumas)
                    cheapest[set2] = i;
            }
        }
        for(int i = 0; i < V; i++)
        {
            if(cheapest[i] != -1)
            {
                int set1 = find(subsets, edge[cheapest[i]].virs);
                int set2 = find(subsets, edge[cheapest[i]].kelias);
                if(set1 == set2)
                    continue;
                MSTweight += edge[cheapest[i]].atstumas;
                cout<<"Briauna "<<edge[cheapest[i]].virs<<" - "<<edge[cheapest[i]].kelias<<" yra viena is MST briaunu"<<endl;
                //Union pašalina vienodas briaunas kad nesikartotu;
                Union(subsets, set1, set2);
                numtrees--;
            }
        }
    }
    cout<<"MST svoris yra "<<MSTweight<<endl;
    return;
}
int find (struct subset subsets[], int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int main()
{
    int V = 4;
    int E = 6;
    /*Šitas Grafas atrodo va taip:
            10
       (0)--------(1)              (0)     (1)
        |  \  /   |                   \   /
       6|   /  \  |15     MST Ats =    / \
        | /4   5 \|                  /4   5\
       (2)--------(3)             (2)-------(3)
            4                           4
    (0, 1) = 10 (0, 2) = 6 (0, 3) = 5 (1, 2) = 4 (1, 3) = 15 (2, 3) = 4
    */
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].virs = 0;
    graph->edge[0].kelias = 1;
    graph->edge[0].atstumas = 10;
    graph->edge[1].virs = 0;
    graph->edge[1].kelias = 2;
    graph->edge[1].atstumas = 6;
    graph->edge[2].virs = 0;
    graph->edge[2].kelias = 3;
    graph->edge[2].atstumas = 5;
    graph->edge[3].virs = 1;
    graph->edge[3].kelias = 3;
    graph->edge[3].atstumas = 15;
    graph->edge[4].virs = 1;
    graph->edge[4].kelias = 2;
    graph->edge[4].atstumas = 4;
    graph->edge[5].virs = 2;
    graph->edge[5].kelias = 3;
    graph->edge[5].atstumas = 4;
    Boruvka(graph);
    return 0;
}
