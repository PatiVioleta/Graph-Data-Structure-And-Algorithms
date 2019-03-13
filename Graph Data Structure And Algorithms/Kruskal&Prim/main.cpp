#include <iostream>
#include <fstream>
#include  <queue>
using namespace std;
ifstream f("in");

const int oo=(1<<30)-1;

int A[100][100],N,M;
int parent[100],pondere[100];

struct NOD{
int x=-1;
int y=-1;
int cost=0;}nod[100];

struct compara{ bool operator()(NOD x, NOD y) {return x.cost > y.cost;}};
priority_queue<NOD, vector<NOD>, compara> Q,K;

void citireMuchii(int &N,int &M)
{
    f>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int x,y,cost;
        f>>x>>y>>cost;
        A[x][y]=A[y][x]=cost;
        NOD n;
        n.cost=cost;    n.x=x;    n.y=y;
        Q.push(n);
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

int findSet(int i)
{
    if (parent[i] == -1)
        return i;
    return findSet(parent[i]);
}

void Kruskal()
{
    for(int i=1;i<=N;i++)
        parent[i]=-1;

    while ( !Q.empty() )
    {
        NOD e = Q.top();
        Q.pop();

        if ( findSet(e.x) != findSet(e.y) )
        {
            K.push(e);
            parent[findSet(e.x)]=findSet(e.y);
        }
    }
}

void afisareCoada()
{
    cout<<endl;
    while(!K.empty()) {
        cout << K.top().x << " "<<K.top().y<<" "<<K.top().cost<<endl;
        K.pop();
    }
}

void Prim(int start)
{
    int nodS=1;
    //int inCoada[100];

    for(int i=1;i<=N;i++)
    {
        parent[i]=0;
        pondere[i]=oo;
        //inCoada[i]=1;
    }
    pondere[nodS]=0;

    while ( nodS<=N )
    {
        for(int i=1;i<=N;i++)
            if(A[nodS][i]!=0 && A[nodS][i]<pondere[i])
            {
                parent[i]=nodS;
                pondere[i]=A[nodS][i];
            }
        nodS++;
    }
}

void afisareParinti()
{
    cout<<endl;
    for(int i=1;i<=N;i++)
        cout<<parent[i]<<" ";
}

int main()
{
    citireMuchii(N,M);
    //afisareMatrice(A);

    ///*
    Kruskal();
    cout<<"Kruskal "<<endl;
    afisareCoada();
    //*/
    cout<<endl;
    ///*
    Prim(1);
    cout<<"Prim"<<endl<<"Vectorul de parinti: ";
    afisareParinti();
    //*/
    cout<<endl;
    return 0;
}
