/*
** EPITECH PROJECT, 2024
** Plane.hpp
** File description:
** Plane.hpp
*/

#pragma once

#include <Hittable/IHittable.hpp>

namespace Hittable
{
    class Plane : public IHittable {
        public:
            Plane();
            Plane(Math::Vector3D axis, double x, Math::Color col);
            ~Plane();

            bool hits(const RayTracer::Ray &r, Math::Interval ray_t, Math::Record3D &rec) const;

        protected:
            Math::Vector3D _axis;
            double _height;
            Math::Color _col;
    };
} // namespace Hittable
