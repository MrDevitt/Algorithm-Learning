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

Node* create(int n){//构建长度为n的链表

}


int KMP(string s1,stirng s2){
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
    set<int> st;
    st.insert(1);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    auto it = st.find(2);
    bool k = it == st.end();
    return 0;
}
