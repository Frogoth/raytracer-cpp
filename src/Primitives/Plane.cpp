/*
** EPITECH PROJECT, 2024
** Plane.cpp
** File description:
** Plane
*/

#include "Plane.hpp"

namespace Primitive
{
    Plane::Plane() {}
    Plane::~Plane() {}

    Plane::Plane(Math::Vector3D axis, double height, RayTracer::Color col)
    {
        this->_axis = axis;
        _height = height;
        _col = col;
    }

    double Plane::hits(RayTracer::Ray &r)
    {
        // if (r.getDirection().dot(this->_axis) == 0)
        //     return std::make_pair(0.0, 0.0);
        // else
        //     return std::make_pair(1.0, 1.0);
        return (0.0);
    }

    RayTracer::Color &Plane::getColor() {
        return _col;
    }

    Math::Vector3D &Plane::getOrigin() {
        return this->_axis;
    }

} // namespace Primitive
