/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Sphere
*/

#pragma once
#include "IHittable.hpp"

namespace Hittable {
    class Sphere : public IHittable {
        public:
            Sphere(Math::Vector3D p, double r, Math::Color c);
            ~Sphere();

            bool hits(const RayTracer::Ray &r, double rayTmin, double rayTmax, Math::Record3D &rec) const;

            friend std::ostream &operator<<(std::ostream &os, const Sphere &s);
        private:
            Math::Vector3D _center;
            double _radius;
            Math::Color _color;
    };
} // namespace Hittable
