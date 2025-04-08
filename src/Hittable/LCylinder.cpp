/*
** EPITECH PROJECT, 2024
** Cylinder.cpp
** File description:
** Cylinder
*/

#include "LCylinder.hpp"

LCylinder::LCylinder()
{
}

LCylinder::LCylinder(Math::Vector3D xyz, double radius, double height)
{
    _x = xyz._x;
    _y = xyz._y;
    _z = xyz._z;
    _radius = radius;
    _base = xyz._z;
    _top = height + xyz._z;
    _height = height;
    _center = xyz;
}

bool LCylinder::hitsTop(RayTracer::Ray &r)
{
    double t = (_center._z + _height / r.getDirection()._z);

        if (t == 0)
            return (false);
        double x = r.getOrigin()._x + r.getDirection()._x * t;
        double y = r.getOrigin()._y + r.getDirection()._y * t;

        double disx = x - _center._x;
        double disy = y - _center._y;

        double sqdis =  std::pow(disx, 2) + std::pow(disy, 2);

        if (sqdis <= std::pow(_radius, 2))
            return (true);
        return false;
    }

bool LCylinder::hitsBase(RayTracer::Ray &r)
{
    double t = (_center._z / r.getDirection()._z);

        if (t == 0)
            return (false);
        double x = r.getOrigin()._x + r.getDirection()._x * t;
        double y = r.getOrigin()._y + r.getDirection()._y * t;

        double disx = x - _center._x;
        double disy = y - _center._y;

        double sqdis =  std::pow(disx, 2) + std::pow(disy, 2);

        if (sqdis <= std::pow(_radius, 2))
            return (true);
        return false;
    }

bool LCylinder::hits(RayTracer::Ray &r)
{
    double A = std::pow(r.getDirection()._x, 2) + std::pow(r.getDirection()._y, 2);
    double B = 2 * ((r.getOrigin()._x - _center._x) * r.getDirection()._x +( r.getOrigin()._y
    - _center._y)* r.getDirection()._y);
    double C = std::pow(r.getOrigin()._x - _center._x, 2) + std::pow(r.getOrigin()._y
     - _center._y, 2) - _radius;

        double discriminant = B * B - 4 * A * C;

        if (discriminant < 0)
            return (false);
        else {
            if (hitsBase(r) || hitsTop(r))
                return (true);
            double t1 = (-B - std::sqrt(discriminant)) / (2 * A);
            double t2 = (-B + std::sqrt(discriminant)) / (2 * A);
            if (_center._z <= r.getOrigin()._z + r.getDirection()._z
            * t1 <= _center._z + _height
            || _center._z <= r.getOrigin()._z + r.getDirection()._z
            * t2 <= _center._z + _height)
                return (true);
            return (false);
        }
    }

LCylinder::~LCylinder()
{
}
