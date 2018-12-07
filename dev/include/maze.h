#ifndef MAZE_H
#define MAZE_H

#include <cstring>
#include <iostream>

namespace mzr{

	//Struct que avalia o estado da célula.
	struct Cell{
		
		Cell() = default;
		~Cell(){ /* empty */ }

		bool TopWall = true;
		bool BottomWall = true;
		bool LeftWall = true;
		bool RightWall = true;
		bool Path = false;
		bool Visited = false;
	};
	
	class Maze{

		public:
			//Enumeração que representa os lados.
			enum side: size_t{
				TopWall = 0,
				BottomWall = 1,
				RightWall = 2,
				LeftWall = 3
			};


			//Construtor
			Maze( size_t w = 20, size_t h = 20 )
				: width{ w }, 
				height{ h }, 
				maze{ new Cell[ width * height ]}{ /* empty */ }
		
			//Destrutor
			~Maze()
			{
				delete[] maze;
			}

			//Construtor cópia
			Maze( const Maze & );

			//Atribuição
			Maze & operator=( const Maze & ); 

			//Métodos
			size_t get_width( void ){ return width; }
			size_t get_height( void ){ return height; }
			bool is_outside( size_t x, size_t y );
			void knock_down( size_t x, size_t y, side v_side );
			bool is_out( size_t x, size_t y );
			bool is_path( size_t x, size_t y );
			bool is_visited( size_t x, size_t y );
			bool has_top_wall( size_t x, size_t y );
			bool has_bottom_wall( size_t x, size_t y );
			bool has_right_wall( size_t x, size_t y );
			bool has_left_wall( size_t x, size_t y );
			bool has_walls( size_t x, size_t y );
			bool top_neighbor_has_wall( size_t x, size_t y );
			bool bottom_neighbor_has_wall( size_t x, size_t y );
			bool left_neighbor_has_wall( size_t x, size_t y );
			bool right_neighbor_has_wall( size_t x, size_t y );



		private:
			size_t width;
			size_t height;
			Cell *maze;
	};
}


#endif