#include "CApp.h"
#include <iostream>
#include "./qbRayTrace/qbLinAlg/qbVector.h"

//the constructor (default)

CApp::CApp()
{
    is_running = true;
    pWindow = NULL;
    pRenderer = NULL;
}

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    pWindow = SDL_CreateWindow("qbRayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

    if (pWindow != NULL) {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

        //initialize qbImage instance
        m_image.Initialize(1280, 720, pRenderer);

        qbRT::Camera testCamera;
        testCamera.SetPosition(qbVector<double>(std::vector<double>{0.0, 0.0, 0.0}));
        testCamera.SetLookAt(qbVector<double>(std::vector<double>{0.0, 2.0, 0.0}));
        testCamera.SetUp(qbVector<double>(std::vector<double>{0.0, 0.0, 1.0}));
        testCamera.SetLength(1.0);
        testCamera.SetHorizontalSize(1.0);
        testCamera.SetAspect(1.0);
        testCamera.UpdateCameraGeometry();

        //get screen center, u v vectors, display
        auto screenCenter = testCamera.GetScreenCenter();
        auto screenU = testCamera.GetU();
        auto screenV = testCamera.GetV();

        std::cout << "Camera Screen Center: " << std::endl;
        PrintVector(screenCenter);
        std::cout << "Camera U Vector: " << std::endl;
        PrintVector(screenU);
        std::cout << "Camera V Vector: " << std::endl;
        PrintVector(screenV);
    } else {
        return false;
    }
    return true;
}

int CApp::OnExecute()
{
    SDL_Event event;

    if (OnInit() == false) {
        return -1;
    }

    while (is_running) {
        while (SDL_PollEvent(&event) != 0) {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }
    return -1;
}

void CApp::OnEvent(SDL_Event *event)
{
    if (event->type == SDL_QUIT) {
        is_running = false;
    }
}

void CApp::OnLoop()
{

}

void CApp::OnRender()
{
    //sets the bg to white
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    //renders image
    m_scene.Render(m_image);

    // display image
    m_image.Display();

    //displays on screen
    SDL_RenderPresent(pRenderer);
}

void CApp::OnExit()
{
    //tidies up sdl things
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}

void CApp::PrintVector(const qbVector<double> &inputVector)
{
    int nRows = inputVector.GetNumDims();
    for (int row=0; row<nRows; row++) {
        std::cout << std::fixed << std::setprecision(3) << inputVector.GetElement(row) << std::endl;
    }
}