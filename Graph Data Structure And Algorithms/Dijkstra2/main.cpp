#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
ifstream f("in");

const int NMax=100;
const int oo = (1 << 30) - 1;

int N;
int D[NMax];
int P[NMax];
int viz[NMax];
vector < pair <int,int> > G[NMax];
vector<int> terminat[100];

void citire(){
    f>>N;
    int x, y, c;
    while(f>>x>>y>>c){
        G[x].push_back(make_pair(y, c));
    }
}

void Initializare(int Start)
{
    for(int i=1; i<=N; i++)
    {
        D[i] = oo;
        P[i]=0;
        viz[i]=0;
    }
    D[Start] = 0;
    viz[Start]=1;
}

void Relax(int j, int vecin ,int cost)
{
    if(cost + D[j] < D[vecin])
    {
        D[vecin] = cost + D[j];
        P[vecin]=j;
    }
}

int dijkstra(int Start)
{
    queue<int> coada;
    int Curent = Start;

    Initializare(Curent);
    coada.push(Curent);

    while(!coada.empty())
    {
        coada.pop();

        for(int i=0; i<G[Curent].size(); i++)
        {
            int vecin = G[Curent][i].first;
            int cost = G[Curent][i].second;

            coada.push(vecin);
            Relax(Curent,vecin,cost);
        }

        terminat->push_back(Curent);
        if(terminat->size() == N)
            break;

        Curent = coada.front();
    }
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
    citire();
    dijkstra(nodStart);

    //afisare();
    cout<<"Nod final: ";cin>>nodFinal;

    drum(P,nodStart,nodFinal);

    return 0;
}
