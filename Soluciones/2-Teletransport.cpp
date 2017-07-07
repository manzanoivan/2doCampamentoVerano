#include <iostream>
#include <vector>
#include <algorithm>
#define lli int
using namespace std;

const lli MOD = 1e4;

typedef vector<lli> Vector;
typedef vector<Vector> Matriz;

int N, L, ori, dest, aux;

Matriz Multiplicar( const Matriz& a, const Matriz& b ){
	Matriz producto( a.size(), Vector( b[0].size(), 0 ) );
	for( int i = 0; i < a.size(); i++ ){
		for( int j = 0; j < b[0].size(); j++ )
			for( int k = 0; k < b.size() ; k++ )
				producto[i][j] = (producto[i][j] + (a[i][k]*b[k][j]) % MOD ) % MOD;
	}
	return producto;

}

Matriz Exponenciar( Matriz a, int n ){
	Matriz resultado( N, Vector( N, 0 ) );
	for( int i = 0; i < N; i++ )
		resultado[i][i] = 1;
	for( ; n; n >>= 1 ){
		if( n&1 ) resultado = Multiplicar( resultado, a );
		a = Multiplicar( a, a );
	}
	return resultado;
}

int main(){
	while( cin >> N >> L ){
		cin >> ori >> dest;
		Matriz mat( N, Vector( N ) );
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < 4; j++ ){
				cin >> aux;
				mat[i][aux-1]++;
			}
		}
		Matriz res = Exponenciar( mat, L );
		cout << res[ori-1][dest-1] << '\n';
	}
}