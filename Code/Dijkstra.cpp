#include<cstdio>
#include<algorithm>
using namespace std;

const int Inf = 0x3fffffff;
const int Maxv = 1000;

int n, m, s, G[Maxv][Maxv];//n为顶点数 m为边数 s为起点
int d[Maxv];
int pre[Maxv];
bool visit[Maxv] = {false};

void Dijkstra(int s){
    fill(d, d + Maxv, Inf);
    d[s] = 0;
    for (int i = 0; i < n; i++){
        int u = -1;
        int min = Inf;
        for (int j = 0; j < n; j++){
            if(visit[j] == false && d[j]<min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1)return;
        //访问u,更新d
        visit[u] = true;
        for (int k = 0; k < n; k++){
            if(visit[k] == false && G[u][k] != Inf && d[u] + G[u][k] < d[k]){
                d[k] = d[u] + G[u][k];
                pre[k] = u;
            }
        }
    }
}

void Path(int s, int des){
    if(pre[des]==s){
        printf("%d\n", s);
        return;
    }
    Path(s, pre[des]);
    printf("%d\n", des);
}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    fill(G[0], G[0] + Maxv * Maxv, Inf);
    int n1, n2, weight;
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &n1, &n2, &weight);
        G[n1][n2] = weight;
        G[n2][n1] = weight;
    }
    Dijkstra(s);
    for (int i = 0; i < n; i++){
        printf("%d ", d[i]);
    }
    printf("\nThe path is :\n");
    Path(s, 5);
    return 0;
}