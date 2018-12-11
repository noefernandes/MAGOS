/*!
 *  This is the program entry, that  manages the game loop (programming pattern).
 *
 *  @author Selan R. dos Santos
 *
 */
#include <cstdlib> // EXIT_SUCCESS
#include <iostream> // cerr

#include "../include/magosgame.h"

int main( int argc, char *argv[] )
{
    mzr::MagosGame mg;

    mg.welcome();

    auto result = mg.initialize( argc, argv );
    if ( result.type == mzr::MagosGame::game_state_e::ERROR )
    {
        std::cerr << result.msg << "\n";
        return EXIT_FAILURE;
    }

    // The Game Loop.
    
    int i = 0;
    while( /*not mg.game_over()*/ i < 1 )
    {
        mg.process_events();
        mg.update();
        mg.render();
        i++;
    }


    return EXIT_SUCCESS;
}
