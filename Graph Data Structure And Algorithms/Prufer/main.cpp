#include <iostream>
#include <fstream>

using namespace std;
ifstream f("in");

int adiac[100][100],lista[100],N,M,A[100][100];
int viz[100],parinti[100],coada[100],k=0;
int p[100],d[100];
bool inCoada[100];
int D[100][100],cost[100][100];
int inchidereTr[100][100];
int pruf[100],decodificare[100][100];

void citesteLista()
{
    f>>N;
    int i=0;
    int x;
    while(f>>x)
        lista[++i]=x;
    M=i/2;
}

void listaAdiac()
{
    for(int i=1;i<=M*2;i+=2)
        A[lista[i]][lista[i+1]]=cost[lista[i]][lista[i+1]]=cost[lista[i+1]][lista[i]]=1;
}

void afisMatrice(int adiac[100][100])
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            cout<<adiac[i][j]<<" ";
        cout<<endl;

    }
}

int existaNoduri(int a[100][100])
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(a[i][j]==1)
                return 1;
    return 0;
}

int parinteFrunza(int a[100][100],int i)
{
    int k=0,w=0,par=0;
    for(int j=1;j<=N;j++)
    {
        if(a[i][j]==1)    ///i nu e frunza
            k++;
        if(a[j][i]==1)    ///i nu e nod izolat, ii stim acum parintele
        {   w++;
            par=j;}
    }
    if(k==0 && w!=0)return par;
    else return 0;
}

int frunzaMinima(int a[100][100])
{
    int frMin=N;
    for(int i=1;i<=N;i++)
        if(parinteFrunza(a,i)!=0 && i<frMin)
            frMin=i;

    return frMin;
}

void prufer(int a[100][100])
{
    k=0;
    //while(existaNoduri(a)==1)
    for(int i=1;i<N;i++)
    {
        int fru=frunzaMinima(a);
        int parinte=parinteFrunza(a,fru);
        pruf[++k]=parinte;
        a[parinte][fru]=0;
    }
}

int celMaiMic(int st,int dr)
{
    for(int i=1;i<=N;i++)
    {
        int k=0;
        for(int j=st;j<=dr;j++)
            if(i==pruf[j])
                k++;
        if(k==0)
            return i;
    }
    return 0;
}

void decodificarePrufer()
{
    int st=1,dr=N-1;
    for(int i=1;i<=N-1;i++)
    {
        int x=pruf[st];
        int y=celMaiMic(st,dr);
        decodificare[x][y]=1;

        st++;
        dr++;
        pruf[dr]=y;
    }
}

void afisareLista(int lista[100],int N)
{
    for(int i=1;i<=N;i++)
        cout<<lista[i]<<" ";
}

int main()
{
    citesteLista();
    listaAdiac();
    prufer(A);
    afisareLista(pruf,N-1);
    decodificarePrufer();
    cout<<endl<<endl;
    afisMatrice(decodificare);

    return 0;
}
