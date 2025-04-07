/*
** EPITECH PROJECT../Math, 2024
** OOP
** File description:
** Ray
*/

#pragma once
#include "../Math/Vector3D.hpp"
#include "../../main.hpp"

namespace RayTracer
{
    class Ray {
        public:
            Ray();
            Ray(Math::Point3D p, Math::Vector3D v);
            ~Ray();
            Ray(Ray &&other);
            Ray(const Ray &other);

            Math::Point3D &getOrigin();
            Math::Vector3D &getDirection();

            Math::Point3D pointAt(double t);

            Ray &operator=(Ray &&other);
            Ray operator=(const Ray &other);
            friend std::ostream &operator<<(std::ostream &os, const Ray &r);
        private:
            Math::Point3D _origin;
            Math::Vector3D _direction;
    };
} // namespace RayTracer
