#ifndef MAGOSGAME_H
#define MAGOSGAME_H

#include "../include/canvas.h"
#include "../include/render.h"
#include "../include/maze.h"

namespace mzr{

	class MagosGame{

		public:
			
			struct Result_type{
				size_t type;
				std::string msg;
			};

			enum game_state_e: size_t{
				OK = 0,
				ERROR = 1,
				BUILDING = 2,
				SOLVING = 3,
				DONE = 4
			};

			MagosGame() = default;
		    
			~MagosGame() = default;

			//Mostra uma apresentação na tela.
			void welcome( void );
			//Verifica se o jogo acabou.
			bool game_over( void );
			//Inicia o objeto MagosGame e retorna uma struct com o estado atual do jogo.
			Result_type initialize( int argc, char **argv );
			//O jogo não possui eventos.
			void process_events( void );
			//Necessita do builder.
			void update( void );
			//Desenha o labirinto na imagem.
			void render( void );


		private:
			
			canvas::Canvas *cv;
			mzr::Maze *mz;
			//Builder *bd;
			//Solver *sv;
	};
}


#endif