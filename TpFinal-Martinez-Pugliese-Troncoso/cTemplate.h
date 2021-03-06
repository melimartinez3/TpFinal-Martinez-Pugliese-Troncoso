#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class cLista {
private:
	T** lista;
	int cantactual;
	int tamtotal;

public:
	friend class cElectrodomesticos;
	friend class cMusimundo;
	friend class cCliente;
	friend class cVendedor;
	friend class cDespachante;

	cLista(int _tamtotal);
	void operator+(T* nuevo);
	T* operator-(T* aeliminar);
	cLista<T>* Filtrar(string parametro);
	friend ostream& operator<< <>(ostream& out, const cLista<T>&);
	T* operator[](int pos);
	bool operator>(int pos);
	void set_cantactual(int cantactual) {
		this->cantactual = cantactual;
	}

	int get_cant_actual() {
		return this->cantactual;
	}
	int get_tamanio_total() {
		return this->tamtotal;
	}

	~cLista();

};

// constructor de la lista template
template <class T>
cLista<T>::cLista(int _tamtotal) {

	this->cantactual = 0;
	this->tamtotal = _tamtotal;
	lista = new T * [tamtotal];
	for (int i = 0; i < tamtotal; i++) {
		lista[i] = NULL;
	}
}

/// <summary>
/// Agregamos a la lista un nuevo elemento
/// </summary>
/// <param name="nuevo"></param>
template <class T>
void cLista<T>::operator+(T* nuevo) {

	if (cantactual < tamtotal) {// verificamos que la cantidad actual sea menor a la maxima
		lista[cantactual++] = nuevo;// lo agregamos a la lista
	}

}


/// <summary>
/// Operator []
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="busqueda"></param>
/// <returns></returns>
template <class T>
T* cLista<T>::operator[](int pos)
{
	bool ok;
	try {
		ok = pos > cantactual;
	}
	catch (...) {
		return NULL;
	}
	return lista[pos];
}
template <class T>
bool cLista<T>::operator>(int pos) {

	if (pos > cantactual) {
		throw new exception(" Se esta intenatndo acceder a una posicion inexistente ");
		return false;
	}
	else return true;

}
/// <summary>
/// esta funcion quita de la lista un elemento
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="aeliminar"></param>
/// <returns></returns>
template <class T>
T* cLista<T>::operator-(T* aeliminar) {
	T* aux = NULL;
	int pos = -1;

	for (int i = 0; i < cantactual; i++) {
		if (lista[i] == aeliminar)
		{
			aux = lista[i];
			pos = i;
		}
	}

	if (pos == -1)
		return NULL;

	this->set_cantactual(--cantactual);
	for (int j = pos; j < cantactual; j++)
	{
		lista[j] = lista[j + 1];
	}

	lista[cantactual] = NULL;

	return aux;
}


/// <summary>
/// Filtramos y retornamos la sublista
/// </summary>
/// <param name="parametro"></param>
/// <returns></returns>
template <class T>
cLista<T>* cLista<T>::Filtrar(string parametro)
{
	cLista<T>* sublista_aux = new T[tamtotal];
	int cont = 0;

	for (int i = 0; i < cantactual; i++) //recorremos toda la lista
	{
		if (*lista[i] == parametro) //si encontramos al elemento buscado
		{
			sublista_aux[i] = lista[i]; //igualamos el elemento[i] de la sublista auxiliar al elemento[i] de la lista original
			cont++; //sumamos 1 al contador 
		}

	}

	T* sublista = new T[cont]; //creamos una sublista del tama?o necesario
	for (int i = 0; i < cont; i++)
	{
		sublista[i] = sublista_aux[i]; //copiamos los elementos de la sublista auxiliar a la sublista
	}

	return sublista; //retornamos la sublista

}

/// <summary>
/// operador de flujo
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
/// <param name="clase"></param>
/// <returns></returns>
template <class T>
ostream& operator<< <>(ostream& out, const cLista<T>& Lista) {

	for (int i = 0; i < Lista.cantactual; i++)
	{
		out << Lista.lista[i]->tostring() << endl;
	}

	return out;
}


// destructor de la lista template
template <class T>
cLista<T>::~cLista() {
	if (lista != NULL) {
		for (int i = 0; i < cantactual; i++) {
			if (lista[i] != NULL) {
				delete lista[i];
			}
		}
		delete[] lista;
	}
}

