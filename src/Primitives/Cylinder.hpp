/*
** EPITECH PROJECT, 2024
** Cylinder.hpp
** File description:
** Cylinder.hpp
*/

#pragma once

#include "../Math/Vector3D.hpp"
#include "../RayTracer/Ray.hpp"
#include "../RayTracer/Color.hpp"
#include <cmath>

class Cylinder {
    public:
        Cylinder();
        Cylinder(Math::Vector3D xyz, double radius);
        ~Cylinder();

        double _x;
        double _y;
        double _z;
        double _radius;
        double _base;
        double _top;
        double _height;

        RayTracer::Color _col;
        bool hitsTop(RayTracer::Ray &r);
        bool hitsBase(RayTracer::Ray &r);
        bool hits (RayTracer::Ray &r);
        Math::Vector3D _vect;
        Math::Vector3D _center;
    protected:
    private:
};
