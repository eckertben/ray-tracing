#ifndef QBIMAGE_H
#define QBIMAGE_H

#include <string>
#include <vector>
#include <iostream>
#include "SDL2/SDL.h"

class qbImage
{
    public:
        //constructor
        qbImage();

        //destructor
        ~qbImage();

        //function initialized
        void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);

        //function to set pixel colors
        void SetPixel(const int x, const int y, const double red, const double green, const double blue);

        //function to return image
        void Display();

        //getter functions for x and y size
        int GetXSize();
        int GetYSize();
    
    private:
        Uint32 ConvertColor(const double red, const double green, const double blue);
        void InitTexture();

    private:
        //arrays to store image data
        std::vector<std::vector<double>> m_rChannel;
        std::vector<std::vector<double>> m_gChannel;
        std::vector<std::vector<double>> m_bChannel;

        //dim of image
        int m_xSize, m_ySize;

        SDL_Renderer *m_pRenderer;
        SDL_Texture *m_pTexture;
};

#endif