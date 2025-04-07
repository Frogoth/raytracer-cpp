/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Sphere
*/

#include "Sphere.hpp"

namespace Primitive
{
    Sphere::Sphere(Math::Vector3D p, double r, RayTracer::Color col) : _center(p), _radius(r), _color(col) {}
    Sphere::~Sphere() {}

    double Sphere::hits(RayTracer::Ray &r) {
        Math::Vector3D oc = r.getOrigin() - _center;

        double a = r.getDirection().lengthSquared();
        double h = r.getDirection().dot(oc);
        double c = oc.lengthSquared() - _radius * _radius;
        double discriminant = h * h - a * c;

        if (discriminant < 0)
            return -1.0;
        return (h - std::sqrt(discriminant)) / a;
    }

    Math::Vector3D &Sphere::getOrigin() {
        return _center;
    }

    RayTracer::Color &Sphere::getColor() {
        return _color;
    }

    std::ostream &operator<<(std::ostream &os, const Sphere &s) {
        os << "sphere center:" << std::endl << s._center << std::endl << "sphere radius: " << std::endl << s._radius;
        return os;
    }
} // namespace Primitive
