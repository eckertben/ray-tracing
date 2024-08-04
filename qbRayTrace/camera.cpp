#include "camera.hpp"
#include "ray.hpp"
#include <math.h>

qbRT::Camera::Camera()
{
    m_cameraPosition = qbVector<double> {std::vector<double> {0.0, -10.0, 0.0}};
    m_cameraPosition = qbVector<double> {std::vector<double> {0.0, -0.0, 0.0}};
    m_cameraPosition = qbVector<double> {std::vector<double> {0.0, 0.0, 1.0}};
    m_cameraLength = 1.0;
    m_cameraHorizontalSize = 1.0;
    m_cameraAspectRatio = 1.0;
}

void qbRT::Camera::SetPosition(const qbVector<double> &newPosition)
{
    m_cameraPosition = newPosition;
}

void qbRT::Camera::SetLookAt(const qbVector<double> &newLookAt)
{
    m_cameraLookAt = newLookAt;
}

void qbRT::Camera::SetUp(const qbVector<double> &newUp)
{
    m_cameraUp = newUp;
}

void qbRT::Camera::SetLength(double newLength)
{
    m_cameraLength = newLength;
}

void qbRT::Camera::SetHorizontalSize(double newHorizontalSize)
{
    m_cameraHorizontalSize = newHorizontalSize;
}

void qbRT::Camera::SetAspect(double newAspect)
{
    m_cameraAspectRatio = newAspect;
}

//getter methods

qbVector<double> qbRT::Camera::GetPosition()
{
    return m_cameraPosition;
}

qbVector<double> qbRT::Camera::GetLookAt()
{
    return m_cameraLookAt;
}

qbVector<double> qbRT::Camera::GetUp()
{
    return m_cameraUp;
}

qbVector<double> qbRT::Camera::GetU()
{
    return  m_projectionScreenU;
}

qbVector<double> qbRT::Camera::GetV()
{
    return  m_projectionScreenV;
}

qbVector<double> qbRT::Camera::GetScreenCenter()
{
    return  m_projectionScreenCenter;
}

double qbRT::Camera::GetLength()
{
    return m_cameraLength;
}

double qbRT::Camera::GetHorizontalSize()
{
    return m_cameraHorizontalSize;
}

double qbRT::Camera::GetAspect()
{
    return m_cameraAspectRatio;
}

//function to compute camera geometry
void qbRT::Camera::UpdateCameraGeometry()
{
    //update position from camera to lookatpos
    m_alignmentVector = m_cameraLookAt - m_cameraPosition;
    m_alignmentVector.Normalize();

    //compute u and v vectors  
    m_projectionScreenU = qbVector<double>::cross(m_alignmentVector, m_cameraUp);
    m_projectionScreenU.Normalize();

    m_projectionScreenV = qbVector<double>::cross(m_alignmentVector, m_projectionScreenU);
    m_projectionScreenV.Normalize();

    //compute center point of the screen (vector pos)
    m_projectionScreenCenter = m_cameraPosition + (m_cameraLength * m_alignmentVector);

    //moify u and v to match the aspect ratio
    m_projectionScreenU = m_projectionScreenU * m_cameraHorizontalSize;
    m_projectionScreenV = m_projectionScreenV * (m_cameraHorizontalSize / m_cameraAspectRatio);
}

qbRT::Ray qbRT::Camera::GenerateRay(float proScreenX, float proScreenY)
{
    //compute location of screen point in world coords
    qbVector<double> screenWorldPart1 = m_projectionScreenCenter + (m_projectionScreenU * proScreenX);
    qbVector<double> screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);

    return qbRT::Ray(m_cameraPosition, screenWorldCoordinate);

}