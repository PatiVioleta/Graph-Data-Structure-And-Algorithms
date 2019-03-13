#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in");

int st[100],N,M,A[100][100],lista[100],viz[100];

void citire()
{
    f>>N;
    int i,j;
    int k=1;
    while(f>>i>>j)
    {
        lista[k]=i;
        k++;
        lista[k]=j;
        k++;
    }
    M=(k-1)/2;
}

void listaAdiac()
{
    for(int i=1;i<=M*2;i+=2)
        A[lista[i]][lista[i+1]]=A[lista[i+1]][lista[i]]=1;
}

int gradPar()
{
    for(int i=1;i<=N;i++)
    {
        int nr=0;
        for(int j=1;j<=N;j++)
            if(A[i][j]==1)
                nr++;
        if(nr%2!=0)
            return 0;
    }
    return 1;
}

int valid(int k)
{
    if(k==1)
        return true;

    if(A[st[k]][st[k-1]]==0)
        return false;

    for(int i=1;i<=k-2;i++)
        if( st[i]==st[k-1] && st[i+1]==st[k] || st[i]==st[k] && st[i+1]==st[k-1])
            return false;

    return true;
}

int solutie(int k)
{
    if(k<3 || st[1]!=1 || A[st[1]][st[k]]==0 || k!=M)
        return false;
    return true;
}

void tipar(int k)
{
    for(int j=1;j<=k;j++)
        cout<<st[j]<<" ";
    cout<<st[1];
    cout<<endl;
}

void ciclu(int k)
{
     for(int i=1;i<=N;i++)
     {
         st[k]=i;
         if(valid(k))
            {
                if(solutie(k))
                    tipar(k);
                else
                ciclu(k+1);
            }
     }
}

void dfs(int k)
{
    viz[k]=1;
    for(int i=1;i<=N;i++)
        if(A[i][k]==1 && viz[i]==0)
            dfs(i);
}

int grad(int i)
{
    int nr=0;
    for(int j=1;j<=N;j++)
        if(A[i][j]==1)
            nr++;
    return nr;
}

int isConex()
{
    for(int i=1;i<=N;i++)
        if(viz[i]==0 && grad(i)!=0)
            return false;
    return true;
}

int main()
{
    citire();
    listaAdiac();
    dfs(1);
    if(gradPar()==false || isConex()==false)
        cout<<"Nu e eulerian";
    else
        ciclu(1);

    return 0;
}
