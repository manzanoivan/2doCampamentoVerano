#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100003;

vector<int> grafo[MAXN];

int BFS( int source, int N ){
    queue<int> cola;
    vector<int> dist( N, -1 );
    dist[source] = 0;
    cola.push( source );
    
    while( !cola.empty() ){
        int u = cola.front();
        cola.pop();
        for( auto v : grafo[u] ){
            if( dist[ v ] == -1 ){
                dist[v] = dist[u] + 1;
                cola.push( v );
            }
        }
    }
    int suma = 0;
    for( int i = 0; i < N; i++ )
        if( dist[i] == -1 ) suma++;
    return suma;
}

int main()
{
    int N, M, x, y;
    cin >> N >> M;
    
    for(  int i = 0; i < M; i++){
        cin >> x >> y;
        grafo[--x].push_back(--y);
        grafo[y].push_back(x);
    }
    
    cin >> x;
    
    cout << BFS( --x, N ) << '\n';
    
    return 0;
}
