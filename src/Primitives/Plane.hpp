/*
** EPITECH PROJECT, 2024
** Plane.hpp
** File description:
** Plane.hpp
*/

#pragma once
#include "../Math/Vector3D.hpp"
#include "../RayTracer/Color.hpp"
#include "../RayTracer/Ray.hpp"
#include "IPrimitive.hpp"

namespace Primitive
{
    class Plane : public IPrimitive {
        public:
            Plane();
            Plane(Math::Vector3D axis, double x, RayTracer::Color col);
            ~Plane();

            double hits(RayTracer::Ray &r);
            Math::Vector3D &getOrigin();
            RayTracer::Color &getColor();

        protected:
            Math::Vector3D _axis;
            double _height;
            RayTracer::Color _col;
    };
} // namespace Primitive
