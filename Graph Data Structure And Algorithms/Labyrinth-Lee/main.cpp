#include <fstream>
#include <iostream>

using namespace std;
ifstream f("in");
ofstream g("out");

int n,x,y,i,j,lista[1000],cont,m,matr[1000][1000],sursa,l[1000],p[1000],labir[1000][1000];
char a[1000][1000];
//a-lista adiacenta

void citireLabirint(int &n,int&m)
{
    f>>n;
    f>>m;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=m/2+1;j++)
            {
                f>>x;
                labir[i][j]=x;
                if (x==-1 && i==n)
                    a[i][j]='F';
                else if (x==-1 && i==1)
                    a[i][j]='S';
                else
                    a[i][j]=x+'0';
                if(j!=m/2+1)
                f>>x;
            }
}

void afisareLabirint(int n,int m,int labir[1000][1000])
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if ((labir[i][j]/100!=0)&&(labir[i][j]/1000==0))
            g<<labir[i][j]<<" ";
            else if ((labir[i][j]/10!=0)&&(labir[i][j]/100==0))
            g<<labir[i][j]<<"  ";
            else if ((labir[i][j]/1!=0)&&(labir[i][j]/10==0))
            g<<labir[i][j]<<"   ";
        }
        g<<'\n';
    }
}
void afisareLabirintch(int n,int m,char labir[1000][1000])
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if ((labir[i][j]/100!=0)&&(labir[i][j]/1000==0))
            g<<labir[i][j]<<" ";
            else if ((labir[i][j]/10!=0)&&(labir[i][j]/100==0))
            g<<labir[i][j]<<"  ";
            else if ((labir[i][j]/1!=0)&&(labir[i][j]/10==0))
            g<<labir[i][j]<<"   ";
        }
        g<<'\n';
    }
}

//parcurgere labirint
void lee(int i,int j,int n)
{
    if(labir[i][j]==0)
    {
        labir[i][j]=n;
        n++;
        lee(i+1,j,n);
        lee(i,j+1,n);
        lee(i-1,j,n);
        lee(i,j-1,n);
    }
}

void drum(int n, int m)
{
    int x;

    for(int i=1;i<=m;i++)
        if (a[n][i]=='F')
            x=i;

    int i=n-1,j=x;
    while (labir[i][j]!=2)
    {
        a[i][j]='*';
        if((labir[i][j+1]==labir[i][j]-1)&&(labir[i][j+1]!=1))
        {
            j=j+1;
        }
    else if((labir[i][j-1]==labir[i][j]-1)&&(labir[i][j-1]!=1))
    {
        j=j-1;
    }
    else if((labir[i+1][j]==labir[i][j]-1)&&(labir[i+1][j]!=1))
    {
        i=i+1;
    }
    else if((labir[i-1][j]==labir[i][j]-1)&&(labir[i-1][j]!=1))
    {
        i-=1;
    }
    }
    a[i][j]='*';
}
int main()
{
    citireLabirint(n,m);
    lee(2,23/2+1,2);
    drum(n,m/2+1);
    afisareLabirintch(n,m/2+1,a);


    return 0;
}
