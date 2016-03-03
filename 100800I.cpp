#include<bits/stdc++.h>
using namespace std;

int main()
{
    char hardWord[]={'B','C','D','G','K','N','P','T',
                     'b','c','d','g','k','n','p','t'};
    char end[] = {'a','o','u'};
    bool isHard[128]={false};
    char near[128];
    char neared[128];
    for(int c:hardWord)isHard[c]=true;
    for(int i='A';i<='Z';++i)
    {
        near[i]='B';
        for(int j=0;j<8;++j)
            if( abs(i-hardWord[j]) < abs(i-near[i]) )
                near[i] = hardWord[j];
                
        neared[tolower(i)]=neared[i] = 'a';
        for(int j=0;j<3;++j)
            if( abs(tolower(i)-end[j]) < abs(tolower(i)-neared[i]) )
            {
                neared[i]=neared[tolower(i)]=end[j];
            }
    }
    for(int i='a';i<='z';++i)
    {
        near[i]='b';
        for(int j=8;j<16;++j)
            if( abs(i-hardWord[j]) < abs(i-near[i]) )
                near[i] = hardWord[j];
    }
    
    string str,buf,opt;
    string::iterator sit;
    getline(cin,str);
    sit = str.begin();
    while( sit!=str.end() )
    {
        buf.clear();
        while( sit!=str.end() && *sit!=' ' )
            buf.push_back(*sit++);
        //cout<<buf;
        opt.clear();
        if( !isHard[buf[0]] )
            buf[0] = near[buf[0]];
            
        char first = buf[0];
        if( first > 'Z' ) first -= ('a'-'A');
        bool flag = false;
        for(char c:buf)
        {
            if(c=='-')
            {
                flag = true;
                continue;
            }
            opt.push_back(c);
            if(flag)
            {
                if( isHard[c] )
                    opt.back() = (opt.back()&0x60)|first;
                //flag=false;
            }
        }
        if( isHard[opt.back()] )
        {
            opt.push_back(neared[opt.back()]);
            opt.push_back('h');
        }
        cout<<opt;
        while( sit!=str.end() && *sit==' ' )
            cout<<*sit++;
    }
    cout<<'\n';
}

