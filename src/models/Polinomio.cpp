/*
 * Polinomio.cpp
 *
 *  Created on: Aug 28, 2012
 *      Author: zerokol
 */

#include "Polinomio.h"

int Polinomio::getGrau() {
	return this->coeficientes.size();
}

double Polinomio::calcularValor(double volume) {
	double valor = this->coeficientes.at(0);
	for (int i = 1; i < this->getGrau(); i++) {
		// std::cout << "coef: " << this->coeficientes.at(i) << endl;
		// std::cout << "val: " << valor << endl;
		valor += this->coeficientes.at(i) * pow(volume, i);
	}
	return valor;
}
