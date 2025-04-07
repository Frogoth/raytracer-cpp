/*
** EPITECH PROJECT, 2024
** Cone.hpp
** File description:
** Cone.hpp
*/

#pragma once

#include "../Math/Vector3D.hpp"
#include "../RayTracer/Color.hpp"
#include "../RayTracer/Ray.hpp"

class Cone {
    public:
        Cone();
        Cone(Math::Vector3D xyz, double radius, double height);
        ~Cone();

        double _x;
        double _y;
        double _z;
        double _radius;
        double _height;
        double _base;
        double _top;

        RayTracer::Color _col;
        bool hits(RayTracer::Ray &r);
        Math::Vector3D _vect;
        Math::Vector3D _center;
    protected:
    private:
};
