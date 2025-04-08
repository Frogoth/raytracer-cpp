/*
** EPITECH PROJECT, 2024
** Plane.hpp
** File description:
** Plane.hpp
*/

#pragma once
#include "../Math/Vector3D.hpp"
#include "../Math/Color.hpp"
#include "../RayTracer/Ray.hpp"
#include "IHittable.hpp"

namespace Hittable
{
    class Plane : public IHittable {
        public:
            Plane();
            Plane(Math::Vector3D axis, double x, Math::Color col);
            ~Plane();

            bool hits(const RayTracer::Ray &r, double rayTmin, double rayTmax, Math::Record3D &rec) const;

        protected:
            Math::Vector3D _axis;
            double _height;
            Math::Color _col;
    };
} // namespace Hittable
