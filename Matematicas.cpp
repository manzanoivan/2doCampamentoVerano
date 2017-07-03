#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Criba de Eratostenes de 1 a n.

vector<int> Criba(int n) {
	int raiz = sqrt(n); vector<int> criba(n + 1);
	for (int i = 4; i <= n; i += 2) criba[i] = 2;
	for (int i = 3; i <= raiz; i += 2) if (!criba[i])
		for (int j = i * i; j <= n; j += i)
			if (!criba[j]) criba[j] = i;
	return criba;
}

typedef pair<int, int> Factor;

// Factores primos de n factorial (n!).
// El vector de primos debe estar ordenado.

vector<Factor> FactoresFactorial(
	int n, const vector<int>& primos) {

	vector<Factor> factores;
	for (int i = 0; i < primos.size(); ++i) {
		if (n < primos[i]) break; int p = primos[i];
		int reps = n / p; while (primos[i] <= n / p)
			p *= primos[i], reps += n / p;
		factores.push_back(Factor(primos[i], reps));
	}
	return factores;
}

// Exponenciacion binaria a^n mod m.

typedef long long Long;

Long Exponenciar(Long a, Long n, Long m) {
    Long resultado = 1;
    for (; n; n >>= 1) {
        if (n & 1) resultado =
            (resultado * a) % m;
        a = (a * a) % m;
    }
    return resultado;
}

// Multiplicacion binaria a*b mod m.

Long Multiplicar(Long a, Long b, Long m) {
    Long resultado = 0;
    for (; b; b >>= 1) {
        if (b & 1) resultado =
            (resultado + a) % m;
        a = (a + a) % m;
    }
    return resultado;
}

int main() {
    return 0;
}