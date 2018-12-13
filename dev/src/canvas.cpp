#include <stdexcept>
#include <iostream>
#include <cstring>

#include "../include/canvas.h"

namespace canvas {

    /*!
     * Deep copy of the canvas.
     * @param clone The object we are copying from.
     */
    Canvas::Canvas( const Canvas & clone )
    {
        // TODO
        m_width = clone.m_width;
        m_height = clone.m_height;
        m_line_thikness = clone.m_line_thikness;
        delete m_pixels;
        m_pixels = new unsigned char[clone.m_height * clone.m_width * 3];
        std::memmove( m_pixels, clone.m_pixels, ( clone.m_height * clone.m_width * 3 ));
    }


    /*!
     * @param source The object we are copying information from.
     * @return A reference to the `this` object.
     */
    Canvas& Canvas::operator=( const Canvas & source )
    {
        // TODO: incompleto

        
        delete m_pixels;
        m_pixels = new unsigned char[source.m_height * source.m_width * 3];
        std::memmove( m_pixels, source.m_pixels, ( source.m_height * source.m_width * 3 ) );
        m_width = source.m_width;
        m_height = source.m_height;
        m_line_thikness = source.m_line_thikness;

        return *this;

    }

    void Canvas::clear( const Color& color )
    {
        // TODO
        for( size_t i = 0; i < width(); i++ )
            for( size_t j = 0; j < height(); j++ )
                pixel(i, j, color);
    }

    /*!
     * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to know the color of.
     * @return The pixel color.
     */
    Color Canvas::pixel( coord_type x, coord_type y ) const
    {
        if( x >= width() or y >= height() )
        {
            throw std::invalid_argument("Valor fora da imagem!\n");
        }

        return Color( m_pixels[(y * width()*3 + (x*3)) + 0],
                      m_pixels[(y * width()*3 + (x*3)) + 1],
                      m_pixels[(y * width()*3 + (x*3)) + 2] 
                    );
    }

    /*!
     * @note Nothing is done if the  pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to change the color.
     * @param c The color.
     */
    void Canvas::pixel( coord_type x, coord_type y, const Color& c )
    {
        // TODO
        m_pixels[(y * width()*3 + (x*3)) + 0] = c.channels[0];
        m_pixels[(y * width()*3 + (x*3)) + 1] = c.channels[1];
        m_pixels[(y * width()*3 + (x*3)) + 2] = c.channels[2]; 

    }


    /*!
     * Draws on the canvas a horizontal line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The horizontal length of the line in pixels.
     */
    void Canvas::hline( coord_type x, coord_type y, size_t length, const Color& color )
    {
        // TODO
        for( size_t j = 0; j < thickness(); j++ )
        {
            for( size_t i = x; i < x + length; i++ )
            {
                pixel( i, y + j, color );
            }
        }
    }

    /*!
     * Draws on the canvas a vertical line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The vertical length of the line in pixels.
     */
    void Canvas::vline( coord_type x, coord_type y, size_t length, const Color& color )
    {
        // TODO
        for( size_t j = 0; j < thickness(); j++ )
        {
            for( size_t i = y; i < y + length; i++ )
            {
                pixel( x + j, i, color );
            }
        }
    }

    /*!
     * Draws on the canvas a filled box. The origin of the box is the top-left corner.
     * The box is compose of horizontal lines, drawn top to bottom.
     * @param p The 2D coordinate of the initial pixel of the box (top-left corner).
     * @param width The box's width in pixels.
     * @param height The box's heigth in pixels.
     */
    void Canvas::box( coord_type x, coord_type y, size_t width, size_t height , const Color& color)
    {
        // TODO
        for( size_t i = y; i < y + height - thickness() + 1; i++ )
        {
            hline( x, i, width, color );
        }
    }
}

//================================[ canvas.cpp ]================================//
