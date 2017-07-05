#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 50;

vector<int> grafo[MAXN];
vector<int> vist;
vector<int> orden;

int TopoSort( int source ){
   vist[source] = 1;
   for( auto v : grafo[source] ){
        if( vist[v] == -1 ){
            TopoSort( v );
        }
   }
   orden.push_back( source );
}

int main()
{
    int N, M, x, y;
    cin >> N >> M;
    
    vist = vector<int>( N, -1 );

    for(  int i = 0; i < M; i++){
        cin >> x >> y;
        grafo[--x].push_back(--y);
    }

    for( int i = N-1; i >= 0; i-- ){
        if( vist[i] == -1 )
            TopoSort( i );
    }
    
    for( int i = orden.size()-1; i >= 0; i-- ){
        cout << orden[i]+1 << " ";
    }
    cout << '\n';
    
    return 0;
}
