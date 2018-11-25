#include <iostream>
#include "../include/canvas.h"
#include "../include/common.h"
#include "../include/render.h"
#include "../include/maze.h"

using namespace mzr;

int main()
{
	//Cria labirinto 5 x 7
	Maze m( 30, 20 );

	//Construtor do render e passando o endereço de mazer
	Render render( &m, 800, 600 );

	//Derrubando as paredes das células informadas
	m.knock_down( 29, 0 , Maze::side::RightWall );
	m.knock_down( 4, 1 , Maze::side::RightWall );
	m.knock_down( 4, 2 , Maze::side::RightWall );
	m.knock_down( 4, 3 , Maze::side::RightWall );
	m.knock_down( 4, 4 , Maze::side::RightWall );
	m.knock_down( 0, 19, Maze::side::BottomWall );
	m.knock_down( 4, 6 , Maze::side::RightWall );
	m.knock_down( 0, 0 , Maze::side::TopWall );

	for( size_t i = 0; i < 20; i++ )
	{
		m.knock_down( 29, i, Maze::side::RightWall );
	}

	//std::cout << m.has_bottom_wall( 1, 2 ) << "\n";
	//std::cout << m.left_neighbor_has_wall( 4, 4 ) << "\n";

	render.draw( "img1" );

	return 0;
}