#include <cstdlib>

#include "../include/magosgame.h"
#include "../include/maze.h"
#include "../include/canvas.h"

namespace mzr{


	MagosGame::Result_type MagosGame::initialize( int argc, char **argv )
	{
		MagosGame::Result_type result;


		size_t arg1, arg2, arg3, arg4;

		if( argc == 1 )
		{
			result.type = game_state_e::OK; 
		}
		else if( argc == 5 )
		{
			result.type = game_state_e::OK;
			arg1 = (size_t) atoi(argv[1]);
			arg2 = (size_t) atoi(argv[2]);
			arg3 = (size_t) atoi(argv[3]);
			arg4 = (size_t) atoi(argv[4]);

			canvas::Canvas c( arg3, arg4 );
			mzr::Maze m( arg1, arg2 );
			result.type = game_state_e::OK;	
		}
		else
		{
			result.type = game_state_e::ERROR;
			result.msg = "Argumentos por linha de comando fornecidos incorretamente.\nSe quiser mostrar o formato padrão não forneça argumentos, mas se quiser escolhê-los, faça da seguinte maneira:\n\n./magos [larg_maze] [alt_maze] [larg canvas] [alt canvas]\n\nQualquer fornecimento será considerado inválido.\n"; 
		}

		return result;
		
	}

	void MagosGame::welcome( void )
	{
		std::cout << "Bem-vindo ao Magos Game!!!\n";
	}
}