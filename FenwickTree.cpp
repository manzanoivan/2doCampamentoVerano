#include <iostream>
using namespace std;

const int MAXN = 1000000;
int N;
int tree[MAXN];

void Actualizar(int i, int v) {
	while (i < N) {
		tree[i] += v; 
		i += i & -i;
	}
}
int Query(int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= i & -i;
	}
	return sum;
}
int Rango(int i, int j) {
	return Query(j) - Query(i - 1);
}

int main(){
	return 0;
}