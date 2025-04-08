/*
** EPITECH PROJECT, 2024
** Cylinder.cpp
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

Cylinder::Cylinder()
{
}

Cylinder::Cylinder(Math::Vector3D xyz, double radius)
{
    _x = xyz._x;
    _y = xyz._y;
    _z = xyz._z;
    _radius = radius;
    _base = xyz._z;
    _center = xyz;
}

bool Cylinder::hits(RayTracer::Ray &r)
{
    double A = std::pow(r.getDirection()._x, 2) + std::pow(r.getDirection()._y, 2);
    double B = 2 * ((r.getOrigin()._x - _center._x) * r.getDirection()._x + (r.getOrigin()._y
    - _center._y) * r.getDirection()._y);
    double C = std::pow(r.getOrigin()._x, 2) + std::pow(r.getOrigin()._y, 2) - _radius;

    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0)
        return (false);
    else
        return (true);
}

Cylinder::~Cylinder()
{
}
