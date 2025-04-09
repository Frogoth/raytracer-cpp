/*
** EPITECH PROJECT, 2024
** Plane.cpp
** File description:
** Plane
*/

#include <Hittable/Plane.hpp>

namespace Hittable
{
    Plane::Plane() {}
    Plane::~Plane() {}

    Plane::Plane(Math::Vector3D axis, double height, Math::Color col)
    {
        this->_axis = axis;
        _height = height;
        _col = col;
    }

    bool Plane::hits(const RayTracer::Ray &r, Math::Interval ray_t, Math::Record3D &rec) const {
        // if (r.getDirection().dot(this->_axis) == 0)
        //     return std::make_pair(0.0, 0.0);
        // else
        //     return std::make_pair(1.0, 1.0);
        return false;
    }

} // namespace Hittable
