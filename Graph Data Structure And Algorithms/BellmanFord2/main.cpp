#include    <iostream>
#include    <fstream>
#include    <queue>
#include    <vector>

using namespace std;
ifstream f("in");

const int NMax = 100;
const int oo = (1 << 30);

int N;
int D[NMax];
int P[NMax];
bool InCoada[NMax];
vector < pair <int,int> > G[NMax];

void afisare();

void Citeste(){
    f>>N;
    int x, y, c;
    while(f>>x>>y>>c)
        G[x].push_back(make_pair(y, c));
}

void Initializare(int N,int nodStart)
{
    for(int i = 1; i <= N; ++i)
    {
        D[i]=oo;
        P[i]=0;
    }
    D[nodStart] = 0;
}

void Relax(int j, int vecin ,int cost,int &ok)
{
    if(cost + D[j] < D[vecin])
    {
        D[vecin] = cost + D[j];
        P[vecin]=j;
        ok=1;
    }
}

int BellmanFord(int nodStart)
{
    int ok;
    Initializare(N,nodStart);

    for(int i = 1; i <= N-1; i++)
    {
       ok=0;
       for(int j = 1; j <= N; j++)
            for(int k = 0; k < G[j].size(); k++)
            {
                int vecin = G[j][k].first;
                int cost = G[j][k].second;
                Relax(j,vecin,cost,ok);
            }
    }

    return ok; //DACA OK=1 AVEM CIRCUIT NEGATIV
}

void afisare(){
    for(int i = 1; i <= N; i++)
        cout << P[i] << ' ';
}

void drum(int P[],int S,int F)
{
    if (S==F)
        cout<<S<<" ";
    else
        if (P[F]==0)
            cout<<"Nu exista drum";
    else
    {
        drum(P,S,P[F]);
        cout<<F<<" ";
    }
}

int main(){
    int nodStart,nodFinal;

    cout<<"Nod start: ";cin>>nodStart;
    Citeste();

    int ok=BellmanFord(nodStart);
    afisare();
    if(ok==1)
        cout<<"Avem circuit negativ"<<endl;

    cout<<"Nod final: ";cin>>nodFinal;
    drum(P,nodStart,nodFinal);
}

