#ifndef RENDER_H
#define RENDER_H

#include "../include/maze.h"
#include "../include/canvas.h"

using namespace mzr;

class Render{

	public:

		Render( Maze* m, const size_t w, const size_t h )
		: maze( m ), width_render( w ), height_render( h ){ /* empty */}

		~Render(){}

		void draw( const char *name_arq );

	private:
		Maze *maze;
		size_t width_render;
		size_t height_render;
};



#endif