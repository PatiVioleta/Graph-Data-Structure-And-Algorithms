#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream f("in");
ofstream g("out");
int coada[100],viz[100],lista[100],N,M,A[100][100];

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

void afisVector(int v[100])
{
    for(int i=1;i<=N;i++)
        cout<<v[i]<<" ";
}

void BFS(int nod)
{
    int st=1;
    int sf=1;
    coada[st]=nod;
    viz[nod]=1;

    while(st<=sf)
    {
        for(int i=1;i<=N;i++)
            if(A[coada[st]][i] && !viz[i])
            {
                sf++;
                coada[sf]=i;
                viz[i]=1;
            }
        st++;
    }
}

int main()
{
    int init;
    citire();
    listaAdiac();
    cout<<"nr: ";
    cin>>init;

    BFS(init);

    afisVector(viz);
    cout<<endl;
    afisVector(coada);

    return 0;
}
