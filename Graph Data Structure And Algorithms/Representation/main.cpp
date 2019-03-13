#include <fstream>
#include <iostream>

using namespace std;
ifstream f("in");
ofstream g("out.txt");

int a[100][100],noduri,x,y,i,j,lista[100],cont,b[100][100],muchii,h[100][100],lista2[100];
//a-lista adiacenta
//b-adiacenta incidenta
//c-lista incidenta
//d-incidenta adiacenta

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
        x=x+3;
        y=y+3;
    }
}

void afisareAdiacenta(int n,int a[100][100])
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
}

void afisare(int n,int a[100][100])
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            if(a[i][j]==100)
                cout<<"* ";
            else
                cout<<a[i][j]<<" ";
        cout<<'\n';
    }
}

void initM(int n,int a[100][100])
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            if(i!=j)
                a[i][j]=100;
            else
                a[i][j]=0;
    }
}

int main()
{
    citire(noduri,cont);
    muchii=cont/3+1;
    listaAdiacenta(noduri,cont);
    afisareAdiacenta(noduri,a);
    cout<<endl;

    int d[100][100];
    int cont=0;
    initM(noduri,d);

    for(int i=1;i<=muchii;i++)
    {
        d[lista[cont]][lista[cont+1]]=d[lista[cont+1]][lista[cont]]=lista[cont+2];
        cont=cont+3;
    }
    afisare(noduri,d);

    return 0;
}
