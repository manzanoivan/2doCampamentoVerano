#include <iostream>
#define lli long long
using namespace std;

const int MAXA = 65;
const int MAXB = 100;

lli N;
lli tam;
lli memo[MAXA][MAXB][2];

lli logDos( lli val ){
	lli aux = 1ll;
	lli ret = 0ll;
	while( aux <= val ){
		aux *= 2ll;
		ret++;
	}
	ret--;
	return ret;
}

lli dp( int pos, int k, bool b ){
	if( memo[pos][k][b] != -1LL ) return memo[pos][k][b];
	if( pos == tam+1 ) return memo[pos][k][b] = k;
	if( b && !( N & (1ll << (tam-pos))) )
		return memo[pos][k][b] = dp( pos+1, k, true );
	if( b && ( N & (1ll << (tam-pos))) )
		return memo[pos][k][b] = dp( pos+1, k, false ) + dp( pos+1, k+1, true);
	if( !b )
		return memo[pos][k][b] = dp( pos+1, k, false ) + dp( pos+1, k+1, false);
	return 0;
}

void limpia(){
	for( int i = 0; i < MAXA; i++ ){
		for( int j = 0; j < MAXB; j++ ){
			for( int k = 0; k < 2; k++ ){
				memo[i][j][k] = -1;
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	lli A, B;
	lli resA, resB;
	while( cin >> A >> B ){
		limpia();
		N = A-1;
		tam = logDos(A-1);
		resA = dp( 0, 0, true );
		limpia();
		N = B;
		tam = logDos(B);
		resB = dp( 0, 0, true );
		cout << resB-resA << '\n';
	}
	return 0;
}