//============================================================================
// Name        : SIme.cpp
// Author      : FJ
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Implemente, tanto de forma recursiva como de forma iterativa, una función que nos
//diga si una cadena de caracteres es simétrica (un palíndromo). Por ejemplo, "Arenera".


bool palin (string cadena) {

	int x = 0, y = cadena.size() -1;

    while (x < y) {

    	if (cadena[x] != cadena[y]) return false;



    	x++;

		y--;



    }
    return true;


}



int main() {

	string cadena;

	cout<<"por favor escriba una palabra si una la palabra es palindroma"<<endl;
    cin>> cadena;

	if(palin(cadena) == true)cout<<"la palabra "<< cadena <<" es palindroma"<<endl;
	else cout<<"la palabra "<< cadena << " no es palindroma"<<endl;


	return 0;
}
