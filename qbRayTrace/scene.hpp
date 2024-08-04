#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "SDL2/SDL.h"
#include "qbImage.hpp"

namespace qbRT
{
    class Scene
    {
        public:
            //default constructior
            Scene();

            //function for rendering
            bool Render(qbImage &outputImage);
    };

    class test
    {
        public:
            void whatsUp();
    };
};

#endif