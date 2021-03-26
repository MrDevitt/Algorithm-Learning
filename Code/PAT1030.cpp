#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 500;
const int inf = 0x3fffffff;

int n, m, S, D, G[N][N];
int d[N];
int cost[N][N];
vector<int> pre[N];
vector<int> path;
vector<int> tempPath;
int minCost=inf;
bool visit[N] = {false};

void Dijkstra(int s){
    fill(d, d + N, inf);
    d[s] = 0;
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
                    pre[k].clear();
                    pre[k].push_back(u);
                }
                else if(d[u] + G[u][k] == d[k]){
                    pre[k].push_back(u);
                }
            }
        }
    }
}

void DFS(int u){
    if(u==S){
        tempPath.push_back(u);
        int tempCost = 0;
        for (int i = tempPath.size() - 1; i > 0; i--){
            int id = tempPath[i];
            int next = tempPath[i - 1];
            tempCost += cost[id][next];
        }
        if(tempCost<minCost){
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(u);
    for (int i = 0; i < pre[u].size(); i++){
        DFS(pre[u][i]);
    }
    tempPath.pop_back();
}

int main(){
    scanf("%d%d%d%d", &n, &m, &S, &D);
    fill(G[0], G[0] + N * N, inf);
    int n1, n2, distance, c;
    for (int i = 0; i < m; i++){
        scanf("%d%d%d%d", &n1, &n2, &distance, &c);
        G[n1][n2] = distance;
        G[n2][n1] = distance;
        cost[n1][n2] = cost[n2][n1] = c;
    }
    Dijkstra(S);
    DFS(D);
    for (int i = path.size() - 1; i >= 0; i--){
        printf("%d ", path[i]);
    }
    printf("%d %d", d[D], minCost);
    return 0;
}