#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in");

int st[100],N,M,A[100][100],lista[100];

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

int valid(int k)
{
    if(k==1)
        return true;

    if(A[st[k]][st[k-1]]==0)
        return false;

    for(int i=1;i<k;i++)
        if( st[i]==st[k])
            return false;

    return true;
}

int solutie(int k)
{
    if(k==1 || st[1]!=1)
        return false;
    return true;
}

void tipar(int k)
{
    for(int j=1;j<=k;j++)
        cout<<st[j]<<" ";
    cout<<endl;
}

void backt(int k)
{
     for(int i=1;i<=N;i++)
     {
         st[k]=i;
         if(valid(k))
            {
                if(solutie(k))
                    tipar(k);
                backt(k+1);
            }
     }
}

int main()
{
    citire();
    listaAdiac();
    backt(1);

    return 0;
}
