#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

// Criba de Eratostenes de 1 a n.
set<int> primos;
void Criba(int n) {
	int raiz = sqrt(n);
	vector<int> criba(n + 1);
	for (int i = 4; i <= n; i += 2)
		criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2)
		if (!criba[i])
			for (int j = i * i; j <= n; j += i)
				if (!criba[j]) criba[j] = i;

	for( int i = 2; i < n; i++ )
		if( !criba[i] ) primos.insert( i );
}

bool esPrimo( int N ){
	for( auto it : primos )
		if( N%it == 0 && N!=it ) return false;
	return true;
}

int main(){
	int N;
	Criba(32000);

	cin >> N;

	if( esPrimo(N) ){
		cout << 1 << '\n' << N << '\n';
		return 0;
	}
	
	int i;
	for( i = N-1; !esPrimo( i ); i-- );

	if( N-i == 2 ){
		cout << 2 << '\n' << i << ' ' << 2 << '\n';
		return 0;
	}

	cout << 3 << '\n' << i << ' ';

	N -= i;
	
	for( auto it : primos ){
		if( primos.count( N-it ) ){
			cout << it << ' ' << N-it << '\n';
			break;
		}
	}

	return 0;
}