#ifndef CAMERA_H
#define CAMERA_H

#include "./qbLinAlg/qbVector.h"
#include "ray.cpp"

namespace qbRT
{
    class Camera
    {
        public:
            Camera();

            void SetPosition(const qbVector<double> &newPosition);
            void SetLookAt(const qbVector<double> &newLookAt);
            void SetUp(const qbVector<double> &upVector);
            void SetLength(double newLength);
            void SetHorizontalSize(double horizontalSize);
            void SetAspect(double newAspect);

            //getter functions for camera parameters
            qbVector<double> GetPosition();
            qbVector<double> GetLookAt();
            qbVector<double> GetUp();
            qbVector<double> GetU();
            qbVector<double> GetV();
            qbVector<double> GetScreenCenter();
            double GetLength();
            double GetHorizontalSize();
            double GetAspect();

            //function to generate a ray
            Ray GenerateRay(float proScreenX, float proScreenY);
            
            //function to update camera geometry
            void UpdateCameraGeometry();

        private:
            qbVector<double> m_cameraPosition = qbVector<double>(3);
            qbVector<double> m_cameraLookAt = qbVector<double>(3);
            qbVector<double> m_cameraUp = qbVector<double>(3);
            double m_cameraLength;
            double m_cameraHorizontalSize;
            double m_cameraAspectRatio;

            qbVector<double> m_alignmentVector = qbVector<double>(3);
            qbVector<double> m_projectionScreenU = qbVector<double>(3);
            qbVector<double> m_projectionScreenV = qbVector<double>(3);
            qbVector<double> m_projectionScreenCenter = qbVector<double>(3);
    };
}

#endif