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
struct compara{ bool operator()(int x, int y){ return D[x] > D[y];}};
priority_queue<int, vector<int>, compara> Coada;

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
        D[i] = oo;
        P[i]=0;
    }
    D[nodStart] = 0;
}

void Relax_Actualiz(int nodCurent,int vecin, int cost)
{
    if(D[nodCurent] + cost < D[vecin])
            {
                D[vecin]=D[nodCurent] + cost;
                P[vecin]=nodCurent;

                if(InCoada[vecin] == false)                //DACA NU E IN COADA
                {
                    Coada.push(vecin);                     //IL PUNEM IN COADA
                    InCoada[vecin] = true;
                }
            }
}

void Dijkstra(int nodStart)
{
    Initializare(N,nodStart);
    int nodCurent=nodStart;

    Coada.push(nodCurent);      //PUNEM NODUL IN COADA
    InCoada[nodCurent] = true;

    while(!Coada.empty())      //CAT TIMP COADA NU E GOALA
    {
        for(int i=0; i<G[nodCurent].size(); i++)    //LUAM PE RAND TOTI VECINII NODULUI CURENT
        {
            int vecin = G[nodCurent][i].first;
            int cost = G[nodCurent][i].second;

            Relax_Actualiz(nodCurent,vecin,cost);
        }

        nodCurent=Coada.top();    //SCOATEM NODUL CURENT
        Coada.pop();
        InCoada[nodCurent] = false;
    }
}

void afisare(){
    for(int i = 1; i <= N; i++)
        cout << D[i] << ' ';
    cout<<endl;
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
    cout<<"Nod start: ";
    cin>>nodStart;

    Citeste();
    Dijkstra(nodStart);
    //afisare();

    cout<<"Nod final: ";cin>>nodFinal;
    drum(P,nodStart,nodFinal);
}
