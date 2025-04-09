/*
** EPITECH PROJECT../Math, 2024
** OOP
** File description:
** Ray
*/

#pragma once

#include <Math/Vector3D.hpp>
#include <main.hpp>

namespace RayTracer
{
    class Ray {
        public:
            Ray();
            Ray(const Math::Point3D p, const Math::Vector3D v);
            ~Ray();
            Ray(Ray &&other);
            Ray(const Ray &other);

            const Math::Point3D &getOrigin() const;
            const Math::Vector3D &getDirection() const;

            Math::Point3D pointAt(double t) const;

            Ray &operator=(Ray &&other);
            Ray operator=(const Ray &other);
        private:
            Math::Point3D _origin;
            Math::Vector3D _direction;
    };
} // namespace RayTracer
