#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 500;
const int inf = 0x3fffffff;

int n, m, C1, C2, G[N][N];
int d[N];
int teams[N];
int pathNum[N] = {0};
int teamNum[N] = {0};
bool visit[N] = {false};

void Dijkstra(int s){
    fill(d, d + N, inf);
    d[s] = 0;
    teamNum[s] = teams[s];
    pathNum[s] = 1;
    for (int i = 0; i < n; i++){
        int u = -1;
        int min = inf;
        for (int j = 0; j < n; j++){
            if(visit[j] == false && d[j]<min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1)return;
        //·ÃÎÊu,¸üÐÂd
        visit[u] = true;
        for (int k = 0; k < n; k++){
            if(visit[k] == false && G[u][k] != inf){
                if(d[u] + G[u][k] < d[k]){
                    d[k] = d[u] + G[u][k];
                    pathNum[k] = pathNum[u];
                    teamNum[k] = teamNum[u] + teams[k];
                }
                else if(d[u] + G[u][k] == d[k]){
                    pathNum[k] += pathNum[u];
                    if(teamNum[u]+teams[k]>teamNum[k]){
                        teamNum[k] = teamNum[u] + teams[k];
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &C1, &C2);
    fill(G[0], G[0] + N * N, inf);
    for (int i = 0; i < n; i++){
        scanf("%d", &teams[i]);
    }
    int n1, n2, distance;
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &n1, &n2, &distance);
        G[n1][n2] = distance;
        G[n2][n1] = distance;
    }
    Dijkstra(C1);
    printf("%d %d", pathNum[C2], teamNum[C2]);
    return 0;
}