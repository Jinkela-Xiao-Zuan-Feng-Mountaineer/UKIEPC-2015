#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    double g,D[4],t;
    cin>>N>>g;
    for(int i=0;i<N;++i)
    {
        cin>>D[i]>>t;
        t = acos(-1.0)/180*t;
        D[i]*=cos(t);
    }
    for(int i=N-2;i>=0;--i)
    {
        D[i]+=D[i+1];
    }
    for(int i=0;i<N;++i)
    {
        printf("%.9f\n",sqrt( 2*g*D[i] ));
    }
}

