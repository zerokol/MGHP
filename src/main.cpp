/*
 * main.cpp
 *
 *  Created on: Aug 28, 2012
 *      Author: zerokol
 */

// Importando bibliotecas necessárias
#include <iostream> // Biblioteca  padrão de I/O
#include <algorithm>
#include <fstream> // Para manipular arquivos
#include <vector> // Para fácil uso de vetores
#include <string> // Para trabalhar fácil com strings
#include <sstream> // Para trabalhar fácil com strings
#include <math.h> // Para ajudar em calculos matemáticos
#include "modelos/SistemaHidroeletrico.h"
#include "modelos/HidroeletricaReservatorio.h"
#include "ferramentas/Conversor.h"

using namespace std;

// Constantes
#define INTERVALOS 60
#define QUANTIDADE_USINAS 2

// Variáveis
SistemaHidroeletrico sistemaHidroeletrico;
// HidroeletricaReservatorio* hidroeletricas[QUANTIDADE_USINAS];
double volumes[QUANTIDADE_USINAS][INTERVALOS];
double vazoes[QUANTIDADE_USINAS][INTERVALOS];
double geracao_hidraulica_intervalos[INTERVALOS];
Conversor conversor;

void carregar_valores();

int main(int argc, char *argv[]) {
	carregar_valores();

	// Configurando as usinas
	// Itubiara
	HidroeletricaReservatorio* itumbiara = new HidroeletricaReservatorio(1,
			"Itumbiara");

	ConjuntoUnidadesGeradoras* conjuntoUnidadesGeradorasItumbiara =
			new ConjuntoUnidadesGeradoras(1, 6, 380.0, 537.0, 80.20, 1);
	CasaDeMaquinas* casaDeMaquinasItumbiara = new CasaDeMaquinas();
	casaDeMaquinasItumbiara->adicionarConjuntoUnidadesGeradoras(
			conjuntoUnidadesGeradorasItumbiara);
	itumbiara->setCasaDeMaquinas(casaDeMaquinasItumbiara);

	vector<double> coeficientesMontanteItumbiara;
	coeficientesMontanteItumbiara.push_back(471.16);
	coeficientesMontanteItumbiara.push_back(7.2805E-03);
	coeficientesMontanteItumbiara.push_back(-5.6098E-07);
	coeficientesMontanteItumbiara.push_back(2.59776E-11);
	coeficientesMontanteItumbiara.push_back(-4.845359E-16);
	PolinomioMontante* polinomioMontanteItumbiara = new PolinomioMontante(
			coeficientesMontanteItumbiara);
	itumbiara->setPolinomioMontante(polinomioMontanteItumbiara);

	vector<double> coeficientesJusanteItumbiara;
	coeficientesJusanteItumbiara.push_back(433.0);
	coeficientesJusanteItumbiara.push_back(1.59584E-03);
	coeficientesJusanteItumbiara.push_back(-8.177386E-08);
	coeficientesJusanteItumbiara.push_back(3.1735E-12);
	coeficientesJusanteItumbiara.push_back(0.0);
	PolinomioJusante* polinomioJusanteItumbiara = new PolinomioJusante(
			coeficientesJusanteItumbiara);
	itumbiara->setPolinomioJusante(polinomioJusanteItumbiara);

	itumbiara->setVolumeMinimoOperativo(4573.0);
	itumbiara->setVolumeMaximoOperativo(17027.0);
	itumbiara->setVolumeMaximoMaximorum(17975.0);
	itumbiara->setVazaoDefluenteMinima(254.0);
	itumbiara->setVazaoDefluenteMaxima(1E20);
	itumbiara->setNivelMedioJusante(435.6);
	itumbiara->setCoeficientePerdaCargaHidraulica(0.0120);
	itumbiara->setCoeficienteProdutibilidadeEspecifica(0.008829);

	sistemaHidroeletrico.adicionarUsinaHidroeletrica(itumbiara);

	// Emborcação
	HidroeletricaReservatorio* emborcacao = new HidroeletricaReservatorio(2,
			"Emborcação");

	ConjuntoUnidadesGeradoras* conjuntoUnidadesGeradorasEmborcacao =
			new ConjuntoUnidadesGeradoras(2, 4, 298.0, 262.0, 130.30, 1);
	CasaDeMaquinas* casaDeMaquinasEmborcacao = new CasaDeMaquinas();
	casaDeMaquinasEmborcacao->adicionarConjuntoUnidadesGeradoras(
			conjuntoUnidadesGeradorasEmborcacao);
	emborcacao->setCasaDeMaquinas(casaDeMaquinasEmborcacao);

	vector<double> coeficientesMontanteEmborcacao;
	coeficientesMontanteEmborcacao.push_back(568.09);
	coeficientesMontanteEmborcacao.push_back(1.4506E-02);
	coeficientesMontanteEmborcacao.push_back(-1.2028E-06);
	coeficientesMontanteEmborcacao.push_back(5.8303E-11);
	coeficientesMontanteEmborcacao.push_back(-1.1245E-15);
	PolinomioMontante* polinomioMontanteEmborcacao = new PolinomioMontante(
			coeficientesMontanteEmborcacao);
	emborcacao->setPolinomioMontante(polinomioMontanteEmborcacao);

	vector<double> coeficientesJusanteEmborcacao;
	coeficientesJusanteEmborcacao.push_back(519.78);
	coeficientesJusanteEmborcacao.push_back(3.9966E-03);
	coeficientesJusanteEmborcacao.push_back(-1.0987E-06);
	coeficientesJusanteEmborcacao.push_back(2.3438E-10);
	coeficientesJusanteEmborcacao.push_back(-1.7646E-14);
	PolinomioJusante* polinomioJusanteEmborcacao = new PolinomioJusante(
			coeficientesJusanteEmborcacao);
	emborcacao->setPolinomioJusante(polinomioJusanteEmborcacao);

	emborcacao->setVolumeMinimoOperativo(4669.0);
	emborcacao->setVolumeMaximoOperativo(17190.0);
	emborcacao->setVolumeMaximoMaximorum(17427.0);
	emborcacao->setVazaoDefluenteMinima(77.0);
	emborcacao->setVazaoDefluenteMaxima(1E20);
	emborcacao->setNivelMedioJusante(521.9);
	emborcacao->setCoeficientePerdaCargaHidraulica(0.0127);
	emborcacao->setCoeficienteProdutibilidadeEspecifica(0.008731);

	emborcacao->setUsinaMontante(itumbiara);

	sistemaHidroeletrico.adicionarUsinaHidroeletrica(emborcacao);

	/*
	 double nivel_montante = emborcacao->calcularNivelMontante(8000);
	 double nivel_jusante = emborcacao->calcularNivelJusante(600);
	 double altura_queda_bruta = emborcacao->calcularAlturaQuedaBruta(
	 nivel_montante, nivel_jusante);
	 double perda_carga = emborcacao->calcularPerdaCarga(altura_queda_bruta);
	 double altura_queda_liquida = emborcacao->calcularAlturaQuedaLiquida(
	 altura_queda_bruta, perda_carga);
	 double engolimento = emborcacao->calcularEngolimento(8000, 600);
	 double geracao_hidraulica = emborcacao->calcularGeracaoHidraulica(
	 altura_queda_liquida, engolimento);
	 */

	for (int intervalo = 1; intervalo < INTERVALOS; intervalo++) {
		double geracao_hidraulica_total = 0.0;
		for (int indice_usina = 0; indice_usina < QUANTIDADE_USINAS;
				indice_usina++) {

			double geracao_hidraulica =
					sistemaHidroeletrico.calcularGeracaoHidraulicaUsina(
							indice_usina + 1, volumes[indice_usina][intervalo],
							vazoes[indice_usina][intervalo]);

			cout
					<< "gh: " + conversor.double_para_string(geracao_hidraulica)
							+ "\n" << endl;

			geracao_hidraulica_total += geracao_hidraulica;
		}

		cout
				<< "ght: "
						+ conversor.double_para_string(geracao_hidraulica_total)
						+ "\n" << endl;
		geracao_hidraulica_intervalos[intervalo] = geracao_hidraulica_total;
	}

	//cin.get(); // aguarda por um novo caracter para então encerrar a aplicação
	return 0;
}

