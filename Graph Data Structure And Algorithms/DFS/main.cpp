#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream f("in");
ofstream g("out");
int coada[100],viz[100],lista[100],N,M,A[100][100],k;

void citire()
{
    f>>N;
    int i,j,k=1;
    while(f>>i>>j)
    {
        lista[k]=i;k++;
        lista[k]=j;k++;
    }
    M=(k-1)/2;
}

void listaAdiac()
{
    for(int i=1;i<=M*2;i+=2)
        A[lista[i]][lista[i+1]]=A[lista[i+1]][lista[i]]=1;
}

void afisVector(int v[100])
{
    for(int i=1;i<=N;i++)
        cout<<v[i]<<" ";
}

void DFS(int nod)
{
    viz[nod]=1;
    coada[k++]=nod;
    for(int i=1;i<=N;i++)
        if(A[nod][i] && !viz[i])
            DFS(i);
}

int main()
{
    int init;
    citire();
    listaAdiac();
    cout<<"nr: ";
    cin>>init;

    k=1;
    DFS(init);
    afisVector(viz);
    cout<<endl;
    afisVector(coada);

    return 0;
}
