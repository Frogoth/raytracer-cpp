/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Sphere
*/

#include "Sphere.hpp"

namespace Hittable
{
    Sphere::Sphere(Math::Vector3D p, double r, Math::Color col) : _center(p), _radius(r), _color(col) {}
    Sphere::~Sphere() {}

    bool Sphere::hits(const RayTracer::Ray &r, Math::Interval ray_t, Math::Record3D &rec) const {
        Math::Vector3D oc = r.getOrigin() - _center;

        double a = r.getDirection().lengthSquared();
        double h = r.getDirection().dot(oc);
        double c = oc.lengthSquared() - _radius * _radius;
        double discriminant = h * h - a * c;

        if (discriminant < 0)
            return false;
        auto sqrt = std::sqrt(discriminant);

        auto root = (h - sqrt) / a;
        if (!ray_t.surrounds(root)) {
            root = (h + sqrt) / a;
            if (!ray_t.surrounds(root))
                return false;
        }
        rec.t = root;
        rec.p = r.pointAt(rec.t);
        Math::Vector3D outwardNormal = (rec.p - _center) / _radius;
        rec.setFaceNormal(r, outwardNormal);

        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Sphere &s) {
        os << "sphere center:" << std::endl << s._center << std::endl << "sphere radius: " << std::endl << s._radius;
        return os;
    }
} // namespace Hittable
