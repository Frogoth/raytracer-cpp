/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-bsraytracer-tom.rudolf
** File description:
** Camera
*/

#pragma once

#include <Hittable/IHittable.hpp>

using primVec = std::vector<std::shared_ptr<Hittable::IHittable>>;

namespace RayTracer
{
    class Camera {
        public:
            Camera();
            Camera(int x, int y, Math::Point3D ori, double fov, Math::Vector3D rot);
            ~Camera();

        int _iPixelW;
        int _iPixelH;
        Math::Point3D _pixel00;
        Math::Point3D _origin;
        Math::Vector3D _viewportU;
        Math::Vector3D _viewportV;

        Ray getRay(double i, double j);
        Math::Color rayColor(Ray &r, const Hittable::IHittable &world);
        Math::Point3D sampleSquare() const;

        double _ratio;
        double _focalLength;
        double _fov;
        double _viewH;
        double _viewW;
        Math::Vector3D _rot;
        Math::Vector3D _pixelDeltaU;
        Math::Vector3D _pixelDeltaV;
        Math::Point3D _viewportUpperLeft;
        int _samplesPerPixels;
        double _pixelSamplesScale;
        void setupCamera();
    };
} // namespace RayTracer
