//============================================================================
// Name        : SIme.cpp
// Author      : FJ
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;






bool palindro (char p[], int ini, int end){

		if(ini >= end) return true;
		if(p[ini]==p[end])
		palindro(p,ini+1,end-1);
		else return false;
}


int main() {

char p [50];
int l;
bool pal;

cout<<"por favor escriba una palabra para saber si es un palindromo"<<endl;

cin.getline(p, 50);
l=strlen(p);

pal =palindro(p,0,l-1);

if(pal == true) cout<<"\n"<< p <<" es un palindromo ";
else cout<<"\n"<< p <<" no es un palindromo "<<endl;


	return 0;
}








