#include "scene.hpp"
#include <iostream>

//constructor
qbRT::Scene::Scene()
{

}

bool qbRT::Scene::Render(qbImage &outputImage) 
{
    //dimensions of outputted image
    int xSize = outputImage.GetXSize();
    int ySize = outputImage.GetYSize();

    //color variations
    for (int x=0; x<xSize; x++) {
        double red = (static_cast<double>(x)/1280.0) * 255.0;
        for (int y=0; y<ySize; y++) {
            double green = (static_cast<double>(y)/720.0) * 255.0;
            outputImage.SetPixel(x, y, red, green, 0.0);
        }
    }
    return true;
}