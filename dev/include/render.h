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
		void set_width( size_t w );
		void set_height( size_t h );
		size_t get_width( void ){ return width_render; }
		size_t get_height( void ){ return height_render; }

	private:
		Maze *maze;
		size_t width_render;
		size_t height_render;
};



#endif