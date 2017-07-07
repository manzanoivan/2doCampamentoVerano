#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> Factor;

// Criba de Eratostenes de 1 a n.
vector<int> Criba(int n) {
	int raiz = sqrt(n);
	vector<int> criba(n + 1);
	for (int i = 4; i <= n; i += 2)
		criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2)
		if (!criba[i])
			for (int j = i * i; j <= n; j += i)
				if (!criba[j]) criba[j] = i;
	return criba;
}

// Factores primos de n factorial (n!). El vector de primos debe estar ordenado.
int FactoresFactorial(int n,
                    const vector<int>& primos) {
    vector<Factor> factores;
    for (int i = 0; i < primos.size(); ++i) {
        if (n < primos[i]) break;
        int p = primos[i]; int reps = n / p;
        while (primos[i] <= n / p) 
            p *= primos[i], reps += n / p;
        factores.push_back(Factor(primos[i],reps));
    }
    int dos = 0, cinco = 0;
    for( int i = 0; i < factores.size(); i++ ){
    	if( factores[i].first == 2 ) dos = factores[i].second;
    	if( factores[i].first == 5 ) cinco = factores[i].second;
    }
    return min( dos, cinco );
}

int main(){
	int N, num;
	vector<int> criba = Criba( 32000 );

	vector<int> primos;
	for( int i = 2; i < criba.size(); i++ ){
		if( !criba[i] ) primos.push_back(i);
	}

	cin >> N;
	while( N-- ){
		cin >> num;
		cout << FactoresFactorial( num, primos ) << '\n';
	}
	return 0;
}