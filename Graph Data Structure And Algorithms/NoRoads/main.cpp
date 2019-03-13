#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in");

int coada[100],viz[100],lista[100],N,M,A[100][100],sf,st;

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
        A[lista[i]][lista[i+1]]=1;
}

void coadaVecini(int nod,int nodF)
{
    st=1;
    sf=1;
    coada[st]=nod;
    viz[nod]=1;

    while(st<=sf)
    {
        for(int i=1;i<=N;i++)
            if(A[coada[st]][i] && !viz[i] && coada[st]!=nodF)
            {
                sf++;
                coada[sf]=i;
            }
        if(coada[st]!=nodF)
            viz[coada[st]]=1;
        st++;
    }
}

int NrDrumuri(int nodF)
{
    int k=0;
    for(int i=1;i<=sf;i++)
        if(coada[i]==nodF)
            k++;
    return k;
}

void afisVector(int v[100])
{
    for(int i=1;i<=sf;i++)
        cout<<v[i]<<" ";
}

int main()
{
    int nodS,nodF;
    citire();
    listaAdiac();
    cout<<"Nod start: ";
    cin>>nodS;
    cout<<"Nod final: ";
    cin>>nodF;
    coadaVecini(nodS,nodF);
    //afisVector(coada);
    cout<<"Sunt "<<NrDrumuri(nodF)<<" drumuri diferite";
    return 0;
}
