/*! \file magosgame.h
	\author Noé Fernandes
	\date December, 12th
*/

#ifndef MAGOSGAME_H
#define MAGOSGAME_H

#include "../include/canvas.h"
#include "../include/render.h"
#include "../include/maze.h"
#include "../include/builder.h"

/*! Namespace que guarda os compontentes da classe MagosGame. */
namespace mzr{

	/*! Classe MagosGame: responsável por administrar o game loop e manipular as outras classes. */
	class MagosGame{

		public:
			/*! Enum que possui todos os estados possíveis para o jogo. */
			enum game_state_e: size_t{
				OK = 0,
				ERROR = 1,
				BUILDING = 2,
				SOLVING = 3,
				DONE = 4
			};

			/*! Possui o estágio atual do jogo. */ 
			size_t type;
			/*! Mensagem a ser mostrada. */
			std::string msg;

			/*! Destrutor */
			~MagosGame(){}

			/*! Mostra uma apresentação na tela. */
			void welcome( void );
			/*! Verifica se o jogo acabou. */
			bool game_over( void );
			/*! Inicia o objeto MagosGame e retorna com o estado atual do jogo. */
			MagosGame& initialize( int argc, char **argv );
			/*! O jogo não possui eventos. */
			void process_events( void );
			/*! Necessita do builder e do solver. */
			void update( void );
			/*! Desenha o maze em seu estado atual na imagem. */
			void render( void );
			/*! Retorna um ponteiro para o maze. */
			Maze get_maze( void ){ return *maze; }

			


		private:
			/*! Ponteiro para o maze. */
			Maze *maze;
			/*! Recebe a largura fornecida para a imagem. */
			size_t width_img;
			/*! Recebe a altura fornecida para a imagem. */ 
			size_t height_img;
			/*! Ponteiro para o builder. */
			Builder *builder;
			//Solver *solver;
	};
}


#endif