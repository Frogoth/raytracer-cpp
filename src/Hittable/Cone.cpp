/*
** EPITECH PROJECT, 2024
** Cone.cpp
** File description:
** Cone.cpp
*/

#include <Hittable/Cone.hpp>

Cone::Cone()
{
}

Cone::Cone(Math::Vector3D xyz, double radius, double height)
{
    _x = xyz._x;
    _y = xyz._y;
    _z = xyz._z;
    _radius = radius;
    _base = xyz._z;
    _center = xyz;
    _height = height;
}

bool Cone::hits(RayTracer::Ray &r)
{
    double jim = _radius / _height;
    double A = std::pow(r.getDirection()._x, 2) + std::pow(r.getDirection()._y , 2)
    - std::pow(r.getDirection()._z , 2) * jim;

    double B = 2 * ((r.getOrigin()._x - _center._x) * r.getDirection()._x + (r.getOrigin()._y
    - _center._y) * r.getDirection()._y - (r.getOrigin()._z - _center._z) * r.getDirection()._z * jim);

    double C = std::pow(r.getOrigin()._x, 2) + std::pow(r.getOrigin()._y, 2)
    - std::pow(r.getOrigin()._z, 2) * jim;

    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0)
        return (false);
    else
        return (true);
}

Cone::~Cone()
{
}
