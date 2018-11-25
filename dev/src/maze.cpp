#include "../include/maze.h"

namespace mzr{
	
	Maze::Maze( const Maze & clone)
	{
		height = clone.height;
		width = clone.width;
		delete maze;
		maze = new Cell[ height * width ];
		memmove( maze, clone.maze, ( height*width ) );
	}

	Maze & Maze::operator=( const Maze & clone )
	{
		delete maze;
		maze = new Cell[ height * width ];
		height = clone.height;
		width = clone.width;
		memmove( maze, clone.maze, ( height*width ) );
		return *this;			
	}



	void Maze::knock_down( size_t x, size_t y, Maze::side v_side )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		switch( v_side )
		{
			case Maze::side::TopWall:
				
				maze[ width * y + x].TopWall = false;
				
				if( !is_outside( x, y - 1) )
				{
					maze[ width * ( y - 1 ) + x].BottomWall = false;
				}
				
				break;

			case Maze::side::BottomWall:
				
				maze[ width * y + x].BottomWall = false;

				if( !is_outside( x, y + 1) )
				{
					maze[ width * ( y + 1 ) + x].TopWall = false;
				}
				
				break;

			case Maze::side::RightWall:
				
				maze[ width * y + x].RightWall = false;

				if( !is_outside( x + 1, y) )
				{
					maze[ width * y + ( x + 1 )].LeftWall = false;
				}

				break;

			case Maze::side::LeftWall:
				maze[ width * y + x].LeftWall = false;

				if( !is_outside( x - 1, y) )
				{
					maze[ width * y + ( x - 1 )].BottomWall = false;
				}

				break;
				
			default:
				throw std::invalid_argument( "O Valor para o lado fornecido é inválido!\n" );
				break;	

		} 
	}

	bool Maze::is_outside( size_t x, size_t y )
	{
		return x >= width or y >= height or x < 0 or y < 0;
	}

	bool Maze::is_path( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		return maze[ width * y + x ].Path;
	}

	bool Maze::is_visited( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		return maze[ width * y + x ].Visited;
	}

	bool Maze::has_top_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		return maze[ width * y + x ].TopWall;
	}

	bool Maze::has_bottom_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		return maze[ width * y + x ].BottomWall;
	}

	bool Maze::has_right_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		return maze[ width * y + x ].RightWall;
	}

	bool Maze::has_left_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		return maze[ width * y + x ].LeftWall;
	}

	bool Maze::has_walls( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		return maze[ width * y + x ].TopWall or maze[ width * y + x ].BottomWall or
		maze[ width * y + x ].RightWall or maze[ width * y + x ].LeftWall;
	}


	bool Maze::top_neighbor_has_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		if( is_outside( x, y - 1 ) )
		{
			throw std::invalid_argument( "A célula vizinha está fora do labirinto!\n" );
		}

		return maze[ width * ( y - 1 ) + x ].BottomWall;
	}

	bool Maze::bottom_neighbor_has_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		if( is_outside( x, y + 1 ) )
		{
			throw std::invalid_argument( "A célula vizinha está fora do labirinto!\n" );
		}

		return maze[ width * ( y + 1 ) + x ].TopWall;
	}

	bool Maze::left_neighbor_has_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		if( is_outside( x - 1, y ) )
		{
			throw std::invalid_argument( "A célula vizinha está fora do labirinto!\n" );
		}

		return maze[ width * y + ( x - 1 ) ].RightWall;
	}

	bool Maze::right_neighbor_has_wall( size_t x, size_t y )
	{
		if( is_outside( x, y ) )
		{
			throw std::invalid_argument( "Os Valores fornecidos para os eixos são inválidos!\n" );
		}

		if( is_outside( x + 1, y ) )
		{
			throw std::invalid_argument( "A célula vizinha está fora do labirinto!\n" );
		}

		return maze[ width * y + ( x + 1 ) ].LeftWall;
	}
}