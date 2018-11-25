#include <iostream>
#include "../include/render.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

void Render::draw( const char *name_arq )
{
	canvas::Canvas c( width_render, height_render );

	size_t x = 0;
	size_t limite = 100;
	
	//Conta o valor máximo de x para que o labirinto não atravesse a imagem.
	while( (x * maze->get_width() < (width_render - limite)) and (x * maze->get_height() < (height_render - limite)) )
	{
		x++;
	}

	//Valores iniciais dos eixos.
	size_t eixox = ( width_render - maze->get_width() * x )/2;
	size_t eixoy = ( height_render - maze->get_height() * x)/2;

	//Plano de fundo.
	c.box( eixox, eixoy, x * maze->get_width(), x * maze->get_height(), canvas::DEEP_SKY_BLUE );

	//Guarda o ponto inicial no eixo x.
	size_t inicio_x = eixox;
	size_t inicio_y = eixoy;
	
	//Desenha as paredes do labirinto.
	for( size_t i = 0; i < maze->get_height(); i++ )
	{
		eixox = inicio_x;
		for( size_t j = 0; j < maze->get_width(); j++ )
		{
			if( maze->has_top_wall( j, i ) )
			{
				c.hline( eixox, eixoy, x, canvas::RED );
			}
			
			if( maze->has_left_wall( j, i ) )
			{
				c.vline( eixox, eixoy, x, canvas::RED );
			}

			eixox += x;
		}

		eixoy += x;
	}

	for( size_t i = 0; i < maze->get_height(); i++ )
	{
		if( maze->has_right_wall( maze->get_width() - 1, i ) )
		{
			c.vline( eixox, inicio_y, x, canvas::RED );
		}

		inicio_y += x;
	}

	for( size_t i = 0; i < maze->get_width(); i++ )
	{
		if( maze->has_bottom_wall( i, maze->get_height() - 1 ) )
		{
			c.hline( inicio_x, inicio_y, x, canvas::RED );
		}

		inicio_x += x;
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