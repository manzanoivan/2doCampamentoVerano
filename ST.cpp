#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int INF = INT_MAX;

int ST[400000];
int valores[100002];

void Construye(int InicioRango,int FinRango,int Pos){
	if(InicioRango == FinRango){
		ST[Pos] = valores[InicioRango];
		return;
	}
	int mitad = (InicioRango + FinRango)/2;
	Construye(InicioRango,mitad,Pos*2);
	Construye(mitad+1,FinRango,Pos*2+1);
	ST[Pos] = min(ST[Pos*2],ST[Pos*2+1]);
}

int Query(int IniRango,int FinRango,const int IniQuery, const int FinQuery,int pos){
	if(FinRango < IniQuery || FinQuery < IniRango){
		return INF;
	}
	if(IniRango >= IniQuery && FinRango <= FinQuery){
		return ST[pos];
	}	
	int mitad = (IniRango+FinRango)/2;
	int izq = Query(IniRango,mitad,IniQuery,FinQuery,pos*2);
	int der = Query(mitad+1,FinRango,IniQuery,FinQuery,pos*2+1);
	return min(izq,der);
}

int main(){

	int N,Q;
	int l,r;

	optimizar_io

	cin >> N ;

	for(int i = 1; i <= N ; i ++){
		cin >> valores[i];
	}

	Construye(1,N,1);

	cin >> Q;

	for(int i = 1 ; i <= Q; i++){
		cin >> l >> r;
		l++,r++;
		cout << Query(1,N,l,r,1) << '\n';
	}

}