/*! \file builder.h
	\author Noé Fernandes
	\date October, 9th
*/

#ifndef BUILDER_H
#define BUILDER_H

#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include <time.h>

#include "../include/maze.h"

using namespace mzr;

/*! Classe Builder: Responsável por formar os caminhos do maze. */ 
class Builder{

	public:

		/*! Construtor. */
		Builder( Maze *m ): maze( m )
		{
			size_t lenght = maze->get_width() * maze->get_height();
			std::srand( (unsigned int ) std::time(NULL) );

			for( size_t i = 0; i < lenght; i++ )
				matrix.push_back(i);
			
		}

		/*! Destrutor. */
		~Builder(){}

		/*! Mostra na tela numericamente o estado atual do maze. */
		void to_see( void );
		/*! Verifica se o processo de construção já foi finalizado (se todos os numeros do vetor são iguais*/
		bool is_not_complete( void );
		/*! Gera um número aleatório entre [inicio; fim]. */
		size_t generate_random( size_t inicio, size_t fim );
		/*! Função principal que constroi os caminhos no maze. */
		void build( void );
		/*! Responsável por atualizar o estado das células que se conectam entre si.
		(Quando uma célula de valor menor se conecta a um conjunto de células, essas
		recebem o valor da célula de menor valor. */
		void set_equal_number( size_t _old, size_t _new );

		void set_width( size_t value ){ b_width = value; }
		void set_height( size_t value ){ b_height = value; }

	private:
		/*! Vector com a identificação numérica de cada célula. */
		std::vector<size_t> matrix;
		/*! Ponteiro para o maze. */
		Maze *maze;
		/*! Tamanho da imagem na horizontal. */
		size_t b_width;
		/*! Tamanho da imagem na vertical. */
		size_t b_height;
		/*! Indices da sequencia de imagens. */
		size_t cont_img = 1;


};



#endif