
//c++ code for ask.3

#include <iostream>
#include "string"
using namespace std;
char c;

int main(){
    string s="s",first;
    string eqs[101];
    int g=0;
    string ch;

    //first input prototype then total dna sequnce

    //input of prototype DNA sequnce s
    cout<<"Input prototype DNA (sample s):"<<endl;
    while((c=getchar())=='A' or c=='G' or c=='T' or c=='C'){
        if(g==0) eqs[0]=first=c;
        eqs[g+1]=eqs[g]+c;
        eqs[g++].erase(0,1);
       s+=c;}

    //input of total DNA sequence ch (S apo ekfonisi)
    cout<<"Input total DNA sequence:"<<endl;
    while((c=getchar())=='A' or c=='G' or c=='T' or c=='C'){
        ch+=c;}

    //DFA construction
    int x=s.length()-1;
    int p[x+1][5];

    for(int i=0;i<=x;i++){
        p[i][1]=p[i][2]=p[i][3]=p[i][4]=0;
    }

    for( int n=0;n<x;n++){
    if(s[n+1]=='A') p[n][1]=n+1;
    else
        for(int i=n;i>0;i--) if(eqs[i]+'A'==first+eqs[i]) p[n][1]=i;
    }
    for( int n=0;n<x;n++){
        if(s[n+1]=='C') p[n][2]=n+1;
        else
            for(int i=n;i>0;i--) if(eqs[i]+'C'==first+eqs[i]) p[n][2]=i;
    }
    for( int n=0;n<x;n++){
        if(s[n+1]=='G') p[n][3]=n+1;
        else
            for(int i=n;i>0;i--) if(eqs[i]+'G'==first+eqs[i]) p[n][3]=i;
    }
    for( int n=0;n<x;n++){
        if(s[n+1]=='T') p[n][4]=n+1;
        else
            for(int i=n;i>0;i--) if(eqs[i]+'T'==first+eqs[i]) p[n][4]=i;
    }

    //check if s -> S
    int i=0,n=0;
   while(i<x and n<ch.length())
    {
        if(ch[n]=='A') i=p[i][1];
        else if(ch[n]=='C') i=p[i][2];
        else if(ch[n]=='G') i=p[i][3];
        else if(ch[n]=='T') i=p[i][4];
    n++;
    }
   //output
   if(i>=x) cout<<"DNA sequence contains sample s";
   else cout<<"DNA sequence does not contain sample s";}


//it works for the examples and corner cases that I could think of,don't know if it works for everything