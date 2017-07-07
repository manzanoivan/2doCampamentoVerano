#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = (1 << 18) + 100;
//ST indexado desde uno
int temp;
int ST[SIZE][4];
int Lazy[SIZE];
 
inline void rotar( int n, int v ){
	while( v-- ){
		temp = ST[n][0];
		ST[n][0] = ST[n][2];
		ST[n][2] = ST[n][1];
		ST[n][1] = temp;
	}
}
 
inline void init(int a, int b, int v, int n, int L, int R) {
	if (L > b || R < a) return;
	if (L >= a && R <= b) {
		ST[n][0] = 1;
		ST[n][3] = 0;
		return;
	}
	int mid = (L + R) >> 1;
	init(a, b, v, n << 1, L, mid);
	init(a, b, v, (n << 1) + 1, mid + 1, R);
 
	ST[n][0] = ST[ n << 1 ][0] + ST[ (n << 1) + 1 ][0];
	ST[n][1] = ST[ n << 1 ][1] + ST[ (n << 1) + 1 ][1];
	ST[n][2] = ST[ n << 1 ][2] + ST[ (n << 1) + 1 ][2];
 
}
 
inline void Update(int a, int b, int v, int n, int L, int R) {
	if( L >= a && R <= b){
		Lazy[n] = (Lazy[n] + v);
		rotar( n, v % 3 ); 
		return;
	}
 
	if (L > b || R < a){
		v--;
		if( v ){
			Lazy[n] = (Lazy[n] + v);
			rotar( n, v % 3 ); 
		}
		return;
	}
 
 
	int mid = (L + R) >> 1;
	Update(a, b, v + Lazy[n], n << 1, L, mid);
	Update(a, b, v + Lazy[n], (n << 1) + 1, mid + 1, R);
	Lazy[n] = 0;
 
	ST[n][0] = ST[ n << 1 ][0] + ST[ (n << 1) + 1 ][0];
	ST[n][1] = ST[ n << 1 ][1] + ST[ (n << 1) + 1 ][1];
	ST[n][2] = ST[ n << 1 ][2] + ST[ (n << 1) + 1 ][2];
}
 
inline int Query(int a, int b, int v, int n, int L, int R) {
	if( v ){
		Lazy[n] = (Lazy[n] + v);
		rotar( n, v % 3 );
	}
 
	if (L > b || R < a) return 0;
	if (L >= a && R <= b){
		return ST[n][ 0 ];
	}
 
	int mid = (L + R) >> 1;
	int uno, dos;
	uno = Query(a, b, Lazy[ n ], n << 1, L, mid);
	dos = Query(a, b, Lazy[ n ], (n << 1) + 1, mid + 1, R);
	Lazy[n] = 0;
 
	return uno+dos;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, Q, a, b, c;
 
	cin >> N >> Q;
 
	for( int i = 1; i <= N; i++ ){
		init( i, i, 1, 1, 1, N );
	}
 
	while( Q-- ){
		cin >> a >> b >> c;
		if( a == 0 ){
			Update( b+1, c+1, 1, 1, 1, N );
		}
		else{
			cout << Query( b+1, c+1, 0, 1, 1, N ) << "\n";
		}
	}
 
	return 0;
}