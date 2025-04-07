/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Sphere
*/

#pragma once
#include "IPrimitive.hpp"

namespace Primitive {
    class Sphere : public IPrimitive {
        public:
            Sphere(Math::Vector3D p, double r, RayTracer::Color c);
            ~Sphere();

            double hits(RayTracer::Ray &r);
            Math::Vector3D &getOrigin();
            RayTracer::Color &getColor();

            friend std::ostream &operator<<(std::ostream &os, const Sphere &s);
        private:
            Math::Vector3D _center;
            double _radius;
            RayTracer::Color _color;
    };
} // namespace Primitive
