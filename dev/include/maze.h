/*! \file maze.h
	\author Noé Fernandes
	\date December, 12th
*/

#ifndef MAZE_H
#define MAZE_H

#include <cstring>
#include <iostream>

/*! Namespace que guarda os membros da classe Maze. */
namespace mzr{

	/*! Struct que avalia o estado da célula. */
	struct Cell{
		
		/*! Construtor */
		Cell() = default;
		/*! Destrutor */
		~Cell(){ /* empty */ }

		bool TopWall = true;
		bool BottomWall = true;
		bool LeftWall = true;
		bool RightWall = true;
		bool Path = false;
		bool Visited = false;
	};
	
	/*! Classe Maze: Responsável por manipular o estado do Maze. */
	class Maze{

		public:
			/*! Enumeração que representa os lados. */
			enum side: size_t{
				TopWall = 0,		
				BottomWall = 1,
				RightWall = 2,
				LeftWall = 3		
			};
			


			/*! Construtor. */
			Maze( size_t w, size_t h )
				: width{ w }, 
				height{ h }, 
				maze{ new Cell[ width * height ]}{ /* empty */ }
		
			/*! Destrutor. */
			~Maze()
			{
				delete[] maze;
			}
			

			/*! Construtor cópia. */
			Maze( const Maze & );

			/*! Operador de Atribuição. */
			Maze & operator=( const Maze & ); 

			/*! Retorna o numero de células do maze horizontalmente. */ 
			size_t get_width( void ){ return width; }
			/*! Retorna o numero de celulas do maze verticalmente. */
			size_t get_height( void ){ return height; }
			/*! Verifica se a coordena fornecida é válida. */
			bool is_outside( size_t x, size_t y );
			/*! Derruba uma parede fornecendo as coordenadas e a parede. */
			void knock_down( size_t x, size_t y, side v_side );
			/*! Verifica se a célula é caminho. */
			bool is_path( size_t x, size_t y );
			/*! Verifica se a célula é visitada. */
			bool is_visited( size_t x, size_t y );
			/*! Verifica se a célula tem parede em cima. */
			bool has_top_wall( size_t x, size_t y );
			/*! Verifica se a célula tem parede em baixo. */
			bool has_bottom_wall( size_t x, size_t y );
			/*! Verifica se a célula tem parede pela direita. */
			bool has_right_wall( size_t x, size_t y );
			/*! Verifica se a célula tem parede na esquerda. */
			bool has_left_wall( size_t x, size_t y );
			/*! Verifica se a célula tem paredes. */
			bool has_walls( size_t x, size_t y );
			/*! Verifica se a vizinha de cima compartilha parede com a célua atual. */
			bool top_neighbor_has_wall( size_t x, size_t y );
			/*! Verifica se a vizinha de baixo compartilha parede com a célua atual. */
			bool bottom_neighbor_has_wall( size_t x, size_t y );
			/*! Verifica se a vizinha da esquerda compartilha parede com a célua atual. */
			bool left_neighbor_has_wall( size_t x, size_t y );
			/*! Verifica se a vizinha da direita compartilha parede com a célua atual. */
			bool right_neighbor_has_wall( size_t x, size_t y );
			/*! Verifica se a vizinha de cima já foi visitada. */
			bool top_neighbor_is_visited( size_t x, size_t y );
			/*! Verifica se a vizinha de baixo já foi visitada. */
			bool bottom_neighbor_is_visited( size_t x, size_t y );
			/*! Verifica se a vizinha da esquerda já foi visitada. */
			bool left_neighbor_is_visited( size_t x, size_t y );
			/*! Verifica se a vizinha da direita já foi visitada. */
			bool right_neighbor_is_visited( size_t x, size_t y );
			/*! Transforma a entrada em coordenadas numa posição para o vetor de células. */
			size_t get_coord( size_t x, size_t y );



		private:
			/*! Número de células na horizontal. */
			size_t width;
			/*! Número de células na vertical. */
			size_t height;
			/*! Ponteiro para o vetor de células. */
			Cell *maze;
	};
}


#endif