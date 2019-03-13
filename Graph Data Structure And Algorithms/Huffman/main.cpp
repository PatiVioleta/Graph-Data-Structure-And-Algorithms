#include <fstream>
#include <iostream>
#include  <queue>
#include <cstring>
using namespace std;
ifstream f("in");
ofstream g("out");

char s[100],copie[100];
int k,nrCaractere;

struct NOD{
char ch='*';
int st=-1;
int dr=-1;
int fr=0;}nod[100];

struct compara{ bool operator()(NOD x, NOD y) {return x.fr > y.fr;}};
priority_queue<NOD, vector<NOD>, compara> Q;

void noduriInitiale(int &k)
{
    f.getline(s,100);      ///s sirul de caractere
    k=0;               ///nr de noduri din graf
    strcpy(copie,s);
    for(int i=0;i<strlen(s);i++)
    {
        char curent=s[i];
        int aparitii=0;
        for(int j=0;j<strlen(s);j++)
            if(s[j]==curent)
            {
                aparitii++;
                strcpy(s+j,s+j+1);
                j--;
            }
        nod[k].ch=curent;
        nod[k].fr=aparitii;
        Q.push(nod[k]);
        k++;
        i--;
    }
}

void afisareNoduri()
{
    for(int i=0;i<k;i++)
        cout<<"nodul cu cifra "<<nod[i].ch<<" aparitii: "<<nod[i].fr<<" st: "<<nod[i].st<<" dr: "<<nod[i].dr<<endl;
}

void afisareNod(NOD i)
{
    cout<<"continut "<<i.ch<<" fr: "<<i.fr<<" st: "<<i.st<<" dr: "<<i.dr<<endl;
}

void afisareCoada()
{
    while(!Q.empty()) {
        cout << Q.top().ch << " "<<Q.top().fr<<endl;
        Q.pop();
    }
}

int cautaNod(NOD x)
{
    for(int i=0;i<k;i++)
        if(nod[i].ch==x.ch && nod[i].dr==x.dr && nod[i].st==x.st && nod[i].fr==x.fr)
            return i;
}

void huffman(int &k)
{
    k--;
    for(int i=1;i<nrCaractere;i++)
    {
        k++;
        NOD x,y;
        x=Q.top();
        Q.pop();
        y=Q.top();
        Q.pop();

        nod[k].st=cautaNod(x);
        nod[k].dr=cautaNod(y);
        nod[k].fr=x.fr+y.fr;

        Q.push(nod[k]);
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout<<arr[i];

    cout<<endl;
}

void printCodes(int root, int arr[], int top)
{
    if (nod[root].st!=-1)
    {
        arr[top] = 0;
        printCodes(nod[root].st, arr, top + 1);
    }

    if (nod[root].dr!=-1)
    {
        arr[top] = 1;
        printCodes(nod[root].dr, arr, top + 1);
    }

    if (nod[root].dr==-1 && nod[root].st==-1)
    {
        cout<<"root "<<root<<" car "<<nod[root].ch<<": ";
        printArr(arr, top);

        char cod[100];
        strcpy(cod,"");
        for(int j=0;j<top;j++)
        {
            if(arr[j]==1)
                strcat (cod,"1");
            else
                strcat(cod,"0");
        }

        char* p;
        char aux[100];
        p=strchr(copie, nod[root].ch);
        while (p)
        {
            strcpy (aux, cod);  //aux e codul
            strcat (aux, p+1);
            strcpy(p, aux);
            p=strchr(p+strlen(cod), nod[root].ch);
        }
        //cout<<copie<<endl;
    }
}

int main()
{
    noduriInitiale(k);
    //afisareNoduri();
    //afisareCoada();

    nrCaractere=k;
    huffman(k);
    cout<<endl;
    k++;
    //afisareNoduri();
    int arr[100];
    printCodes(10,arr,0);


    cout<<endl<<copie<<endl;
    g<<copie;

    return 0;
}
