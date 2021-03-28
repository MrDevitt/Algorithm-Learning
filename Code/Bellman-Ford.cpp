#include<cstdio>
#include<vector>
#include<set>
using namespace std;

struct node
{
    int v;
    int dis;
    node(int _v,int _dis):v(_v),dis(_dis){}
};
const int N = 500;
const int inf = 0x3fffffff;
vector<node> G[N];
int d[N];
int n, m, C1, C2;
set<int> pre[N];
int pathNum[N];

