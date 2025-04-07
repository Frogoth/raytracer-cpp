/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-bsraytracer-tom.rudolf
** File description:
** Camera
*/

#include "Camera.hpp"

namespace RayTracer
{
    Camera::Camera() : _iPixelW(1), _iPixelH(1), _origin(Math::Point3D()), _fov(70), _rot(Math::Vector3D()) {}

    Camera::Camera(int imageWidth, int imageHeight, Math::Point3D ori, double fov, Math::Vector3D rot) {
        _iPixelW = imageWidth;
        _iPixelH = imageHeight;
        _origin = ori;
        _fov = fov;
        _rot = rot;
        setupCamera();
    }
    Camera::~Camera() {}

    double Camera::degrees_to_radians(double degrees) {
        const double pi = 3.1415926535897932385;
        return degrees * pi / 180.0;
    }

    Ray Camera::ray(double i, double j) {
        Math::Vector3D pixelCenter = _pixel00 + (i * _pixelDeltaU) + (j * _pixelDeltaV);
        Math::Vector3D rayDirection = pixelCenter - _origin;
        return RayTracer::Ray(_origin, rayDirection);
    }

    Color Camera::rayColor(Ray &r, primVec &pv) {
        for (const auto &primitive : pv) {
            auto t = primitive->hits(r);
            if (t > 0.0) {
                Math::Point3D tmp = r.pointAt(t) - Math::Point3D(0, 0, -1);
                Math::Point3D N = tmp.unitVector();
                return 0.5 * Color(N._x + 1, N._y + 1, N._z + 1);
            }
        }
        Math::Vector3D unitDirection = r.getDirection().unitVector();
        auto a = 0.5 * (unitDirection._y + 1.0);
        return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
    }

    void Camera::setupCamera() {
        _ratio = double(_iPixelW) / _iPixelH;
        _focalLength = 1.0;
        _viewH = 2.0;
        _viewW = _viewH * _ratio;
        _viewportU = Math::Vector3D(_viewW, 0, 0);
        _viewportV = Math::Vector3D(0, -_viewH, 0);
        _pixelDeltaU = _viewportU / _iPixelW;
        _pixelDeltaV = _viewportV / _iPixelH;
        _viewportUpperLeft = _origin - Math::Vector3D(0, 0, _focalLength) - _viewportU / 2 - _viewportV / 2;
        _pixel00 = _viewportUpperLeft + 0.5 * (_pixelDeltaU + _pixelDeltaV);
    }
} // namespace RayTracer
