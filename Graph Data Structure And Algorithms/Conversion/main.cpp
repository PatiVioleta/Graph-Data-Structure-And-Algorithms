#include <fstream>

using namespace std;
ifstream f("in");
ofstream g("out");

int a[100][100],noduri,x,y,i,j,lista[100],cont,b[100][100],muchii,c[100][100],d[100][100],lista2[100];
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
        x=x+2;
        y=y+2;
    }
}

void listaIncidenta(int noduri,int cont)
{
    int x=0;
    int y=1;
    for (i=1;i<=cont/2+1;i++)
    {
        c[lista[x]][i]=c[lista[y]][i]=1;
        x=x+2;
        y=y+2;
    }
}

void adiacentaIncidenta(int noduri,int muchii)
{
    int i,j;
    int contM=1;
    for (i=1;i<=noduri;i++)
        for(j=1;j<=noduri;j++)
            if (i<j && a[i][j]==1)
                {
                    b[i][contM]=b[j][contM]=1;
                    contM++;
                }
}

void incidentaAdiacenta(int noduri,int muchii)
{
    int i,j;
    int x=0,y=0;
    for (j=1;j<=muchii;j++)
    {
        for (i=1;i<=noduri;i++)
        {
            if (c[i][j]==1 && x==0)
                x=i;
            else
                if(c[i][j]==1 && y==0)
                    y=i;
        }
        d[x][y]=d[y][x]=1;
        x=0;
        y=0;
    }
}

void incidentaLista(int noduri,int muchii)
{
    int i,j;
    int cont=0;
    int x=0,y=0;
    for (j=1;j<=muchii;j++)
    {
        for (i=1;i<=noduri;i++)
        {
            if (c[i][j]==1 && x==0)
                x=i;
            else
                if(c[i][j]==1 && y==0)
                    y=i;
        }

        lista2[cont]=x;
        cont++;
        lista2[cont]=y;
        cont++;
        x=0;
        y=0;
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

void afisareIncidenta(int n, int m, int a[100][100])
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }
}

void afisareLista(int muchii,int lista[100])
{
    int i;
    for (i=0;i<=muchii*2-1;i=i+2)
        g<<lista[i]<<" "<<lista[i+1]<<endl;
}

int main()
{
    citire(noduri,cont);
    muchii=cont/2+1;
    g<<"Din lista in adiacenta";
    g<<endl;
    listaAdiacenta(noduri,cont);
    afisareAdiacenta(noduri,a);
    g<<endl;
    g<<"Din adiacenta in incidenta";
    g<<endl;
    adiacentaIncidenta(noduri,muchii);
    afisareIncidenta(noduri,muchii,b);
    g<<endl;
    g<<"Din lista in incidenta";
    g<<endl;
    listaIncidenta(noduri,cont);
    afisareIncidenta(noduri,muchii,c);
    g<<endl;
    g<<"Din incidenta in adiacenta";
    g<<endl;
    incidentaAdiacenta(noduri,muchii);
    afisareAdiacenta(noduri,d);
    g<<endl;
    g<<"Din incidenta in lista";
    g<<endl;
    incidentaLista(noduri,muchii);
    afisareLista(muchii,lista2);

    return 0;
}
