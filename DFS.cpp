#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100003;

vector<int> grafo[MAXN];
vector<int> vist;

int DFS( int source ){
   vist[source] = 1;
   for( auto v : grafo[source] ){
        if( vist[v] == -1 ){
            DFS( v );
        }
   }
}

int main()
{
    int N, M, x, y;
    cin >> N >> M;
    
    vist = vector<int>( N, -1 );

    for(  int i = 0; i < M; i++){
        cin >> x >> y;
        grafo[--x].push_back(--y);
        grafo[y].push_back(x);
    }
    
    cin >> x;

    DFS( --x );

    int suma = 0;
    for( int i = 0; i < N; i++ ){
        if( vist[i] == -1 ) suma++;
    }

    cout << suma << '\n';
    
    return 0;
}
