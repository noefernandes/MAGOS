#ifndef MAGOSGAME_H
#define MAGOSGAME_H

#include "../include/canvas.h"
#include "../include/render.h"
#include "../include/maze.h"

namespace mzr{

	class MagosGame{

		public:

			enum game_state_e: size_t{
				OK = 0,
				ERROR = 1,
				BUILDING = 2,
				SOLVING = 3,
				DONE = 4
			};

			//Mostra o estágio atual do objeto. 
			size_t type;
			//Mensagem a ser mostrada.
			std::string msg;

			~MagosGame(){}

			//Mostra uma apresentação na tela.
			void welcome( void );
			
			//Verifica se o jogo acabou.
			bool game_over( void );
			//Inicia o objeto MagosGame e retorna uma struct com o estado atual do jogo.
			MagosGame& initialize( int argc, char **argv );
			//O jogo não possui eventos.
			void process_events( void );
			//Necessita do builder.
			void update( void );
			//Desenha o labirinto na imagem.
			void render( void );

			Maze get_maze( void ){ return *maze; }

			


		private:
			
			Maze *maze;
			size_t width_img;
			size_t height_img;
			//Builder *builder;
	};
}


#endif