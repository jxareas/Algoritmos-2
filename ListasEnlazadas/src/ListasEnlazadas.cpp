//============================================================================
// Name        : ListasEnlazadas.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;



struct nodo {
	int codigoProducto;
	string descripcion;
	int cantidad;
	float precio;
	nodo *elementoSigueinte;
};

void insertarDato(nodo *&lista, int dato, string nombre, int cantidad, float price){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->codigoProducto = dato;
	nuevo_nodo->descripcion = nombre;
	nuevo_nodo->cantidad = cantidad;
	nuevo_nodo->precio = price;

	nodo *aux1 = lista;
	nodo *aux2;

	while((aux1 != NULL) && (aux1->codigoProducto < dato)){
		aux2 = aux1;
		aux1 = aux1->elementoSigueinte;
	};

	if(lista == aux1){
		lista = nuevo_nodo;
	}else {
		aux2->elementoSigueinte = nuevo_nodo;
	};

	nuevo_nodo->elementoSigueinte = aux1;
	cout<<"Elemento "<<dato<<" insertado a la lista correctamente."<<" Su descripcion es: "<<nombre<<endl;
}

void mostrarLista(nodo *lista){
	nodo *actual = new nodo();
	actual = lista;
	int n = 0;
	cout<<"Estos son los datos que han sido ingresados.\n"<<endl;
	while(actual != NULL){
		n++;
		cout<<n<<".  "<<actual->codigoProducto<<" - Descripcion: "<<actual->descripcion<<" - Cantidad: "<<actual->cantidad<<" - Precio: "<<actual->precio<<endl;
		actual = actual->elementoSigueinte;
	};
}

void eliminarElemento(nodo *&lista, int codeItemToDelete){
	if(lista != NULL){
		nodo *aux_borrar;
		nodo *anterior = NULL;

		aux_borrar = lista;

		while((aux_borrar != NULL) && (aux_borrar->codigoProducto != codeItemToDelete)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->elementoSigueinte;
		};

		if(aux_borrar == NULL){
			cout<<"El elemento que quiere eliminar no exite en esta lista."<<endl;
		}else if(anterior == NULL){
			lista = lista->elementoSigueinte;
			delete aux_borrar;
		}else {
			anterior->elementoSigueinte = aux_borrar->elementoSigueinte;
			delete aux_borrar;

		};
	};
}


int main() {
	nodo *lista = NULL;
	int code;
	int n = 0;
	string name;
	int cant;
	float cost;
	int opcion;

	cout<<"Digite el codigo del producto a ingresar, luego su descripcion. (Ingrese 0 para salir de la ejecución)"<<endl;
	do{
		n++;
		cout<<"Elemento numero "<<n<<": ";
		cin>>code;

		if(code != 0){
			cout<<"\n Descripcion: ";
			cin>>name;
			cout<<"\n Cantidad: ";
			cin>>cant;
			cout<<"\n Precio: ";
			cin>>cost;
		};

		if(code != 0){
			insertarDato(lista, code, name, cant, cost);
		};
	}while(code != 0);

	mostrarLista(lista);

	cout<<"Desea eliminar algun elemento de la lista? si(1) - no(0)"<<endl;
	cin>>opcion;

	if(opcion == 1){
		cout<<"Digite el codigo del producto que desea eliminar."<<endl;
		cin>>code;

		eliminarElemento(lista, code);
	};

	mostrarLista(lista);

	cout<<"Si desea repetir el proceso, agregar o eliminar elementos, digite 1, de lo contrario digite 0"<<endl;
	cin>>opcion;
	if(opcion == 1){
		main();
	}else{
		cout<<"Gracias por preferirnos."<<endl;
	};

	return 0;
}
