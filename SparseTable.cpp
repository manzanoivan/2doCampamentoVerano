#include<bits/stdc++.h>
#define LOGN 20
#define MAXN 50003
using namespace std;

int SPMA[MAXN][LOGN], SPMI[MAXN][LOGN], A[MAXN], logs[MAXN];

void pre(int N)
{
    for(int i = 2; i <= N; i++)
        logs[i] = logs[i / 2] + 1;
    for(int i = 0; i < N; i++){
        SPMA[i][0] = A[i];
        SPMI[i][0] = A[i];
    }
    for(int i = 0; i < logs[N]; i++)
        for(int j = 0; j < N; j++){
            SPMA[j][i + 1] = max(SPMA[j][i], SPMA[min(j + (1 << i), N - 1)][i]);
            SPMI[j][i + 1] = min(SPMI[j][i], SPMI[min(j + (1 << i), N - 1)][i]);
        }
}

int queryMA(int a, int b){
    if(a == b) return SPMA[a][0];
    int L = logs[b - a + 1];
    return max(SPMA[a][L], SPMA[b - (1 << L) + 1][L]);
}

int queryMI(int a, int b)
{
    if(a == b) return SPMI[a][0];
    int L = logs[b - a + 1];
    return min(SPMI[a][L], SPMI[b - (1 << L) + 1][L]);
}

int main(){
    int N, Q, a, b;
    scanf("%d%d",&N, &Q);
    for(int i = 0; i < N; i++)
        scanf("%d",&A[i]);
    pre(N);
    for(int i = 0; i < Q; i++){
        scanf("%d%d",&a,&b);
        printf("%d\n", queryMA(a - 1, b - 1) - queryMI(a - 1, b - 1));
    }
}
 