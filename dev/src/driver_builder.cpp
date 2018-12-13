#include <iostream>
#include "../include/builder.h"
#include "../include/maze.h"
#include "../include/render.h"

int main()
{
	Maze m(100, 100);

	Builder b( &m );

	//b.to_see();

	b.build();

	Render r( &m, 800, 600 );
	r.draw( "img" );

	//b.to_see();

	return 0;
}