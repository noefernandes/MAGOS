#include <iostream>
#include "../include/render.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

void Render::draw( const char *name_arq )
{
	canvas::Canvas c( width_render, height_render );

	size_t limage = width_render - width_render*10/100;
	size_t aimage = height_render - height_render*10/100;
	size_t line;

	if( maze->get_height() >= maze->get_width() )
	{
		line = aimage/maze->get_height();
	}
	else
	{
		line = limage/maze->get_width();
	}

	while( line * maze->get_height() > aimage )
	{
		line--;
	}

	while( line * maze->get_width() > limage )
	{
		line--;
	}
	

	size_t inicio_x = ( width_render - line*maze->get_width() )/2;
	size_t inicio_y = ( height_render - line*maze->get_height() )/2;
	size_t eixox;
	size_t eixoy = inicio_y;

	c.box( inicio_x + line - line*90/100, inicio_y + line - line*90/100, 
			 line - 2*line*10/100, line - 2*line*10/100 , canvas::LIGHT_BLUE );


	for( size_t i = 0; i < maze->get_height(); i++ )
	{
		eixox = inicio_x;
		for( size_t j = 0; j < maze->get_width(); j++ )
		{
			if( maze->has_top_wall( j, i ) )
			{
				c.hline( eixox, eixoy, line, canvas::RED );
			}
			
			if( maze->has_left_wall( j, i ) )
			{
				c.vline( eixox, eixoy, line, canvas::RED );
			}

			eixox += line;
		}

		eixoy += line;
	}

	for( size_t i = 0; i < maze->get_height(); i++ )
	{
		if( maze->has_right_wall( maze->get_width() - 1, i ) )
		{
			c.vline( eixox, inicio_y, line, canvas::RED );
		}

		inicio_y += line;
	}

	for( size_t i = 0; i < maze->get_width(); i++ )
	{
		if( maze->has_bottom_wall( i, maze->get_height() - 1 ) )
		{
			c.hline( inicio_x, inicio_y, line, canvas::RED );
		}

		inicio_x += line;
	}
	

	

	
	//Cria a imagem png.
	auto wid = c.width();
    auto hei = c.height();
    auto pixels = c.buffer(); 
	
	stbi_write_png_compression_level = 0;    
    stbi_write_png( name_arq,      
                	wid, hei,        
               		3,                    
             		pixels,               
                	wid*3);    
}

