#include <fstream>
#include <iostream>

using namespace std;
ifstream f("in");
ofstream g("out");

int a[100][100],noduri,x,y,i,j,lista[100],cont,b[100][100],muchii,h[100][100],lista2[100],l[100],p[100],sursa,u[100],coada[100];
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

void moore(int k)
{
    int st=1,sf=1;

    for (int i=1;i<=noduri;i++)
        if(i!=k)
            l[i]=100;
    l[k]=0;

    coada[1]=k;

    while(st<=sf)
    {
        for(int i=1;i<=noduri;i++)
            if(a[coada[st]][i]==1 && l[i]==100)
                {
                    p[i]=coada[st];
                    l[i]=l[coada[st]]+1;
                    sf++;
                    coada[sf]=i;
                }
        st++;
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

void m_drum(int p[100],int l[100],int v,int u[100])
{
    int k=l[v];
    for(int i=1;i<100;i++)
        u[i]=0;
    u[k]=v;
    while(k!=0)
    {
        u[k-1]=p[u[k]];
        k--;
    }
}

void afisareLista(int noduri,int lista[100])
{
    for(int i=1;i<=noduri;i++)
        cout<<lista[i]<<" ";
}

void afisareLista2(int noduri,int lista[100])
{
    for(int i=0;i<=noduri;i++)
        cout<<lista[i]<<" ";
}

int noduriIzolate(int n, int a[100][100],int nod)
{
    int i,ok=1;
    for (i=1;i<=n;i++)
    {
        if(a[nod][i]!=0)
                ok=0;
    }

        if(ok==1)
            return 1;

    return 0;
}

int main()
{
    citire(noduri,cont);
    muchii=cont/2+1;
    listaAdiacenta(noduri,cont);

    //afisareAdiacenta(noduri,a);
    cout<<endl;
    cout<<"Alegeti nodul sursa: ";
    cin>>sursa;

    if(noduriIzolate(noduri,a,sursa)==1)
    {
        cout<<"Nodul introdus este izolat ";
        cout<<endl;
        return 0;
    }

    moore(sursa);
    cout<<endl;
    cout<<"Lungimile de la sursa la noduri: "<<endl;
    afisareLista(noduri,l);
    cout<<endl;
    cout<<endl;
    cout<<"Lista predecesorilor: "<<endl;
    afisareLista(noduri,p);
    cout<<endl;
    cout<<endl;
    cout<<"Dati un nod final: "<<endl;
    int nod;
    cin>>nod;
    //m_drum(p,l,nod,u);
    //afisareLista2(l[nod],u);
    drum(p,sursa,nod);




    return 0;
}
