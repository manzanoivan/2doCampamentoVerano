#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int INF  = INT_MAX;

int N,S;
int V[2002];
int P[2002];
int DP[2002][2002];

int Busca(int CapacidadActual, int Posicion){
	
	if(CapacidadActual < 0){
		return -INF;
	}
	
	if(Posicion == N+1){
		return 0;
	}
	if(CapacidadActual == 0){
		return 0;
	}
	

	if(DP[CapacidadActual][Posicion] != -1){
		return DP[CapacidadActual][Posicion];
	}

	int Solucion;
	Solucion = max(Busca(CapacidadActual-P[Posicion], Posicion+1)+V[Posicion],
		           Busca(CapacidadActual,Posicion+1));
	DP[CapacidadActual][Posicion] = Solucion;

	return Solucion;
}

int main(){

	optimizar_io

	cin >> S >> N ;

	for(int i = 1; i <= N ; i++){
		cin >> P[i] >> V[i];
	}

	for(int i = 0; i <= S; i ++){
		for(int j = 0 ; j <= N ; j++)
			DP[i][j] = -1;
	}

	cout << Busca(S,1) <<'\n';

	return 0;
}