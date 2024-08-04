#ifndef CAPP_H
#define CAPP_H

#include "SDL2/SDL.h"
#include "./qbRayTrace/qbImage.cpp"
#include "./qbRayTrace/scene.cpp"
#include "./qbRayTrace/camera.cpp"

class CApp {
    public:
        CApp();

        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event *event);
        void OnLoop();
        void OnRender();
        void OnExit();

    private:
        //instance of  qbImage class
        qbImage m_image;

        //instance of scene class
        qbRT::Scene m_scene;

        // SDL2 stuff
        bool is_running;
        SDL_Window *pWindow;
        SDL_Renderer *pRenderer;
    
    private:
        void PrintVector(const qbVector<double> &inputVector);
};

#endif