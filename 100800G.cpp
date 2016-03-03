#include<bits/stdc++.h>
using namespace std;
bool dp[1005][605]={false};
int use[1005][605]={};
int ud[8]={0};
int m[8],tms;
int ac[8];
void rev(int M,int A)
{
    if(M==0||A==0)return;
    assert(use[M][A]>=0);
    ud[ use[M][A] ]++;
    rev(M-m[use[M][A]],A-ac[use[M][A]]);
}
int main()
{
    dp[0][0]=true;
    memset(use,-1,sizeof(use));
    
    int N,M,A,a,b,c,d;
    string name[8],tmp;
    double mn;
    
    scanf("%d.%d %d.%d %d",&a,&b,&c,&d,&N);
    M=a*100+b;
    A=(c*10+d)*3;
    for(int i=0;i<N;++i)
    {
        cin>>name[i]>>ac[i]>>tmp;
        scanf("%d.%d",&a,&b);mn=a*100+b;
        m[i] = mn;
        ac[i]= ac[i]*30;
        if( tmp == "1/1" )tms=1;
        else if(tmp == "1/2")tms=2;
        else tms=3;
        ac[i]/=tms;
    }
    for(int i=0;i<N;++i)
    {
        for(int j=m[i];j<=M;++j)
            for(int k=ac[i];k<=A;++k)
            {
                //cout<<i<<' '<<j<<' '<<k<<endl;
                if( dp[j-m[i]][k-ac[i]] )
                {
                    use[j][k] = i;
                    dp[j][k] = true;
                }
            }
    }
    if( dp[M][A] )
    {
        rev(M,A);
        for(int i=0;i<N;++i)
            if(ud[i])
                cout<<name[i]<<' '<<ud[i]<<'\n';
    }
    else
    {
        puts("IMPOSSIBLE");
    }
    
}

