/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-bsraytracer-tom.rudolf
** File description:
** Camera
*/

#include <RayTracer/Camera.hpp>

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

    Ray Camera::getRay(double i, double j) {
        Math::Point3D offset = sampleSquare();
        Math::Vector3D pixelSample = _pixel00 + ((i + offset._x) * _pixelDeltaU) + ((j + offset._y) * _pixelDeltaV);

        Math::Point3D rayOrigin = _origin;
        Math::Vector3D rayDirection = pixelSample - rayOrigin;
        return Ray(rayOrigin, rayDirection);
    }

    Math::Color Camera::rayColor(Ray &r, const Hittable::IHittable &world) {
        Math::Record3D rec;
        if (world.hits(r, Math::Interval(0, infinity), rec)) {
            Math::Vector3D direction = Math::Vector3D::randomOnHemisphere(rec.normal);
            Ray newRay(rec.p, direction);
            return 0.5 * rayColor(newRay, world);
        }

        Math::Vector3D unitDirection = r.getDirection().unitVector();
        auto a = 0.5 * (unitDirection._y + 1.0);
        Math::Color err = (1.0 - a) * Math::Color(1.0, 1.0, 1.0) + a * Math::Color(0.5, 0.7, 1.0);
        return err;
    }

    Math::Point3D Camera::sampleSquare() const {
        return Math::Point3D(randomDouble() - 0.5, randomDouble() - 0.5, 0);
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
        _samplesPerPixels = 50;
        _pixelSamplesScale = 1.0 / _samplesPerPixels;
    }
} // namespace RayTracer
