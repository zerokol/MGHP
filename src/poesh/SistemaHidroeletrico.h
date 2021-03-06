/*
 * SistemaHidroeletrico.h
 *
 *  Created on: Sep 4, 2012
 *      Author: zerokol
 */

#ifndef SISTEMAHIDROELETRICO_H_
#define SISTEMAHIDROELETRICO_H_
// Importando bibliotecas úteis
#include <iostream> // Biblioteca  padrão de I/O
#include <vector> // Para trabalhar com vetores
#include "../ferramentas/Conversor.h"
#include "HidroeletricaReservatorio.h"

using std::vector;

#define Fc 0.380517504 // Fc = 10⁶/2628000
class SistemaHidroeletrico {
private:
	int intervalos;
	int demanda;
	Conversor conversor;
	vector<vector<double> > volumes;
	vector<vector<double> > vazoes;
	vector<double> geracoes;
	vector<double> geracoesComplementares;
	vector<vector<double> > geracoesIndividuais;
	vector<vector<double> > vazoesDefluente;
	vector<vector<double> > vazoesTurbinada;
	vector<HidroeletricaReservatorio*> usinas;

public:
	SistemaHidroeletrico(int intervalos, int demanda);

	SistemaHidroeletrico(int intervalos, int demanda,
			vector<vector<double> > volumes, vector<vector<double> > vazoes);

	bool adicionarUsinaHidroeletrica(
			HidroeletricaReservatorio* usinaHidroeletrica);
	bool removerUsinaHidroeletrica(
			HidroeletricaReservatorio* usinaHidroeletrica);

	string getNomeUsina(unsigned int codigo);

	double getVolumeMinimoOperativoUsina(unsigned int codigo);

	double getVolumeMaximoOperativoUsina(unsigned int codigo);

	HidroeletricaReservatorio* getUsina(unsigned int codigo);

	void setVolumes(vector<vector<double> > volumes);

	void setVazoes(vector<vector<double> > vazoes);

	double calcularAlturaQuedaLiquidaUsina(unsigned int codigo, double volume,
			double vazaoDefluente);

	double calcularAlturaQuedaLiquidaMediaUsina(unsigned int codigo,
			double volumeMedio);

	double calcularEngolimentoMaximoUsina(unsigned int codigo, double volume,
			double vazaoDefluente);

	double calcularGeracaoHidraulicaUsina(unsigned int codigo, double volume,
			double vazaoDefluente);

	double calcularCustoTotal();

	double calcularVazaoAfluenteIncremental(int indiceUsina, int intervalo);

	double calcularVazaoDefluente(int indiceUsina, int intervalo);

	double calcularEnergiaArmazenadaSistema(int intervalo);

	double calcularEnergiaArmazenadaSistemaMaxima();

	double calcularEnergiaArmazenadaSistemaMinima();

	vector<double> getGeracoes();

	vector<double> getGeracoesComplementares();

	vector<vector<double> > getGeracoesIndividuais();

	vector<vector<double> > getVazoesDefluente();

	vector<vector<double> > getVazoesTurbinada();
};

#endif /* SISTEMAHIDROELETRICO_H_ */
