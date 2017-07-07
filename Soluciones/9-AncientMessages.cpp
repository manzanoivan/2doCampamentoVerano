#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#define MAXN 205
using namespace std;

int imagen[205][205];
int color;

int movI[] = { 0, 0, 1, -1 };
int movJ[] = { 1, -1, 0, 0 };

int movI8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int movJ8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int H, W, num, caso = 1;

set < int > conj;
map < int, char > mapa;

bool valido( int i, int j ){
	if( i >= 0 && j >= 0 && i < MAXN && j < MAXN ) return true;
	return false;
}

void floodFill( int i, int j ){
	imagen[i][j] = color;
	for( int k = 0; k < 8; k++ ){
		if( valido( i + movI8[k] , j + movJ8[k] ) && !imagen[ i + movI8[k] ][ j + movJ8[k] ] )
			floodFill( i + movI8[k], j + movJ8[k] );
	}
}

void llenar( int i, int j ){
	imagen[i][j] = color;
	for( int k = 0; k < 4; k++ ){
		if( valido( i + movI[k] , j + movJ[k] ) ){
			if( imagen[ i + movI[k] ][ j + movJ[k] ] == 1  )
				llenar( i + movI[k], j + movJ[k] );
			else if( imagen[ i + movI[k] ][ j + movJ[k] ] != color )
				conj.insert( imagen[ i + movI[k] ][ j + movJ[k] ] );
		}
	}
}

int main(){
	string cad, res;
	mapa[ 2 ] = 'A';
	mapa[ 4 ] = 'J';
	mapa[ 6 ] = 'D';
	mapa[ 5 ] = 'S';
	mapa[ 1 ] = 'W';
	mapa[ 3 ] = 'K';

	while( 1 ){
		cin >> H >> W;
		if( !H && !W ) break;

		for( int i = 0; i < MAXN; i++ ){
			for( int j = 0; j < MAXN; j++ ){
				imagen[i][j] = 0;
			}
		}

		for( int i = 1; i <= H; i++ ){
			cin >> cad;
			for( int j = 1; j <= W; j++ ){
				num = ( cad[ j - 1 ] >= 'a' ? 10 + cad[j - 1] - 'a' : cad[j - 1] - '0' );
				for( int k = 3; k >= 0; k-- ){
					imagen[ i ][ j*4 + 3 - k] = ( (num >> k) & 1 );
				}
			}
		}

		res = "";
		color = 2;
		/*
		for( int i = 0; i < H + 2; i++ ){
			for( int j = 0; j < 4*(W+2) ; j++ ){
				cout << imagen[i][j];
			}
			cout << endl;
		}
		cout << endl;
		*/
		
		for( int i = 0; i < H + 2; i++ ){
			for( int j = 0; j < 4*(W+2); j++ ){
				if( !imagen[i][j] ){
					floodFill( i, j );
					color++;
				}
			}
		}
		/*
		for( int i = 0; i < H+2; i++ ){
			for( int j = 0; j < 4*(W+2); j++ ){
				cout << imagen[i][j];
			}
			cout << endl;
		}
		cout << endl;
		*/
		for( int i = 0; i < H + 2; i++ ){
			for( int j = 0; j < 4*(W+2); j++ ){
				if( imagen[i][j] == 1 ){
					conj.clear();
					llenar( i, j );
					res += mapa[ conj.size() ];
					color++;
				}
			}
		}

		sort( res.begin(), res.end() );

		cout << "Case " << caso++ << ": " << res << '\n';

	}
	return 0;
}