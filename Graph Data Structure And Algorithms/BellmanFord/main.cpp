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
int DD[100][100];

vector < pair <int,int> > G[NMax];
struct compara{ bool operator()(int x, int y) {return D[x] > D[y];}};
priority_queue<int, vector<int>, compara> Coada;

void afisare_graf_extins();
void afisare_vector(int D[],int N);

void Citeste(){
    f>>N;
    int x, y, c;
    while(f>>x>>y>>c)
        G[x].push_back(make_pair(y, c));
}

void Initializare(int nodStart)
{
    for(int i = 1; i <= N; ++i)
    {
        D[i] = oo;
        P[i]=0;
    }
    D[nodStart] = 0;
    P[nodStart]=0;
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

int BellmanFord(int nodStart)
{
    int ok;
    Initializare(nodStart);

    for(int i = 1; i <= N-1; i++)
    {
       ok=0;
       for(int j = 1; j <= N; j++)
            for(int k = 0; k < (int)G[j].size(); k++)
            {
                int vecin = G[j][k].first;
                int cost = G[j][k].second;
                Relax(j,vecin,cost,ok);
            }
    }

    return ok; //DACA OK=1 AVEM CIRCUIT NEGATIV
}

void Dijkstra(int nodStart)
{
    Initializare(nodStart);
    int nodCurent=nodStart;

    Coada.push(nodCurent);      //PUNEM NODUL IN COADA
    InCoada[nodCurent] = true;

    while(!Coada.empty())      //CAT TIMP COADA NU E GOALA
    {
        for(int i=0; i< (int)G[nodCurent].size(); i++)    //LUAM PE RAND TOTI VECINII NODULUI CURENT
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

void graf_extins()
{
    for( int i=1;i<= N;i++)                  //facem G`
        G[N+1].push_back(make_pair(i, 0));
}

void Johnson()
{
    graf_extins();

    if (BellmanFord(N+1)!=0)
        cout<<"G contine circuit negativ";
    else
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<(int)G[i].size();j++)
            {
                int vecin = G[i][j].first;
               // cout<<i<<" "<<vecin<<endl;
                G[i][j].second += D[i] - D[vecin];
            }
        }

        for(int i=1;i<=N;i++)
        {
            Dijkstra(i);
            //afisare_vector(D,N);

            for(int k=1;k<=N;k++)
            {

                DD[i][k] = D[k];
            }
        }
    }
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

void afisare_vector(int D[],int N)
{
    for(int i = 1; i <= N; i++)
        if(D[i]==oo)
            cout<<"INF"<<' ';
        else
            cout << D[i] << ' ';
    cout<<endl;
}

void afisare_graf_extins()
{
    for(int j = 1; j <= N+1; ++j)
    {
            for(int k = 0; k < G[j].size(); ++k)
            {
                int vecin = G[j][k].first;
                int cost = G[j][k].second;
                cout<<vecin<<" "<<cost<<"       ";
            }
            cout<<endl;
    }
}

void afisare_matrice(int a[100][100],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i][j]==oo)
                cout<<"oo ";
            else
                cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int nodStart,nodFinal;
    //cout<<"Nod start: ";cin>>nodStart;

    Citeste();
    //BellmanFord(nodStart);
    //Dijkstra(nodStart);
    //afisare_vector(D,N);

    Johnson();
    //cout<<"Nod final: ";cin>>nodFinal;
    afisare_matrice(DD,N);
    //drum(P,nodStart,nodFinal);
}
