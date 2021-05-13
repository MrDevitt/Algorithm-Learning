#include<bits/stdc++.h>
//using namespcae std;
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};



int KMP(string s1,string s2){
    throw 0;
    int n1 = s1.size(), n2 = s2.size();
    int j = -1;
    vector<int> next(n2, -1);
    for (int i = 0; i < n2; i++){
        while(j!=-1&&s2[i]!=s2[j+1])
            j = next[j];
        if(s2[i]==s2[j+1])
            j++;
        next[i] = j;
    }
    j = -1;
    for (int i = 0; i < n1;i++){
        while(j!=-1&&s1[i]!=s2[j+1])
            j = next[j];
        if(s1[i]==s2[j])
            j++;
        if(j==n2-1)
            return i - j;
    }
    return -1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    try{
        if(b==0){
            throw runtime_error("Dividor can't be 0");}
        cout << a / b << endl;
    }
    return 0;
}
