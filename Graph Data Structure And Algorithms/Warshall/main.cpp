#include <fstream>
#include <iostream>

using namespace std;
ifstream f("in");
ofstream g("out");

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
                    h[i][contM]=h[j][contM]=1;
                    contM++;
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
            if (h[i][j]==1 && x==0)
                x=i;
            else
                if(h[i][j]==1 && y==0)
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
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
}

void afisareDistanta(int n,int a[100][100])
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

void noduriIzolate(int n, int a[100][100])
{
    int i,j,ver=0;
    for (i=1;i<=n;i++)
    {
        int ok=1;
        for (j=1;j<=n;j++)
            if(a[i][j]!=0)
                ok=0;
        if(ok==1)
        {
            cout<<"Nodul "<<i<<" este izolat"<<endl;
            ver=1;
        }

    }
    if(ver==0)
        cout<<"Nu sunt noduri izolate!"<<endl;
}

int grafRegular(int n, int a[100][100])
{
    int b[100];
    int i,j,o=1;
    for (i=1;i<=n;i++)
    {
        int s=0;
        for (j=1;j<=n;j++)
            s=s+a[i][j];
        b[o++]=s;
    }
    for (i=1;i<n;i++)
        if(b[i]!=b[i+1])
    {
        cout<<"Nu este graf regular!"<<endl;
        return 0;
    }
    cout<<"Este graf regular"<<endl;
    return 0;
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

void warshall(int n,int a[100][100])
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
    {
        if(a[i][j]>a[i][k]+a[j][k])
            a[i][j]=a[j][i]=a[i][k]+a[j][k];
    }
}

void verifConex(int n,int a[100][100])
{
    int i,j;
    int ok=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==100)
                ok=0;
    if(ok==1)
        cout<<"Graful este conex!"<<endl;
    else
        cout<<"Graful nu este conex!"<<endl;
}

int main()
{
    citire(noduri,cont);
    muchii=cont/2+1;
    listaAdiacenta(noduri,cont);

    int com;
    while(1)
    {
        cout<<endl;
        cout<<"Alegeti comanda:"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"1.Afisare matrice adiacenta"<<endl;
        cout<<"2.Afisare noduri izolate"<<endl;
        cout<<"3.Este graf regular?"<<endl;
        cout<<"4.Matricea distantelor"<<endl;
        cout<<"5.Este graf conex?"<<endl;

        cin>>com;
        if (com==0)
            return 0;
        if(com==1)
            afisareAdiacenta(noduri,a);
        if(com==2)
            noduriIzolate(noduri,a);
        if(com==3)
            grafRegular(noduri,a);
        if(com==4)
        {
            int cont=0;
            int x;
            int c[100][100];
            initM(noduri,c);

            cout<<"Dati ponderi pentru muchii:"<<endl;
            for(int i=1;i<=muchii;i++)
            {
                cout<<"Pentru muchia "<<lista[cont]<<" "<<lista[cont+1]<<" ";
                cin>>x;
                c[lista[cont]][lista[cont+1]]=c[lista[cont+1]][lista[cont]]=x;
                cont=cont+2;
            }
            warshall(noduri,c);
            afisareDistanta(noduri,c);
        }
        if(com==5)
        {
            int d[100][100];
            int cont=0;
            initM(noduri,d);

            for(int i=1;i<=muchii;i++)
            {
                d[lista[cont]][lista[cont+1]]=d[lista[cont+1]][lista[cont]]=1;
                cont=cont+2;
            }
            warshall(noduri,d);
            verifConex(noduri,d);
        }

    }
    return 0;
}
