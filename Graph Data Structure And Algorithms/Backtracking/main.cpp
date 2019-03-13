#include<iostream>

using namespace std;

int st[20],n;



void tipar()

{for(int i=1;i<=n;i++)

    cout<<st[i]<<' ';

cout<<endl;}





int valid(int k)

{ for(int i=1;i<=k-1;i++)

 if (st[i]==st[k])

       return 0;

 return 1;}



void back(int k)

{for(int i=1;i<=n;i++)

       {st[k]=i;

        if (valid(k))

                if(k==n)

                        tipar();

                else

                   back(k+1);

          }

}



int main()

{

cout<<"n=";

cin>>n;

back(1);

return 0;

}
