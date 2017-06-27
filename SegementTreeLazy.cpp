#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int ST[400000];
bool Lazy[400000];

void Construye(int Ini,int Fin,int Pos){
	if(Ini == Fin){
		ST[Pos] = 0;
		return;
	}
	int mitad = (Ini+Fin)/2;
	Construye(Ini,mitad,Pos*2);
	Construye(mitad+1,Fin,Pos*2+1);
	ST[Pos] = ST[Pos*2] + ST[Pos*2+1];
}

void Update(int Inir,int Finr,int Iniu,int Finu,int Pos){

	if(Lazy[Pos]){
		int Total = Finr-Inir+1;
		ST[Pos] = Total - ST[Pos];
		if(Inir != Finr){
			Lazy[Pos*2] = !Lazy[Pos*2];		
			Lazy[Pos*2+1] = !Lazy[Pos*2+1];		
		}
		Lazy[Pos] = false;
	}

	if(Finr < Iniu || Finu < Inir){
		return;
	}

	if(Inir >= Iniu && Finr <= Finu){
		int Total = Finr-Inir+1;
		ST[Pos] = Total - ST[Pos];
		if(Inir != Finr){
			Lazy[Pos*2] = !Lazy[Pos*2];		
			Lazy[Pos*2+1] = !Lazy[Pos*2+1];		
		}
		Lazy[Pos] = false;
		return;
	}

	int mitad = (Inir + Finr) / 2;
	Update(Inir, mitad, Iniu, Finu,Pos*2);
	Update(mitad+1, Finr, Iniu,Finu,Pos*2+1);

	ST[Pos] = ST[Pos*2] + ST[Pos*2+1];

}

int Query(int Inir, int Finr,int Iniq,int Finq ,int Pos){
	

	if(Finr < Iniq || Finq < Inir){
		return 0;
	}

	if(Inir >= Iniq && Finr <= Finq){
		return ST[Pos];
	}	

	int mitad = (Inir + Finr) / 2;
	int izq = Query(Inir, mitad, Iniq, Finq,Pos*2);
	int der = Query(mitad+1, Finr, Iniq,Finq,Pos*2+1);

	return izq+der;

}

int main(){

	int N,M;
	int K,l,r;

	optimizar_io

	cin >> N >> M ; 

	Construye(1,N,1);

	for(int i = 0 ; i < M ; i++){
		cin >> K >> l >> r ;
		if(K == 0){
			Update(1,N,l,r,1);
		} else {
			cout << Query(1,N,l,r,1) << '\n';
		}
	}

	return 0;
}