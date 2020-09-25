//============================================================================
// Name        : Funcion.cpp
// Author      : Jonathan Javier Areas
// Version     : Version 1.1
// Copyright   : N.A.
// Description : Funcion Potencial Exponencial implementada de manera iterativa.
//============================================================================

#include <iostream>
using namespace std;

double power(double base, double exp);

int main() {
	double x{}, n{};
	cout << "Introduzca la potencia: " << endl;
	cin >> x;
	cout << "Introduzca el exponenete: " << endl;
	cin >> n;
	cout << x << " a la potencia " << n << " es " << power(x, n);
	return 0;
}

double power(double base, double exp) {
	double aux = 1;
	for (int i = 0; i < exp; i++)
		 aux *= base;
	return aux;
}
