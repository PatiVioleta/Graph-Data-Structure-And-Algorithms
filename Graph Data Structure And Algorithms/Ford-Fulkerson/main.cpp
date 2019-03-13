#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in");

int A[100][100],N,M,viz[100],path[100],parent[100];

void citireMuchii(int &N,int &M)
{
    f>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int x,y,cost;
        f>>x>>y>>cost;
        A[x][y]=cost;
    }
}

void afisareMatrice(int A[100][100])
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

void initVizPar()
{
    for(int i=1;i<=N;i++)
        viz[i]=0,parent[i]=0;
}

int PATH(int sursa,int destinatie)
{
    int st=1,dr=1;
    path[st]=sursa;
    viz[sursa]=1;
    parent[sursa]=0;

    while(st<=dr)
    {
        for(int i=1;i<=N;i++)
            if(A[path[st]][i]!=0 && !viz[i])
            {
                dr++;
                path[dr]=i;
                parent[i]=path[st];
                viz[i]=1;
            }
        st++;
    }
    return (viz[destinatie]==1);
}

void initPath()
{
    int i=0;
    while(path[i]!=0)
    {
        path[i]=0;
        i++;
    }
}

void afisarePath(int s,int t)
{
    cout<<endl;
    if(s==t)
        cout<<s<<" ";
    else
        if(parent[t]==0)
            cout<<"nu e drum";
    else
    {
        afisarePath(s,parent[t]);
        cout<<t<<" ";
    }
}

int main()
{
    citireMuchii(N,M);
    //afisareMatrice(A);

    initVizPar();
    initPath();

    int max_flow=0;

    while(PATH(1,4))
    {
        int minP=INT_MAX;
        for (int v=4; v!=1; v=parent[v])
        {
            int u = parent[v];
            minP = min(minP, A[u][v]);
        }

        for (int v=4; v != 1; v=parent[v])
        {
            int u = parent[v];
            A[u][v] -= minP;
            A[v][u] += minP;
        }

        max_flow+=minP;
        initVizPar();
        initPath();
    }
    cout<<"Flux: "<<max_flow<<endl;
    return 0;
}
