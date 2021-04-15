#include<bits/stdc++.h>
using namespace std;

int KMP(string s1,string s2){
    int n1=s1.size(),n2=s2.size();
    int j=-1;
    vector<int> next(n2,-1);
    for(int i=1;i<n2;i++){
        while(j!=-1&&s2[i]!=s2[j+1])j=next[j];
        if(s2[i]==s2[j+1])j++;
        next[i]=j;
    }
    j=-1;
    for(int i=0;i<n1;i++){
        while(j!=-1&&s1[i]!=s2[j+1])j=next[j];
        if(s1[i]==s2[j+1])j++;
        if(j==n2-1)return i-j;
    }
    return -1;
}

int main(){
    string s1 = "ababababca";
    string s2 = "abababca";
    int n = KMP(s1, s2);
}