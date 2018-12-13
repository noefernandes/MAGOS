/*! \file render.h
	\author Noé Fernandes
	\date December, 12th
*/

#ifndef RENDER_H
#define RENDER_H

#include "../include/maze.h"
#include "../include/canvas.h"

using namespace mzr;
/*! Classe Render: Recebe um ponteiro para o maze e, com suas informações, desenha o desenha. */
class Render{

	public:
		/*! Construtor. */
		Render( Maze* m, const size_t w, const size_t h )
		: maze( m ), width_render( w ), height_render( h ){ /* empty */}

		/*! Destrutor. */
		~Render(){}

		/*! Função responsável por desenha o Maze. */
		void draw( const char *name_arq );
		/*! Retorna o número de pixels da imagem na horizontal. */ 
		size_t get_width( void ){ return width_render; }
		/*! Retorna o número de pixels da imagem na vertical. */
		size_t get_height( void ){ return height_render; }

	private:
		/*! Ponteiro para o maze. */
		Maze *maze;
		/*! Numero de pixels da imagem na horizontal. */
		size_t width_render;
		/*! Numero de pixels da imagem na vertical. */
		size_t height_render;
};



#endif