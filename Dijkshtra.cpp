#include<bits/stdc++.h>
#define SIZE 10010
using namespace std;
struct node
{
    int dest,weight;
    node(int v,int w)
    {
        dest=v;
        weight=w;
    }
};
struct vertice
{
    int vert;
    int weight;
    bool operator<(const vertice &r)const
    {
        return weight>r.weight;
    }
    vertice(int v,int w)
    {
        vert=v;
        weight=w;
    }
    vertice()
    {
        vert=weight=INT_MAX;
    }
};
int Dist[SIZE];
void Initialize(int N)
{
    for(int i=1;i<=N;i++)
    {
        Dist[i]=INT_MAX;
    }
}
int main()
{
    /*********Variable Declarations ************/
    int N,M,i,u,v,weight,S,D,t,flag;
    flag=0;
    vector<node> Adj[SIZE]; //Adjacency List
    priority_queue<vertice>pq;
    //N denotes Number of Vertices and M denotes number of edges
    cin>>N>>M;
    Initialize(N);
    for(i=0;i<M;i++)
    {
        cin>>u>>v>>weight;
        Adj[u].push_back(node(v,weight));
    }
    //S represents Source
    //D represents Destiny
    cin>>S>>D;
    pq.push(vertice(S,0));
    Dist[S]=0;
    while(!pq.empty())
    {
        vertice Q=pq.top();
        pq.pop();
        if(Q.vert==D)
        {
            cout<<"Minimum Distance is:"<<Dist[Q.vert]<<"\n";
            flag=1; //Path Found
            break;
        }
        for(i=0;i<Adj[Q.vert].size();i++)
        {
            if(Dist[Adj[Q.vert][i].dest]>Dist[Q.vert]+Adj[Q.vert][i].weight)
            {
                Dist[Adj[Q.vert][i].dest]=Dist[Q.vert]+Adj[Q.vert][i].weight;
                pq.push(vertice(Adj[Q.vert][i].dest,Dist[Adj[Q.vert][i].dest]));
            }
        }
    }
    for(i=0;i<=N;i++)
        Adj[i].clear();
    while(!pq.empty())
        pq.pop();
    if(!flag)
        cout<<"No path Exists\n";
    return 0;

}