void carregar_valores() {
	int contador_usina = 0;
	string line;
	ifstream itumbiara_volumes_file("./assets/Itumbiara-Volumes.txt"); // ifstream = padrão ios:in
	if (itumbiara_volumes_file.is_open()) {
		int contador_interacao = 0;
		//enquanto end of file for false continua
		while (!itumbiara_volumes_file.eof()) {
			getline(itumbiara_volumes_file, line); // como foi aberto em modo texto(padrão), e não binário(ios::bin) pega cada linha
			double d = conversor.string_para_double(line);
			volumes[contador_usina][contador_interacao] = d;
			contador_interacao++;
		}
		itumbiara_volumes_file.close();
	} else {
		cout << "Impossivel abrir o arquivo!";
	}
	ifstream itumbiara_vazoes_file("./assets/Itumbiara-Vazoes.txt"); // ifstream = padrão ios:in
	if (itumbiara_vazoes_file.is_open()) {
		int contador_interacao = 0;
		//enquanto end of file for false continua
		while (!itumbiara_vazoes_file.eof()) {
			getline(itumbiara_vazoes_file, line); // como foi aberto em modo texto(padrão), e não binário(ios::bin) pega cada linha
			double d = conversor.string_para_double(line);
			vazoes[contador_usina][contador_interacao] = d;
			contador_interacao++;
		}
		itumbiara_vazoes_file.close();
	} else {
		cout << "Impossivel abrir o arquivo!";
	}
	contador_usina++;
	ifstream emborcacao_volumes_file("./assets/Emborcacao-Volumes.txt"); // ifstream = padrão ios:in
	if (emborcacao_volumes_file.is_open()) {
		int contador_interacao = 0;
		//enquanto end of file for false continua
		while (!emborcacao_volumes_file.eof()) {
			getline(emborcacao_volumes_file, line); // como foi aberto em modo texto(padrão), e não binário(ios::bin) pega cada linha
			double d = conversor.string_para_double(line);
			volumes[contador_usina][contador_interacao] = d;
			contador_interacao++;
		}
		emborcacao_volumes_file.close();
	} else {
		cout << "Impossivel abrir o arquivo!";
	}
	ifstream emborcacao_vazoes_file("./assets/Emborcacao-Vazoes.txt"); // ifstream = padrão ios:in
	if (emborcacao_vazoes_file.is_open()) {
		int contador_interacao = 0;
		//enquanto end of file for false continua
		while (!emborcacao_vazoes_file.eof()) {
			getline(emborcacao_vazoes_file, line); // como foi aberto em modo texto(padrão), e não binário(ios::bin) pega cada linha
			double d = conversor.string_para_double(line);
			volumes[contador_usina][contador_interacao] = d;
			contador_interacao++;
		}
		emborcacao_vazoes_file.close();
	} else {
		cout << "Impossivel abrir o arquivo!";
	}
}
