#include "../include/builder.h"
#include "../include/maze.h"
#include "../include/render.h"
#include <cstring>
#include <sstream>

void Builder::to_see( void )
{
	for( size_t i = 0; i < maze->get_width()*maze->get_height(); i++ )
	{

		if( i % maze->get_width() == 0 and i != 0)
		{
			std::cout << "\n";
		}

		std::cout << matrix[i] << " ";
	}

	std::cout << "\n\n";
}



size_t Builder::generate_random( size_t inicio, size_t fim )
{
	unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());
	std::mt19937 mt(seed);
	std::uniform_int_distribution<int> linear_i(inicio, fim);
	size_t value = linear_i(mt);

	return value;
}

bool Builder::is_not_complete( void )
{
	for(size_t i = 0; i < matrix.size(); i++)
	{
		if( matrix[i] != 0 )
		{
			return true;
		}
	}

	return false;
}

void Builder::set_equal_number( size_t _old, size_t _new )
{
	for( size_t i = 0; i < maze->get_width()*maze->get_height(); i++ )
	{
		if( matrix[i] == _old )
		{
			matrix[i] = _new;
		}
	}
}

void Builder::build( void )
{

	// Versão tentada 1.
	Render r( maze, b_width, b_height );
	std::string temp;
	char msg[20];
	const char *num;

	if( is_not_complete() )
	{
		size_t randomwall = rand()%4;
		size_t x = generate_random( 0, maze->get_width() - 1 );
		size_t y = generate_random( 0, maze->get_height() - 1 );
		
		if( randomwall == Maze::side::TopWall and y > 0 and
		 matrix[maze->get_coord(x,y)] != matrix[maze->get_coord(x, y-1)]) 
		{
			maze->knock_down( x, y, Maze::side::TopWall );

			set_equal_number( std::max( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x,y-1)]),
							  std::min( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x,y-1)]));

			std::istringstream iss(std::to_string(cont_img));
			strcpy( msg, "building_");
			iss >> temp;
			const char *num = temp.c_str();

			strcat( msg, num );

			r.draw( msg );

			iss.clear();
			cont_img++;
			
		}

		if( randomwall == Maze::side::BottomWall and y < maze->get_height() - 1 and
		matrix[maze->get_coord(x,y)] != matrix[maze->get_coord(x, y+1)])
		{
			maze->knock_down( x, y, Maze::side::BottomWall );
			
			set_equal_number( std::max( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x,y+1)]),
							  std::min( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x,y+1)]));

			std::istringstream iss(std::to_string(cont_img));
			strcpy( msg, "building_");
			iss >> temp;
			num = temp.c_str();

			strcat( msg, num );

			r.draw( msg );

			iss.clear();
			cont_img++;
		}

		if( randomwall == Maze::side::LeftWall and x > 0 and
		matrix[maze->get_coord(x,y)] != matrix[maze->get_coord(x-1, y)])
		{
			maze->knock_down( x, y, Maze::side::LeftWall );
			
			set_equal_number( std::max( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x-1,y)]),
							  std::min( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x-1,y)]));

			std::istringstream iss(std::to_string(cont_img));
			strcpy( msg, "building_");
			iss >> temp;
			num = temp.c_str();

			strcat( msg, num );

			r.draw( msg );

			iss.clear();
			cont_img++;


		}

		if( randomwall == Maze::side::RightWall and x < maze->get_width() - 1 and
		matrix[maze->get_coord(x,y)] != matrix[maze->get_coord(x+1, y)])
		{
			maze->knock_down( x, y, Maze::side::RightWall );

			set_equal_number( std::max( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x+1,y)]),
							  std::min( matrix[maze->get_coord(x,y)], matrix[maze->get_coord(x+1,y)]));

			std::istringstream iss(std::to_string(cont_img));
			strcpy( msg, "building_");
			iss >> temp;
			num = temp.c_str();

			strcat( msg, num );

			r.draw( msg );

			iss.clear();
			cont_img++;
		}
				
	} 
}
