#include <fstream>
#include <iostream>
using namespace std;
ifstream f("in");
ofstream g("out");

int a[100][100],noduri,x,y,i,j,lista[100],cont,muchii,matr[100][100];
//a-lista adiacenta

void citire(int &noduri,int &cont)
{
    cont=0;
    f>>noduri;
    while(f>>x)
    {
        lista[cont++]=x;
    }
    cont--;
}

void listaAdiacenta(int noduri,int cont)
{
    int x=0;
    int y=1;
    for (i=1;i<=cont/2+1;i++)
    {
        a[lista[x]][lista[y]]=a[lista[y]][lista[x]]=1;
        x=x+2;
        y=y+2;
    }
}


void afisareAdiacenta(int n,int a[100][100])
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }
}

void afisareVector(int n, int lista[100])
{
    for(int i=1;i<=n;i++)
        g<<lista[i]<<" ";
}

void initVector(int lista[100],int n)
{
    int i;
    for (i=1;i<=n;i++)
        lista[i]=0;
}

void initPoz(int n,int lin, int lista[100])
{
    for(int i=1;i<=n;i++)
        matr[lin][i]=lista[i];
}

void DFS(int n,int vf, int lista[100])
{
    lista[vf]=1;
    for(int i = 1 ; i<=n ; i++ )
        if(a[vf][i]==1 && lista[i]==0)
            DFS(n,i,lista);
}

int main()
{
    citire(noduri,cont);
    muchii=cont/2+1;
    listaAdiacenta(noduri,cont);
    for (i=1;i<=noduri;i++)
    {
        initVector(lista,noduri);
        DFS(noduri,i,lista);
        initPoz(noduri,i,lista);
    }
    g<<"Matricea inchiderii tranzitive:"<<endl<<endl;
    afisareAdiacenta(noduri,matr);

    return 0;
}
