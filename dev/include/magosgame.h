#ifndef MAGOSGAME_H
#define MAGOSGAME_H

#include "/include/render.h"

namespace mzr{

	class MagosGame{

		public:
			
			struct Result_type{
				size_t type;
				char *msg;
			}

			enum game_state_e{
				size_t OK = 0;
				size_t ERROR = 1;
				size_t BUILDING = 2;
				size_t SOLVING = 3;
			}

			MagosGame( Maze *m /*, Builder *b, Solver *s*/ )
				: mz( m ) /*, bd( b ), sv( s ) */;
			
			~MagosGame();

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
			
			Maze *mz;
			//Builder *bd;
			//Solver *sv;
	}
}


#endif