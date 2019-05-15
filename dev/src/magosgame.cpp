#include <cstdlib>
#include <iomanip>

#include "../include/magosgame.h"
#include "../include/maze.h"
#include "../include/canvas.h"
#include "../include/render.h"
#include "../include/builder.h"
#include <sstream>

namespace mzr{

	void MagosGame::welcome( void )
	{
		std::cout << "\n";
		std::cout << "$" << std::setw(50) << std::setfill('%') << "$" << "\n";
		std::cout << "$" << std::setw(50) << std::setfill('%') << "$" << "\n";
		std::cout << "$" << std::setw(13) << std::setfill(' ') << "" << "Bem-vindo ao Magos Game"
				  << std::setw(13) << std::setfill(' ') << "" << "$\n";
		std::cout << "$" << std::setw(50) << std::setfill('%') << "$" << "\n";
		std::cout << "$" << std::setw(50) << std::setfill('%') << "$" << "\n";
		std::cout << "\n";

		std::cout << "Gerando Maze...\n";
	}


	MagosGame& MagosGame::initialize( int argc, char **argv )
	{
		std::istringstream iss;
		size_t w_maze, h_maze;
		std::string value;

		if( argc == 1 )
		{
			w_maze = 5;
			h_maze = 7;
			width_img = 800;
			height_img = 600;
		}

		if( argc == 2 )
		{
			value = argv[1];
			iss.str(value);
			iss >> w_maze;
			iss.clear();

			h_maze = 15;
			width_img = 800;
			height_img = 600;
		}

		if( argc == 3 )
		{
			value = argv[1];
			iss.str(value);
			iss >> w_maze;
			iss.clear();

			value = argv[2];
			iss.str(value);
			iss >> h_maze;
			iss.clear();

			width_img = 800;
			height_img = 600;
		}

		if( argc == 4 )
		{
			value = argv[1];
			iss.str(value);
			iss >> w_maze;
			iss.clear();

			value = argv[2];
			iss.str(value);
			iss >> h_maze;
			iss.clear();

			value = argv[3];
			iss.str(value);
			iss >> width_img;
			iss.clear();

			height_img = 600;
		}

		if( argc == 5 )
		{
			value = argv[1];
			iss.str(value);
			iss >> w_maze;
			iss.clear();

			value = argv[2];
			iss.str(value);
			iss >> h_maze;
			iss.clear();

			value = argv[3];
			iss.str(value);
			iss >> width_img;
			iss.clear();

			value = argv[4];
			iss.str(value);
			iss >> height_img;
			iss.clear();
		}

		if( argc > 5 )
		{
			throw std::invalid_argument("Quantidade de argumentos de linha de comando inválida!\n");
		}

		//Criando um novo maze e adicionando-o ao campo privado. 
		Maze *m = new Maze( w_maze, h_maze );
		maze = m;

		if( ( maze->get_width() < 2 and maze->get_height() < 1 ) or 
			( maze->get_width() < 1 and maze->get_height() < 2 ) )
		{
			type = MagosGame::game_state_e::ERROR;
			msg = "Dimensões não funcionais de labirinto!\n";
		}

		//Criando um novo builder e adicionando-o ao campo privado.
		Builder *b = new Builder( maze );
		builder = b;

		builder->set_width( width_img );
		builder->set_height( height_img );

		Render r( maze, width_img, height_img );
		r.draw("building_0");

		return *this;
	}

	void MagosGame::process_events( void )
	{
		//Não tem eventos.
	}

	
	void MagosGame::update( void )
	{
		//Máquina de estado.
		if( builder->is_not_complete() )
		{
			type = game_state_e::BUILDING;
		
		}
		/*
		else if( solver->is_not_complete() )
		{
			type = game_state_e::SOLVING;
		}
		*/
		else
		{
			type = game_state_e::DONE;
		}
	}

	bool MagosGame::game_over( void )
	{
		return type == game_state_e::DONE;
	}

	void MagosGame::render( void )
	{
		
		builder->build();
	}
	
}